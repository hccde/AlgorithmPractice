#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;


int main()
{ 		
	int m,t,u,f,d,sum(0),result(0);
	char flag;
	bool status(true);
	cin>>m>>t>>u>>f>>d;
	for(int i = 0;i<t;i++){
		cin>>flag;
		if(!status){
			continue;
		}

		if(flag == 'u' || flag == 'd'){
			sum = sum+(u+d);
		}else{
			sum = sum+2*f;
		}

		if(sum >= m){
			result = i;
			status = false;
		}
	}
	if(result == 0){
		result = t;
	}
	cout<<result;
	return 0;	
}