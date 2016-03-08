#!/usr/bin/python
# encoding=utf-8

from wechat_sdk import WechatConf
import urllib

conf = WechatConf(
	token='yipaiyaokong',
	appid='wx41f68781ce5afc96',
	appsecret='35a9fe4bc7c4554594e8c73c240b848b',
	encrypt_mode='safe',
	encoding_aes_key='PQIBCj6d6Ed9EnfbFQyNxoPK6xvzyxixKn9JyGPM0oK',
	
)

from wechat_sdk import WechatBasic
wechat = WechatBasic(conf=conf)

accessToken = wechat.get_access_token()
access_token = accessToken['access_token']
access_token_expires_at = accessToken['access_token_expires_at']

# 获取用户列表
# 参考：http://mp.weixin.qq.com/wiki/12/54773ff6da7b8bdc95b7d2667d84b1d4.html

#https://api.weixin.qq.com/cgi-bin/user/get?access_token=ACCESS_TOKEN&next_openid=NEXT_OPENID

url = 'https://api.weixin.qq.com/cgi-bin/user/get?access_token=' + access_token + '&next_openid='
data = urllib.urlopen(url).read()

mydict = eval(data)
num = mydict['total']
array = []
# 获取用户基本信息
# https://api.weixin.qq.com/cgi-bin/user/info?access_token=ACCESS_TOKEN&openid=OPENID&lang=zh_CN
for i in range(0,  num):
	openid = mydict['data']['openid'][i]
	url = ' https://api.weixin.qq.com/cgi-bin/user/info?access_token=' + access_token + '&openid=' + openid + '&lang=zh_CN'
	data = urllib.urlopen(url).read()
	print data.decode('utf8')
	array.append(data.decode('utf8'))



