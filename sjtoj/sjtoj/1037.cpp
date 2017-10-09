#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool more_than(int i,int j){
	return (i>j);
}
void quick_sort(int a[],int length){
	sort(a,a+length,more_than);
}

int main()
{ 		
	int N,M;
	int res(0);
	cin>>N>>M;
	int high[10001]={0},low[10001]={0};
	for(int i = 0;i<N;i++){
		cin>>high[i];
	}
	quick_sort(high,N);
	for(int i = 0;i<M;i++){
		cin>>low[i];
	}
	quick_sort(low,M);

	int save(0);//没有初始化，浪费很多时间
	for(int i = 0;i<N;i++){
		res +=1;
		if(high[i]<low[M-1] || i>= M){
			res = (res-i-1)+N;
			break;
		}
		for(int j = save;j<M;j++){
			if(high[i]>low[j]){
				res+=1;
				save = j+1;
				break;
			}
		}
	}
	cout<<res;
	return 0;	
}