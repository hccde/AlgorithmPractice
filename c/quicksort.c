#include <stdio.h>
int 
int main(void){
	//  需排序的数组
	//应该使用链表
	int needSorted = [1,3,2,6,4];
	int len = sizeof(needSorted)/sizeof(int);
	int i =1;
	for(;i<len;i++){
		if (needSorted[i]>needSorted[i-1])
		{
			continue;
		}
		int j =1;
		for(;j<i;j++){
			if (needSorted[i]<needSorted[j])
			{
				int insertEle = needSorted[i];

			}
		}
	}
	return 1;
}