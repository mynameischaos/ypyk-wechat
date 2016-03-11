#!/usr/bin/python
# encoding=utf-8

from get_state import UserState
from wechat_sdk.basic import WechatBasic
import sys
from tool.get_user_msg import UserMsg 
from python_db.pyDB import pyDB
import json
import requests

# 图灵机器人的 API KEY
# www.tuling123.com申请领取key
TURING_API_KEY = 'b4e43d544c3e0c5315453ba01fc7ee63'


class MsgProcess:
    def __init__(self):
        sys.path.append('tool')
   # 图灵机器人
    def get_turing(self, message):
       url = 'http://www.tuling123.com/openapi/api?key=' + TURING_API_KEY + '&info='
       req = requests.get(url + message)
       #json通信解析{"code":xxx, "text":xxx}
       return json.loads(req.content)["text"]
    
    def find_brand(self, brand, filename):
        fp = open(filename, 'r')
        for line in fp.readlines():
            if brand == line.strip():
                fp.close()
                return True
        fp.close()
        return False

    def msg_process(self, obj, wechat):
        if obj.type == 'text':
            um = UserMsg()
            openid = um.get_openid(obj)
            pydb = pyDB()
            result = pydb.find_type(openid)
            if result != False:
                # 检测输入的品牌是否存在
                if result == 'TV':
                    res = self.find_brand(obj.content, '/var/www/weixin/wechat/brand/tv.txt')
                elif result == 'air_condition':
                    res = self.find_brand(obj.content, '/var/www/weixin/wechat/brand/air_condition.txt')
                elif result == 'cable':
                    res = self.find_brand(obj.content, '/var/www/weixin/wechat/brand/cable.txt')
                elif result == 'network_box':
                    res = self.find_brand(obj.content, '/var/www/weixin/wechat/brand/network_box.txt')

                # 查询brand设置model
                res2 = pydb.find_brand_set_model(obj.content, openid)
                if res2:
                    res3 = pydb.clean_brand_model_type(openid)
                    if res3 == 'TV':
                        return wechat.response_text('电视遥控器操作界面')
                    elif res3 == 'air_condition':
                        return wechat.response_text('空调遥控器操作界面')
                    elif res3 == 'network_box':
                        return wechat.response_text('网络盒子遥控器操作界面')
                    elif res3 == 'cable':
                        return wechat.response_text('机顶盒遥控器操作界面')
                else:
                    if res:
                        pydb.set_brand(obj.content, openid)
                        return wechat.response_text("请您输入型号或者拍摄上传您的遥控器:")
                    else:
                        return wechat.response_text(content=self.get_turing(obj.content))
            else:
                return wechat.response_text(content=self.get_turing(obj.content))
            if obj.content == 'ypyk':
                content = [{
                   'title': u'一拍遥控',
                   'description': u'点击属于您自己的遥控！',
                   'url': u'http://weixin.yipaiyaokong.com/index.html',
                   },]
                return wechat.response_news(content)
            else:
                return wechat.response_text(content=self.get_turing(obj.content))

if __name__ == '__main__':
    mp = MsgProcess()
    res = mp.Find('小米')
    if res:
        print 'ok'

