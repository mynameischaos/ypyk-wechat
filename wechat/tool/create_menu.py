#!/usr/bin/python
# encoding=utf-8

# 微信配置
from wechat_sdk import WechatConf
conf = WechatConf(
    token='yipaiyaokong', 
    appid='wx41f68781ce5afc96', 
    appsecret='35a9fe4bc7c4554594e8c73c240b848b', 
    encrypt_mode='safe',  # 可选项：normal/compatible/safe，分别对应于 明文/兼容/安全 模式
    encoding_aes_key='OXlthXP7Q49yPXws3vRU8W7AJRc2VfxlYJElaVFNpAA',  # 如果传入此值则必须保证同时传入 token, appid
	checkssl=False,
)

# 初始化对象
from wechat_sdk import WechatBasic
wechat = WechatBasic(conf=conf)


# 定义菜单
menu = {
	"button": [
        {
            "name": "我的遥控",
            "sub_button": [
                {
                    "type": "click",
                    "name": "空调",
                    "key": "air_condition"
                },
                {
                    "type": "click",
                    "name": "机顶盒",
                    "key": "cable"
                },
                {
                    "type": "click",
                    "name": "网络盒子",
                    "key": "network_box"
                },
                {
                    "type": "click",
                    "name": "TV电视",
                    "key": "television"
                }
            ]
        },
        {
            "name": "扫码发图",
            "sub_button": [
                {
                    "type": "scancode_waitmsg",
                    "name": "扫码带提示",
                    "key": "rselfmenu_0_0"
                },
                {
                    "type": "scancode_push",
                    "name": "扫码推事件",
                    "key": "rselfmenu_0_1"
                },
                {
                    "type": "pic_sysphoto",
                    "name": "系统拍照发图",
                    "key": "rselfmenu_1_0"
                },
                {
                    "type": "pic_photo_or_album",
                    "name": "拍照或相册发图",
                    "key": "rselfmenu_1_1"
                },
                {
                    "type": "pic_weixin",
                    "name": "微信相册发图",
                    "key": "rselfmenu_1_2"
                }
            ]
        },
        {
            "name": "发送位置",
            "type": "location_select",
            "key": "rselfmenu_2_0"
        }
    ]
}

res = wechat.create_menu(menu)
if res['errmsg'] == 'ok':
	print '创建菜单成功!'
else:
	print '创建菜单失败!'
