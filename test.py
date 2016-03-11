#!/usr/bin/python
# -*- coding: utf-8 -*-
 
import os
import sys
import cgitb
import urlparse
import time
import requests
import json
from wechat_sdk import WechatBasic

# 图灵机器人的 API KEY
# www.tuling123.com申请领取key
TURING_API_KEY = 'b4e43d544c3e0c5315453ba01fc7ee63'
 
# 微信公众平台 TOKEN
TOKEN = 'yipaiyaokong'

# 图灵机器人
def get_turing(message):
    url = 'http://www.tuling123.com/openapi/api?key=' + TURING_API_KEY + '&info='
    req = requests.get(url + message)
    #json通信解析{"code":xxx, "text":xxx}
    return json.loads(req.content)["text"]
 
# 启用调试
cgitb.enable()
 
# 获取 POST 内容
body_text = sys.stdin.read()
 
# 获取 URL 参数
query_string = os.environ.get("QUERY_STRING")
 
# 不带参数直接访问，则跳转回主页
if query_string == '':
    print 'Status: 301 Moved Permanently'
    print 'Location: https//:zhs.space'
    print ''
    sys.exit(1)
 
# 如果含参数，解析各个参数 CGI编程
print 'Content-Type: text/html'
print ''
 
arguments = urlparse.parse_qs(query_string)
 
signature = arguments['signature'][0]
timestamp = arguments['timestamp'][0]
nonce = arguments['nonce'][0]
 
# 校验时间戳。5 分钟以前的 timestamp 自动拒绝
current_timestamp = int(time.time())
 
if (current_timestamp - int(timestamp)) > 300:
    print 'Status: 403 Forbidden'
    print ''
    print 'Incorrect timestamp'
    sys.exit(1)
 
# 实例化 Wechat
wechat = WechatBasic(token=TOKEN)
 
# 接口检测部分
try:
    echostr = arguments['echostr'][0]
except:
    echostr = None
 
if echostr != None:
    if wechat.check_signature(signature=signature, timestamp=timestamp, nonce=nonce):
        print echostr
        sys.exit(0)
    else:
        print 'Signature Mismatch'
        sys.exit(1)
 
# 对来自微信服务器的信息处理部分
if wechat.check_signature(signature=signature, timestamp=timestamp, nonce=nonce):
    # 对 XML 数据进行解析
    wechat.parse_data(body_text)
 
    # 获得解析结果, message 为 WechatMessage 对象 (wechat_sdk.messages中定义)
    message = wechat.get_message()
 
    response = None


    if message.type == 'text':
        if message.content.lower() in ('hello', 'hi'):
	    response = wechat.response_text(u'Who are you!')
	elif message.content.encode(encoding='UTF-8', errors='strict').lower() in (u'一拍遥控', 'app', 'ypyk', 'APP'):
	    response = wechat.response_news(
		[
			{
				'title': u'一拍遥控',
				'description': u'点击进入属于您自己的遥控器',
				#'url':u'http://demo.open.weixin.qq.com/jssdk',
				'url': u'http://weixin.yipaiyaokong.com/ypyk-web/wechat/index.html',
				'picurl': u'http://weixin.yipaiyaokong.com/ypyk-web/wechat/image/page.png',
			},

		])
        else:
            response = wechat.response_text(content = get_turing(message.content))
    print response.encode('utf-8')
