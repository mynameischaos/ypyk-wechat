// JavaScript Document

/*function clickButton(){
	
	var xmlhttp;
	if(window.XMLHttpRequest){
		xmlhttp = new XMLHttpRequest();	
	}else{
		xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");	
	}
	xmlhttp.onreadystatechange = function(){
			if(xmlhttp.readyState === 4 && xmlhttp.status === 200){
				
				document.getElementById("myDiv").innerHTML=xmlhttp.responseText;
					
			}
			
	}
	xmlhttp.open("GET", "weixin.yipaiyaokong.com?brand=xiaomi&btnName=power", true);
	xmlhttp.send();
	
}*/

//��������
/*
function clickButton(){
	var
		js = document.createElement('script');
		head = document.getElementsByTagName('head')[0];
	js.src = 'http://weixin.yipaiyaokong.com/bit3wa.wav?callback=playWAV';
	head.appendChild(js);
	
}

function playWAV(data){
	var src = document.getElementById('playWAV');
	src.src = data;
}
*/
function clickButton(obj, id)
{

	navigator.vibrate = navigator.vibrate || navigator.webkitVibrate || navigator.mozVibrate || navigator.msVibrate;
	if(navigator.vibrate === false)
	{
		alert('your mobile dosen\'t support vibrate!');
		return;
	}
	else{
		navigator.vibrate(100);
	}
	if(id === 'power_wav')
	{
		var src = document.getElementById('powerWAV');
	}
	else if(id === 'home_wav')
	{
		var src = document.getElementByIdf('homeWAV');
	}
	else if(id === 'up_wav')
	{
		var src = document.getElementById('upWAV');
	}
	else if(id === 'down_wav')
	{
		
		var src = document.getElementById('downWAV')	
	}
	else if(id === 'left_wav')
	{
		var src = document.getElementById('leftWAV')
	}
	else if(id === 'right_wav')
	{
		var src = document.getElementById('rightWAV')
	}
	src.play();
}

/*
// ��������
function orientationChange() {

    switch(window.orientation) {

    ��case 0: 

            alert("���� 0,screen-width: " + screen.width + "; screen-height:" + screen.height);

            break;
    ��case -90: 

            alert("�� -90,screen-width: " + screen.width + "; screen-height:" + screen.height);

            break;

    ��case 90:   

            alert("�� 90,screen-width: " + screen.width + "; screen-height:" + screen.height);

            break;

    ��case 180:   

        ��alert("���� 180,screen-width: " + screen.width + "; screen-height:" + screen.height);

        ��break;
	
    };
	

}


// ������
addEventListener('load', function(){

    orientationChange();

    window.onorientationchange = orientationChange;

});

*/
