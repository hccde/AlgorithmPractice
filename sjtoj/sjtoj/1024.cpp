#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

//快排
int main()
{ 	
	int n(0),i(0);
	cin>>n;
	int num[10000];
	while(i<n){
		cin>>num[i];
		i += 1;
	}

	int tem(0);
	int cur(0);
	for(int k = 0;k<n;k++){
		cur = k;
		label1:for(int i = n-1;i>=cur;i--){
			if(num[i]<num[cur]){
				tem = num[cur];
				num[cur] = num[i];
				num[i] = tem;
				cur = i;
				break;
			}
		}

		for(int j = 0;j<=cur;j++){
			if(num[j]>num[cur]){
				tem = num[cur];
				num[cur] = num[j];
				num[j] = tem;
				cur = j;
				goto label1;
			}
		}
		if(cur != k){//基准变化了 就从上一次
			k = k-1;
		}
	}

	for(int l = 0;l < n; l++){
		cout<<num[l]<<" ";
	}

	return 0;	
}