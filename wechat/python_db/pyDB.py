#!/usr/bin/python
# encoding=utf-8

import MySQLdb
import sys
sys.path.append('..')
from  tool.get_user_msg import UserMsg
class pyDB:
    def __init__(self):
        sys.path.append('/var/www/weixin/wechat/tool')
    # 连接数据库 
    def connect_db(self):
        try:
            conn = MySQLdb.connect(host='localhost', user='root', passwd='nimbus@405', port=3306, db='nimbusdata', charset='utf8')
            cur = conn.cursor()
            return cur, conn
        except MySQLdb.Error, e:
            print "Mysql Error %d: %s" %(e.args[0], e.args[1])
            exit(1)

    # 在数据库中记录新关注的用户
    def record_user(self, openid):
        cur, conn = self.connect_db()
        sql = "insert into wechat_request(type, brand, model, openid) values(%s, %s, %s, %s)"
        data = ('', '', '', openid)
        cur.execute(sql, data)
        conn.commit()
        # 存储用户详细信息
        um = UserMsg()
        data = um.get_user_detailMsg(openid)
        sql1 = "insert into wechat_user(openid, province, subscribe_time, language, country, remark, sex, subscribe, nickname, groupid) values (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
        data1 = (data['openid'], data['province'], data['subscribe_time'], data['language'],
                data['country'], data['remark'], data['sex'], data['subscribe'], data['nickname'], 
                data['groupid'])
        cur.execute(sql1, data1)
        conn.commit()
        cur.close()
        conn.close()
        return True
    # 添加微信用户设备信息
    def add_wechat_user_device(self, openid, Type, brand, model):
        cur, conn = self.connect_db()
        sql = "select id from wechat_user where openid=%s"
        cur.execute(sql, [openid])
        conn.commit()
        res = cur.fetchone()
        sql1 = "insert into wechat_user_device(uid, type, brand, model) values(%s, %s, %s, %s) "
        data1 = (res[0], Type, brand, model)
        cur.execute(sql1, data1)
        conn.commit()
        cur.close()
        conn.close()

    # 取消关注设置if_follow为0
    def set_if_follow(self, openid):
        cur, conn = self.connect_db()
        sql = "update wechat_user set if_follow=%s where openid=%s"
        cur.execute(sql, [0, openid])
        conn.commit()
        cur.close()
        conn.close()
        return True
    def find_user_device(self, Type, openid):
        cur, conn = self.connect_db()
        sql = "select id from wechat_user where openid=%s and if_follow=%s"
        result = cur.execute(sql, [openid, 1])
        conn.commit()
        if result == 0:
            return False, None, None, None
        res = cur.fetchone()
        sql2 = "select type, brand, model  from wechat_user_device where uid=%s and type=%s"
        result = cur.execute(sql2, [res[0], Type])
        conn.commit()
        if result != 0:
            res = cur.fetchone()
            cur.close()
            conn.close()
            return True, res[0], res[1], res[2]
        else:
            return False, None, None, None
    
    # 用于判断上传的图片是否具有type和brand信息
    def find_type_brand(self, openid):
        cur, conn = self.connect_db()
        sql = "select type, brand from wechat_request where openid=%s"
        cur.execute(sql, [openid])
        conn.commit()
        res = cur.fetchone()
    
        cur.close()
        conn.close()
        if res[0] != '' and res[1] != '':
            return True
        else:
            return False

    # 清空用户记录
    def clean_user(self, openid):
        cur, conn = self.connect_db()
        sql = "delete from wechat_request where openid=%s"
        cur.execute(sql, [openid])
        conn.commit()
        cur.close()
        conn.close()
    # 清空用户数据 brand and model
    def clean_brand_model_type(self, openid):
        cur, conn = self.connect_db()
        sql1 = "select type from wechat_request where openid=%s " 
        result = cur.execute(sql1, [openid])
        conn.commit()
        res = cur.fetchone()
        return_res = res[0]
     
        sql = "update wechat_request set brand=%s, model=%s, type=%s where openid=%s " 
        cur.execute(sql, ['', '', '', openid])
        conn.commit()
        cur.close()
        conn.close()
        
        return return_res
    #  存储用户输入的品牌
    def set_brand(self, brand, openid):
        cur, conn = self.connect_db()
        sql = "update wechat_request set brand=%s where openid=%s"
        result = cur.execute(sql, [brand, openid])
        conn.commit()
        cur.close()
        conn.close()
        return True
    def find_brand_set_model(self, model, openid):
        cur, conn = self.connect_db()
        sql = "select brand from wechat_request where openid=%s"
        result = cur.execute(sql, [openid])
        conn.commit()
        res = cur.fetchone()
        result = res[0]
        if result != '':
            sql = "update wechat_request set model=%s where openid=%s"
            cur.execute(sql, [model, openid])
            conn.commit()
            cur.close()
            conn.close()
            return True
        else:
            return False
    # 查询用户的请求状态
    def find_type(self, openid):
        cur, conn = self.connect_db()
        sql = "select type from wechat_request where openid=%s"
        result = cur.execute(sql, [openid])
        conn.commit()
        res = cur.fetchone()
        result = res[0]
        if result == '':
            return False
        else:
            return result
    def get_type_brand_model(self, openid):
        cur, conn = self.connect_db()
        sql = "select type, brand, model from wechat_request where openid=%s"
        cur.execute(sql, [openid])
        conn.commit()
        res = cur.fetchone()
        cur.close()
        conn.close()
        return res[0], res[1], res[2]
    def find_request_state(self, Type, openid):
        # 连接数据库
        cur, conn = self.connect_db()
        sql1 = "select type from wechat_request where openid=%s"
        result = cur.execute(sql1, [openid])
        conn.commit()
        res = cur.fetchone()
        result =  res[0]
        if Type == result:
            sql2 = "select brand from wechat_request where openid=%s"
            result = cur.execute(sql2, [openid])
            conn.commit()
            res = cur.fetchone()
            result = res[0]
            if result == '':
                return '请您输入品牌：'
            else:
                sql3 = "select model from wechat_request where openid=%s"
                result = cur.execute(sql3, [openid])
                conn.commit()
                res = cur.fetchone()
                result = res[0]
                if result == '':
                    return '请您输入型号：'
                else:
                    sql4 = "update wechat_request set type=%s, brand=%s, model=%s where openid=%s"
                    cur.execute(sql4, ['', '', '', openid])
                    conn.commit()
                    return '返回遥控器操作界面URL'
        elif (Type != result or result == ''):
            sql5 = "update wechat_request SET type=%s, brand=%s, model=%s where openid=%s"
            cur.execute(sql5, [Type, '', '', openid])
            conn.commit()
            return '请您输入品牌'
        cur.close()
        conn.close()

if __name__ == '__main__':
    pydb = pyDB()
    pydb.connect_db()
    #print pydb.add_wechat_user_device('oNevcsrMuWWGyiW2z9xFdW4dMS38', 'TV', 'xiaomi', '小米电视')
    print pydb.find_user_device('TV', 'oNevcspgKodRqe7yevoFMKAa0YCk')
