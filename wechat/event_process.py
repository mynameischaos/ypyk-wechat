#!/usr/bin/python
# encoding=utf-8


import get_user_basicMsg

class EventProcess:
	def __init__(self):
		pass
	def click_event(self, obj):
		# 点击事件的处理
		if obj.type == 'click':
			if obj.key == 'television':
				self.get_click_user_msg(obj)
				return '请输入TV品牌'
			elif obj.key == 'air_condition':
				return '请输入空调品牌'
			elif obj.key == 'cable':
				return '请输入机顶盒品牌'
			elif obj.key == 'network_box':
				return '请输入网络盒子品牌'
			else:
				return '请求未处理'
		else:
			get_user_basicMsg.get_msg(obj)
			return '选择一拍，遥控世界！'
