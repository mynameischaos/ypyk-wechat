#!/usr/bin/python
# encoding=utf-8

from flask import Flask, request, make_response, render_template, url_for
import hashlib
from wechat_sdk import WechatBasic
from wechat_sdk.messages import *
from event_process import EventProcess
from msg_process import MsgProcess
from tool import download_picture
from tool import get_wavFile
import sys
from wechat_sdk import WechatConf


app = Flask(__name__)



@app.route('/', methods=['GET', 'POST'])
def wechat_auth():
	reload(sys)
	sys.setdefaultencoding('utf8')
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
		# 创建一个wechat对象
		wechat = WechatBasic(token=TOKEN)
		response = None
		if wechat.check_signature(signature=signature,timestamp=timestamp, nonce=nonce):
			wechat.parse_data(body_text)
			message = wechat.get_message()
			# 消息内容为文本
			if isinstance(message, TextMessage):
				mp = MsgProcess()
				response = mp.msg_process(message, wechat)
			# 消息内容为图片
			elif isinstance(message, ImageMessage):
				picurl = message.picurl
				#media_id = message.media_id
				download_picture.get(picurl)		
				response = wechat.response_text('上传成功！')
			# 消息内容为事件
			elif isinstance(message, EventMessage):
				ep = EventProcess()
				content = ep.click_event(message)
				response = wechat.response_text(content)

		return make_response(response.encode('utf-8'))


@app.route('/index.html/')
def return_index():
	btnName_pos = get_wavFile.create_wavFile('TV', 'xiaomi', '小米电视')
	power_wav = url_for('static', filename=get_wavFile.find_pos('POWER', btnName_pos))
	up_wav = url_for('static', filename=get_wavFile.find_pos('UP', btnName_pos))
	down_wav = url_for('static', filename=get_wavFile.find_pos('DOWN', btnName_pos))
	left_wav = url_for('static', filename=get_wavFile.find_pos('LEFT', btnName_pos))
	right_wav = url_for('static', filename=get_wavFile.find_pos('RIGHT', btnName_pos))
	home_wav = url_for('static', filename=get_wavFile.find_pos('HOME', btnName_pos))
	return render_template('index.html',
						 power_wav=power_wav,
						 up_wav=up_wav,
						 down_wav=down_wav,
						 left_wav=left_wav,
						 home_wav=home_wav,
						 right_wav=right_wav)

if __name__ == '__main__':
	app.run(host='0.0.0.0', debug=True)
