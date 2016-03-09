#!/usr/bin/python
# encoding=utf-8

from get_state import UserState
from wechat_sdk.basic import WechatBasic
import sys
from tool.get_user_msg import UserMsg 
import json
import requests

# 图灵机器人的 API KEY
# www.tuling123.com申请领取key
TURING_API_KEY = 'b4e43d544c3e0c5315453ba01fc7ee63'


class MsgProcess:
	def __init__(self):
		sys.path.append('tool')
	# 图灵机器人
	def get_turing(self, message):
		url = 'http://www.tuling123.com/openapi/api?key=' + TURING_API_KEY + '&info='
		req = requests.get(url + message)
		#json通信解析{"code":xxx, "text":xxx}
		return json.loads(req.content)["text"]

	def msg_process(self, obj, wechat):
		if obj.type == 'text':
			if obj.content == 'msg':
				um = UserMsg()
				data = um.get_user_detailMsg(obj)
				return wechat.response_text(data)
			elif obj.content == 'ypyk':
				content = [{
				'title': u'一拍遥控',
				'description': u'点击属于您自己的遥控！',
				'url': u'http://weixin.yipaiyaokong.com/index.html',
				},]
				return wechat.response_news(content)
			else:
				return wechat.response_text(content=self.get_turing(obj.content))
					
