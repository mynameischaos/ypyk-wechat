#!/usr/bin/python
# encoding=utf-8

from wechat_sdk import WechatConf
from wechat_sdk import WechatBasic

def get_wechat():
	# 微信配置
	conf = WechatConf(
		token='yipaiyaokong', 
		appid='wx41f68781ce5afc96', 
		appsecret='35a9fe4bc7c4554594e8c73c240b848b', 
		encrypt_mode='safe',  # 可选项：normal/compatible/safe，分别对应于 明文/兼容/安全 模式
		encoding_aes_key='OXlthXP7Q49yPXws3vRU8W7AJRc2VfxlYJElaVFNpAA',  # 如果传入此值则必须保证同时传入 token, appid
		checkssl=False,
	)

	# 初始化对象
	wechat = WechatBasic(conf=conf)
	return wechat

if __name__ == '__main__':
	print get_wechat()
