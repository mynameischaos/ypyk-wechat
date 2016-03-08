#!/usr/bin/python
# encoding=utf-8

import urllib

def get(url):
	fp = open('/var/www/weixin/wechat/tool/picture_id', 'r')
	nameID = fp.read()
	fp.close()
	conn = urllib.urlopen(url)
	name = '/var/www/weixin/wechat/download_picture/wechat_' + str(nameID) + '.jpg'
	f = open(name, 'wb+')
	f.write(conn.read())
	f.close()
	print '下载图片成功！'

	id = int(nameID) + 1
	fp2 = open('/var/www/weixin/wechat/tool/picture_id', 'w')
	data = str(id)
	fp2.write(data)
	fp2.close()
	

if __name__ == '__main__':
	get('http://mmbiz.qpic.cn/mmbiz/lILAOXFORh82yy2CeQ3cvcWPFFsQcQyibPU8WVBM91GeQonhc4U1D6vuGgDGQDOKjQJib9tavby7tqibDFo4iaz6iaw/0')
