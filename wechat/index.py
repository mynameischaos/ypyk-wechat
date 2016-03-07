#!/usr/bin/python
# encoding=utf-8

from flask import Flask, request, make_response
import hashlib
import wechat_sdk


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

        if message.type == 'text':
            if message.content.lower() in 'app':
                response = wechat.response_text(u'abc')
            else:
                response = wechat.response_text(u'how do you do')

        return make_response(response.encode('utf-8'))


@app.route('/hello/')
def hello():
    return 'hello world!!!'

if __name__ == '__main__':
    app.run(host='127.0.0.1', debug=True)
