#!/usr/bin/python
# encoding=utf-8

from flask import Flask, request, make_response, render_template
import hashlib
from wechat_sdk import WechatBasic
from wechat_sdk.messages import *

app = Flask(__name__)


@app.route('/', methods=['GET', 'POST'])
def wechat_auth():
	TOKEN = 'yipaiyaokong' # your toke
	query = request.args   # GET方法附上的参数
	signature = query.get('signature', '')
	timestamp = query.get('timestamp', '')
	nonce = query.get('nonce', '')
	echostr = query.get('echostr', '')

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
			if isinstance(wechat.message, TextMessage):
				if wechat.message.type == 'text':
					if wechat.message.content.lower() == 'app':
						response = wechat.response_news(
						[
							{
								'title': u'一拍遥控',
								'description': u'属于您自己的遥控器',
								'url': 'weixin.yipaiyaokong.com/ypyk-web/wechat/index.html'
							}	
						]
	
						)
					else:
						response = wechat.response_text('你好')
			elif isinstance(wechat.message, ImageMessage):
				picurl = wechat.message.picurl
				media_id = wechat.message.media_id
				response = wechat.response_text(picurl + '>>>' + media_id)
		return make_response(response.encode('utf-8'))


@app.route('/index.html/')
def hello():
	return render_template('index.html')

if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True)
