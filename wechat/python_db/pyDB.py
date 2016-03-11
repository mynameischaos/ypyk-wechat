#!/usr/bin/python
# encoding=utf-8

import MySQLdb


class pyDB:
    def __init__(self):
        pass
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
        sql = "insert into wechat_device(type, brand, model, openid) values(%s, %s, %s, %s)"
        data = ('', '', '', openid)
        cur.execute(sql, data)
        conn.commit()
        cur.close()
        conn.close()
        return True

    def find_user_device(self, Type, openid):
        pass
    
    # 用于判断上传的图片是否具有type和brand信息
    def find_type_brand(self, openid):
        cur, conn = self.connect_db()
        sql = "select type, brand from wechat_device where openid='%s' " % (openid)
        cur.execute(sql)
        res = cur.fetchone()

        conn.commit()
        cur.close()
        conn.close()
        if res[0] != '' and res[1] != '':
            return True
        else:
            return False

    # 清空用户记录
    def clean_user(self, openid):
        cur, conn = self.connect_db()
        sql = "delete from wechat_device where openid='%s' " % (openid)
        cur.execute(sql)
        conn.commit()
        cur.close()
        conn.close()
    # 清空用户数据 brand and model
    def clean_brand_model_type(self, openid):
        cur, conn = self.connect_db()
        sql1 = "select type from wechat_device where openid='%s' " % (openid)
        result = cur.execute(sql1)
        conn.commit()
        res = cur.fetchone()
        return_res = res[0]
     
        sql = "update wechat_device set brand='%s', model='%s', type='%s'  where openid='%s' " % ('', '', '', openid)
        cur.execute(sql)
        conn.commit()
        cur.close()
        conn.close()
        
        return return_res
    #  存储用户输入的品牌
    def set_brand(self, brand, openid):
        cur, conn = self.connect_db()
        sql = "update wechat_device set brand='%s' where openid='%s' " % (brand, openid)
        result = cur.execute(sql)
        conn.commit()
        cur.close()
        conn.close()
        return True
    def find_brand_set_model(self, model, openid):
        cur, conn = self.connect_db()
        sql = "select brand from wechat_device where openid='%s' " % (openid)
        result = cur.execute(sql)
        conn.commit()
        res = cur.fetchone()
        result = res[0]
        if result != '':
            sql = "update wechat_device set model='%s' where openid='%s' " % (model, openid)
            cur.execute(sql)
            conn.commit()
            cur.close()
            conn.close()
            return True
        else:
            return False
    # 查询用户的请求状态
    def find_type(self, openid):
        cur, conn = self.connect_db()
        sql = "select type from wechat_device where openid='%s' " % (openid)
        result = cur.execute(sql)
        conn.commit()
        res = cur.fetchone()
        result = res[0]
        if result == '':
            return False
        else:
            return result
    def find_request_state(self, Type, openid):
        # 连接数据库
        cur, conn = self.connect_db()
        sql1 = "select type from wechat_device where openid='%s' " % (openid)
        result = cur.execute(sql1)
        conn.commit()
        res = cur.fetchone()
        result =  res[0]
        if Type == result:
            sql2 = "select brand from wechat_device where openid='%s'" % (openid)
            result = cur.execute(sql2)
            conn.commit()
            res = cur.fetchone()
            result = res[0]
            if result == '':
                return '请您输入品牌：'
            else:
                sql3 = "select model from wechat_device where openid='%s' " % (openid)
                result = cur.execute(sql3)
                conn.commit()
                res = cur.fetchone()
                result = res[0]
                if result == '':
                    return '请您输入型号：'
                else:
                    sql4 = "update wechat_device set type='%s' and brand='%s' and  model='%s' where openid='%s' " % ( '', '', '', openid)
                    cur.execute(sql4)
                    conn.commit()
                    return '返回遥控器操作界面URL'
        elif (Type != result or result == ''):
            sql5 = "update wechat_device SET type='%s', brand='%s', model='%s' where openid='%s' " % (Type, '', '',  openid)
            cur.execute(sql5)
            conn.commit()
            return '请您输入品牌'
        cur.close()
        conn.close()

if __name__ == '__main__':
    pydb = pyDB()
    pydb.connect_db()
    res = pydb.find_brand_set_model('bb', 'oNevcspgKodRqe7yevoFMKAa0YCk')
    print res
