#!/usr/bin/python
# encoding=utf-8

from flask import Flask, request, make_response, render_template, url_for
import hashlib
from wechat_sdk import WechatBasic
from wechat_sdk.messages import *
from event_process import EventProcess
from msg_process import MsgProcess
<<<<<<< HEAD
from img_process import ImgProcess
from tool import download_picture
from tool import get_wavFile
import sys
sys.path.append('tool')
sys.path.append('python_db')
=======
from tool import download_picture
from tool import get_wavFile
import sys
>>>>>>> 48f33b10e0460d1b1213af2c3d17ecd3f84e0ac5
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
<<<<<<< HEAD
	#sys.path.append('tool')
        #sys.path.append('python_db')
=======
	sys.path.append('tool')
>>>>>>> 48f33b10e0460d1b1213af2c3d17ecd3f84e0ac5

	
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
<<<<<<< HEAD
                            ip = ImgProcess()
                            content = ip.check_picture(message)
                            response = wechat.response_text(content)
			# 消息内容为事件
			elif isinstance(message, EventMessage):
				ep = EventProcess()
				state, response = ep.click_event(message)
				if response == '获取地理信息':
					return 
                                if state == 'news':
                                    response = wechat.response_news(response)
                                elif state == 'text':
                                    response = wechat.response_text(response)
=======
				picurl = message.picurl
				#media_id = message.media_id
				download_picture.get(picurl)		
				response = wechat.response_text('上传成功！')
			# 消息内容为事件
			elif isinstance(message, EventMessage):
				ep = EventProcess()
				content = ep.click_event(message)
				if content == '获取地理信息':
					return 
				response = wechat.response_text(content)
>>>>>>> 48f33b10e0460d1b1213af2c3d17ecd3f84e0ac5
		return make_response(response.encode('utf-8'))


@app.route('/index.html/', methods=['GET', 'POST'])
def return_index():
<<<<<<< HEAD
    if request.method == 'GET':
	query = request.args
	if query != None:
	    Type = query.get('type', '').encode('UTF-8')
            brand = query.get('brand', '').encode('UTF-8')
            model = query.get('model', '').encode('UTF-8')
            btnName_pos = get_wavFile.create_wavFile(str(Type), str(brand), str(model))
            power_wav = url_for('static', filename=get_wavFile.find_pos('POWER', btnName_pos))
            up_wav = url_for('static', filename=get_wavFile.find_pos('UP', btnName_pos))
            down_wav = url_for('static', filename=get_wavFile.find_pos('DOWN', btnName_pos))
            left_wav = url_for('static', filename=get_wavFile.find_pos('LEFT', btnName_pos))
            right_wav = url_for('static', filename=get_wavFile.find_pos('RIGHT', btnName_pos))
            #home_wav = url_for('static', filename=get_wavFile.find_pos('HOME', btnName_pos))
            ok_wav = url_for('static', filename=get_wavFile.find_pos('OK', btnName_pos))
            menu_wav = url_for('static', filename=get_wavFile.find_pos('MENU', btnName_pos))
            return render_template('index.html',
                                                     power_wav=power_wav,
                                                     up_wav=up_wav,
                                                     down_wav=down_wav,
                                                     left_wav=left_wav,
                       #                              home_wav=home_wav,
                                                     right_wav=right_wav,
                                                     ok_wav=ok_wav,
                                                     menu_wav=menu_wav)
        else:
            return 'www.yipaiyaokong.com'

@app.route('/test.html/')
def test():
    return 'hello'

if __name__ == '__main__':
	app.run(host='0.0.0.0', debug=True, port=81)
=======
	# 获取请求参数
	query = request.args
	if query != None:
		type = query.get('type', '')
		brand = query.get('brand', '')
		model = query.get('model', '')

		btnName_pos = get_wavFile.create_wavFile(type, brand, model)
		power_wav = url_for('static', filename=get_wavFile.find_pos('POWER', btnName_pos))
		up_wav = url_for('static', filename=get_wavFile.find_pos('UP', btnName_pos))
		down_wav = url_for('static', filename=get_wavFile.find_pos('DOWN', btnName_pos))
		left_wav = url_for('static', filename=get_wavFile.find_pos('LEFT', btnName_pos))
		right_wav = url_for('static', filename=get_wavFile.find_pos('RIGHT', btnName_pos))
		home_wav = url_for('static', filename=get_wavFile.find_pos('HOME', btnName_pos))
		ok_wav = url_for('static', filename=get_wavFile.find_pos('OK', btnName_pos))
		menu_wav = url_for('static', filename=get_wavFile.find_pos('MENU', btnName_pos))
		return render_template('index.html',
							 power_wav=power_wav,
							 up_wav=up_wav,
							 down_wav=down_wav,
							 left_wav=left_wav,
							 home_wav=home_wav,
							 right_wav=right_wav,
							 ok_wav=ok_wav,
							 menu_wav=menu_wav)
	else:
		return 'www.yipaiyaokong.com'

if __name__ == '__main__':
	app.run(host='0.0.0.0', debug=True)
>>>>>>> 48f33b10e0460d1b1213af2c3d17ecd3f84e0ac5
