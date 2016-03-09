#!/usr/bin/python
# encoding=utf-8

import get_user_basicMsg
from get_state import UserState
from wechat_sdk.basic import WechatBasic

class MsgProcess:
	def msg_process(self, obj):
		if obj.type == 'text':
			if obj.content == 'app':
				openid = get_user_basicMsg.get_openid(obj)
				us = UserState()
				state = us.get_user_state(openid)			
				return state
			elif obj.content == 'ypyk':
				pass
			else:
				return 'how are you?'
