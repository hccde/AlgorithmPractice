#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

int ackerman(int m,int n){
	if(m == 0){
		return n+1;
	}
	if(n == 0){
		return ackerman(m-1,1);
	}

	int tem = ackerman(m,n-1);
	return ackerman(m-1,tem);
}
int main()
{ 		
	int m,n;
	cin>>m>>n;
	cout<<ackerman(m,n);
	return 0;	
}