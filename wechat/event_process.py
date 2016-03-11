#!/usr/bin/python
# encoding=utf-8

import sys
from tool.get_user_msg import UserMsg
<<<<<<< HEAD
from python_db.pyDB import pyDB
from tool import get_wechat

class EventProcess:
	def __init__(self):
	    sys.path.append('tool')
            sys.path.append('python_db')
	def click_event(self, obj):
            # click事件
            if obj.type == 'click':
                if obj.key == 'television':
                  state, res = self.click_tv(obj)
                elif obj.key == 'cable':
                    res = self.click_cable(obj)
                elif obj.key == 'network_box':
                    res = self.click_network_box(obj)
                elif obj.key == 'air_condition':
                    res = self.click_air_condition(obj)
                return state, res


            # subscribe 关注事件
            elif obj.type == 'subscribe':
                # 在wechat_device_request中记录
                um = UserMsg()
                openid = um.get_openid(obj)
                pydb = pyDB()
                result = pydb.record_user(openid)
                if result == True:
                    return '感谢您关注一拍遥控！'
                else:
                    return '关注失败！'
            
            elif obj.type == 'unsubscribe':
                um = UserMsg()
                openid = um.get_openid(obj)
                pydb = pyDB()
                pydb.set_if_follow(openid) # TODO bug fix
                pydb.clean_user(openid)
            # 上报地理位置事件
            else:
                um = UserMsg()
                um.get_user_basicMsg(obj)
                return '获取地理信息'

            
        def click_tv(self, obj):
            um = UserMsg()
            openid = um.get_openid(obj)
            # 查询是否已经添加设备
            pydb = pyDB()
            pydb.clean_brand_model_type(openid)
            state, Type, brand, model = pydb.find_user_device('TV', openid)
            # 假设state = False
            if state == True:
                url = 'http://weixin.yipairemote.com/index.html?type=' + Type + '&brand=' + brand + '&model=' + model 
                response = [
                        {
                            'title': '一拍遥控', 
                            'description': '欢迎使用属于您自己的遥控器', 
                            'url': url
                        },        
                        ]
                return 'news', response
            else:
                result = pydb.find_request_state('TV', openid)
                return 'text', result

        def click_air_condition(self, obj):
            um = UserMsg()
            openid = um.get_openid(obj)
            pydb = pyDB()
            pydb.clean_brand_model_type(openid)
            state = pydb.find_user_device('air_condition', openid)
            state = False
            if state == True:
                return '空调的操作界面'
            else:
                result = pydb.find_request_state('air_condition', openid)
                return result

        def click_network_box(self, obj):
            um = UserMsg()
            openid = um.get_openid(obj)
            pydb = pyDB()
            pydb.clean_brand_model_type(openid)
            state = pydb.find_user_device('network_box', openid)
            state = False
            if state == True:
                return '网络盒子的操作界面'
            else:
                result = pydb.find_request_state('network_box', openid)
                return result

        def click_cable(self, obj):
            um = UserMsg()
            openid = um.get_openid(obj)
            pydb = pyDB()
            pydb.clean_brand_model_type(openid)
            state = pydb.find_user_device('cable', openid)
            state = False
            if state == True:
                return '机顶盒的操作界面'
            else:
                result = pydb.find_request_state('cable', openid)
                return result

if __name__ == '__main__':
    ep = EventProcess()
=======

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
>>>>>>> 48f33b10e0460d1b1213af2c3d17ecd3f84e0ac5
