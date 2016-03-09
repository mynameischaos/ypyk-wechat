#!/usr/bin/python
# encoding=utf-8

import urllib
import os
import hashlib
import time
import urllib2
import datetime

# 获取遥控器的红外编码
def get_encode(type, brand, model):
	data = {
		'type': type,
		'brand': brand,
		'model': model,
	}
	requrl = 'http://115.231.180.19:8000/device.do'
	data_encode = urllib.urlencode(data)

	req = urllib2.Request(url=requrl, data=data_encode)
	#print req

	res_data = urllib2.urlopen(req)
	res =  res_data.read()
	#print res
	res_dict = eval(res)
	return res_dict

def wav_file_gen(encoding_type, ir_code, frequency, signal_strength, btn_name, brand):

    # Name
    md_lib = hashlib.md5()

    today = datetime.date.today()
    today_str = str(today)
    md_lib.update(today_str)
    today_name = (md_lib.hexdigest())[0:10]

    wav_src = btn_name + time.strftime('%Y%m%d', time.localtime(time.time()))
    md_lib.update(wav_src)
    wav_name = (md_lib.hexdigest())[0:10]

    brand_src = brand + time.strftime('%m%d', time.localtime(time.time()))
    md_lib.update(brand_src)
    brand_name = (md_lib.hexdigest())[0:10]

    # Path
    path_brand = brand_name + "/"
    path_header = "/var/www/weixin/wechat/static/media/"
    today_folder = path_header + today_name + "/"

    # File
    raw_data = today_folder + path_brand + wav_name
    pcm_file = raw_data + ".pcm"
    wav_file = raw_data + ".wav"
    relative_wav_file = "media/" + today_name + "/" + path_brand + wav_name + ".wav"

    # Delete Older Path
    for day in range(1, 6):
        date_src = str(today - datetime.timedelta(days=day))
        print date_src
        md_lib.update(date_src)
        old_date_name = (md_lib.hexdigest())[0:10]
        print old_date_name
        old_name = path_header + old_date_name
        if os.path.isdir(old_name):
            rm_older = "rm -rf " + old_name

    # If File Exist
    if os.path.exists(wav_file):
        return relative_wav_file
    else:
        # Command
        mkdir = "mkdir -p " + today_folder + path_brand
        raw_data_gen = "rawDataGen " + encoding_type + " '" + ir_code + "' " + frequency + " " + signal_strength
        print raw_data_gen
        xxd = "xxd -r -p " + raw_data + " " + pcm_file
        print xxd
        ffmpeg = "ffmpeg -y -f s16be -ar 44.1k -ac 2 -i " + pcm_file + " " + wav_file
        print ffmpeg
        # Execute
        os.popen(mkdir)
        file_handler = open(raw_data, 'w')
        file_handler.write(os.popen(raw_data_gen).read().strip('\n'))
        file_handler.close()
        os.popen(xxd)
        os.popen(ffmpeg)
    return relative_wav_file

	
# 解析按键的红外码
'''
POWER=电源=MiBox=0 3CCC==OK=确认=MiBox=0 860D==MENU=菜单=MiBox=0 8604==
UP=上=MiBox=0 8605==DOWN=下=MiBox=0 8606==LEFT=左=MiBox=0 860B==RIGHT=右=MiBox=0 860C==
VOL+=音量+=MiBox=0 860E==VOL-=音量-=MiBox=0 860F==RETURN=返回=MiBox=0 8607==HOME=主页=MiBox=0 8608
'''
def parse_button(str):
	buttons = []
	data = str.split('==')
	for i in data:
		btn = {}
		btnData = i.split('=')
		btn['name'] = btnData[0]
		btn['encoding_type'] = btnData[2]
		btn['ir_code'] = btnData[3]
		buttons.append(btn)
	return buttons

def create_wavFile(type, brand, model):
	res_dict = get_encode(type, brand, model)
	buttons = parse_button(res_dict['Buttons'])
	#wav_index = wav_file_gen('MiBox', '0 3CCC', str(res_dict['Frequency']), str(1), 'Power',res_dict['Brand'])
	btnName_pos = []
	for btn in buttons:
		position = wav_file_gen(btn['encoding_type'], btn['ir_code'], str(res_dict['Frequency']), str(1), btn['name'], res_dict['Brand'])
		#print btn['name'] + position
		data = {}
		data['btnName'] = btn['name']
		data['position'] = position
		btnName_pos.append(data)
	return btnName_pos
		

# 测试
if __name__ == '__main__':
	print create_wavFile('TV', 'xiaomi', '小米电视')
	
