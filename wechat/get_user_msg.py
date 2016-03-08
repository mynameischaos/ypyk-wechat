#!/usr/bin/python
# encoding=utf-8

from wechat_sdk import WechatConf

conf = WechatConf(
	token='yipaiyaokong',
	appid='wx5520539c1d92e2fa',
	appsecret='69c5462eca2fcb04dc2d489c5fc0d043',
	encrypt_mode='safe',
	encoding_aes_key='PQIBCj6d6Ed9EnfbFQyNxoPK6xvzyxixKn9JyGPM0oK',
	
)

from wechat_sdk import WechatBasic
wechat = WechatBasic(conf=conf)


wechat.create_group('zhs')
