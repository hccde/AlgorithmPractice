(function() {
		function quickSork() {
			var raw = [].slice.call(arguments);
			raw.length > 1?sort(raw): nil;

			function sort() {
				for (var j = 1; j < raw.length; j++) {
					if (raw[j] > raw[j - 1])
						continue; //比已经排序的大，进行下一次
					for (var i = 0; i < j; i++) {
						if (raw[i] > raw[j]) { //找到了位置，前插
							var insertEle = raw.splice(j, 1).pop();
							raw.splice(i, 0, insertEle);
							break;
						}
					}

				}

			}
			return raw;
		}
	return quickSork
})()