#!/usr/bin/python
# encoding=utf-8

import sys
from tool.get_user_msg import UserMsg
from tool import download_picture
from python_db.pyDB import pyDB

class ImgProcess:
    def __init__(self):
        sys.path.append('tool')
        sys.path.append('python_db')
    
    def check_picture(self, obj):
        um = UserMsg()
        openid = um.get_openid(obj)
        pydb = pyDB()
        result = pydb.find_type_brand(openid)
        if result == True:
            download_picture.get(obj.picurl)
            return '返回识别结果'
        else:
            return '请点击我的遥控'
