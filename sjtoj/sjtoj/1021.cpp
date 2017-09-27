#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;


int main()
{ 	
	int border;
	cin>>border;
	int** d = new int*[border];

	for(int i = 0;i<border;i++){
		d[i] = new int[border];
	}
	//对角线是环的开始
	int deg = border/2;
	int num(1);
	for(int i = 0;i<deg;i++){
		//一条环

		// top
		for(int j = i;j<border-i;j++){
			d[i][j] = num;
			num++;
		}
		//right
		for(int j = i+1; j<border-i;j++){//rm repated j = i+1
			d[j][border-i-1] = num;
			num++;
		}
		//bottom
		for(int j = border-i-2;j>=i;j--){
			d[border-i-1][j] = num;
			num++;
		}
		//left
		for(int j = border-i-2;j>i;j--){
			d[j][i] = num;
			num++;
		}

	}
	// odd
	if(border%2 != 0){
		d[border/2][border/2] = num;
	}
	//output 
	for(int i = 0;i<border;i++){
		cout<<endl;
		for(int j = 0;j<border;j++){
			cout<<setw(6)<<d[i][j]<<" ";
		}
	}

	//destroy
	for(int i = 0;i<border;i++){
		delete[] d[i];
	}

	return 0;	
}