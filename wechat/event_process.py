#!/usr/bin/python
# encoding=utf-8

class EventProcess:
	def __init__(self):
		pass
	def click_event(self, key):
		# 点击事件的处理
		if key == 'television':
			return '输入TV类型'
		else:
			return '未处理'
		
