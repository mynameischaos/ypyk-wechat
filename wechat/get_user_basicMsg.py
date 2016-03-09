#!/usr/bin/python
# encoding=utf-8

# 获取用户的基本信息
def get_msg(obj):
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
