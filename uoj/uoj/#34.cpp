#include <iostream>
using namespace std;
int* getNumber(int arr[],int size){
	for(int i=0;i<=size;i++){
		cin>>arr[i];
	}
	return arr;
};

void out(int *res,int size){
	for(int i=0;i<size;i++){
		cout<<res[i]<<" ";
	}
	cout<<res[size];
}

void initArr(int *arr,int size){
	for(int i=0;i<=size;i++){
		arr[i] = 0;
	}
}

int main(int argc,char**argv){
	int n=0,m=0;
	cin>>n>>m;
	int *front = getNumber(new int[n+1],n);
	int *behind = getNumber(new int[m+1],m);
	int *res = new int[n+m+1];
	initArr(res,n+m);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			res[i+j] = res[i+j]+(front[i])*(behind[j]);
		}
	}

	out(res,n+m);
	return 0;
}