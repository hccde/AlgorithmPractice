(function(){
	function sort(){

		var raw = [].slice.call(arguments);
		if(raw.length<1)
			return raw;
		for(var j =0;j<raw.length-1;j++){
		for(var i =0;i<raw.length-1;i++){
			if(raw[i]<raw[i+1]){
				continue;
			}
			var tme;
			tem = raw[i];
			raw[i]=raw[i+1];
			raw[i+1] = tem;
		}
	}
		return raw
	}
	return sort;
})()