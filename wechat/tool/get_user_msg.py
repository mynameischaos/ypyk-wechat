#!/usr/bin/python
# encoding=utf-8

import get_wechat

# 用户信息类 
class UserMsg:
	# 返回用户的openid
	def get_openid(self, obj):
		openid = obj.source
		return openid 
	# 通过openid获取用户详细信息
	def get_user_detailMsg(self, openid):
		wechat = get_wechat.get_wechat()
		data = wechat.get_user_info(openid, lang='zh_CN')
		return data
	# 获取用户的基本信息
	# 传入的是消息对象
	def get_user_basicMsg(self, obj):
		id = obj.id          # 对应于 XML 中的 MsgId
		target = obj.target  # 对应于 XML 中的 ToUserName
		source = obj.source  # 对应于 XML 中的 FromUserName
		time = obj.time      # 对应于 XML 中的 CreateTime
		type = obj.type      # 对应于 XML 中的 MsgType
		raw = obj.raw        # 原始 XML 文本，方便进行其他分析

		fp = open('/var/www/weixin/wechat/context', 'a')  #注意最好直接使用绝对路径
		data = {}
		data['id'] = id
		data['target'] = target
		data['source'] = source
		data['time'] = time
		data['type'] = type
		fp.write(str(data) + '\n')
		fp.close()

if __name__ == '__main__':
    um = UserMsg()
    print um.get_user_detailMsg('oNevcspgKodRqe7yevoFMKAa0YCk')
