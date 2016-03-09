#!/usr/bin/python
# encoding=utf-8

import get_user_basicMsg

class MsgProcess:
	def msg_process(self, obj):
		if obj.type == 'text':
			if obj.content == 'app':
				get_user_basicMsg.get_msg(obj)
				return 'who'
			else:
				return 'how are you?'
