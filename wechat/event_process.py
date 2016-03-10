#!/usr/bin/python
# encoding=utf-8

import sys
from tool.get_user_msg import UserMsg

class EventProcess:
	def __init__(self):
		sys.path.append('tool')
	def click_event(self, obj):
		# 点击事件的处理
		if obj.type == 'click':
			if obj.key == 'television':
				um = UserMsg()
				um.get_user_basicMsg(obj)
				return '请输入TV品牌'
			elif obj.key == 'air_condition':
				return '请输入空调品牌'
			elif obj.key == 'cable':
				return '请输入机顶盒品牌'
			elif obj.key == 'network_box':
				return '请输入网络盒子品牌'
			else:
				return '请求未处理'
		elif obj.type == 'scancode_push':
			#return obj.ScanCodeInfo											
			return 'scan'
		else:
			um = UserMsg()
			um.get_user_basicMsg(obj)
			return '获取地理信息'
