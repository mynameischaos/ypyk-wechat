#!/usr/bin/python
# encoding=utf-8

from flask import Flask, request, make_response, render_template
import hashlib
from wechat_sdk import WechatBasic
from wechat_sdk.messages import *
from event_process import EventProcess
from tool import download_picture
import sys

app = Flask(__name__)



@app.route('/', methods=['GET', 'POST'])
def wechat_auth():
	TOKEN = 'yipaiyaokong' # your toke
	query = request.args   # GET方法附上的参数
	signature = query.get('signature', '')
	timestamp = query.get('timestamp', '')
	nonce = query.get('nonce', '')
	echostr = query.get('echostr', '')
	sys.path.append('tool')

	if request.method == 'GET':
		s = [timestamp, nonce, TOKEN]
		s.sort()
		s = ''.join(s)
		if(hashlib.sha1(s).hexdigest() == signature):
			return make_response(echostr)
	else:
		# 解析数据;回复消息
		body_text = request.data
		wechat = WechatBasic(token=TOKEN)
		response = None
		if wechat.check_signature(signature=signature,timestamp=timestamp, nonce=nonce):
			wechat.parse_data(body_text)
			message = wechat.get_message()
			# 消息内容为文本
			if isinstance(message, TextMessage):
				response = wechat.response_text(message)
			# 消息内容为图片
			elif isinstance(message, ImageMessage):
				picurl = message.picurl
				media_id = message.media_id
				download_picture.get(picurl)		
				response = wechat.response_text('上传成功！')
			# 消息内容为事件
			elif isinstance(message, EventMessage):
				if message.type == 'click':
					ep = EventProcess()
					content = ep.click_event(message.key)
				#if message.type == 'click':
				#	if message.key == 'television':
				#		content = '请输入TV类型'
				response = wechat.response_text(content)

		return make_response(response.encode('utf-8'))


@app.route('/index.html/')
def hello():
	return render_template('index.html')

if __name__ == '__main__':
	app.run(host='0.0.0.0', debug=True)
