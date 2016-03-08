(function(){  
    var init=function(){  
        var updateOrientation=function(){  
            var orientation=window.orientation;  
            switch(orientation){  
                case 90:   
                case -90: 
			/*
			var rotate = document.getElementById('rotate90');
			rotate.style.transform = "rotate(90deg)"; 
			//rotate.style.-moz-transform = "rotate(90deg)";
			//rotate.style.-ms-transform = "rotate(90deg)";
			rotate.style.-webkit-transform = "rotate(90deg)";
			//rotate.style.-o-transform = "rotate(90deg)";
			*/
			addCSSRule(document.styleSheets[2], "rotate90", "-webkit-transform:rotate(90deg)");
			alert('90');
                    	break;  
                default:  
                    break;  
            }  
        };  

        window.addEventListener("orientationchange",updateOrientation,false);  
        updateOrientation();  
    };  
    window.addEventListener("DOMContentLoaded",init,false);  
})();  
function addCSSRule(sheet, selector, rules, index){
	if(sheet.insertRule){
		sheet.insertRule(selector + "{" + rules + "}", index);
	}	
	else{
		sheet.addRule(selector, rules, index);
	}
	
} 
