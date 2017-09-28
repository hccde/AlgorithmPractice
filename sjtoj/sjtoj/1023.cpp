#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
// 竟然是用scanf 和 printf 过的
int tem[600];
int main()
{ 		
	int count(0);
	cin>>count;
	int border,direction;
	for(int c = 0; c < count;c++){
		// cin>>border>>direction;
		scanf("%d%d",&border,&direction);
		//建立矩阵
		int bor = border-1;
		int* d[600];
		int inner[600*600];
		for(int k = 0;k<border;k++){
			d[k] = inner+k*600;
			for(int j = 0;j<border;j++){
				// cin>>d[k][j];
				scanf("%d",&d[k][j]);
			}
		}


				switch(direction){
					case 0:
						for(int j = 0;j<border;j++){
							for(int i = 0;i<border;i++){
								printf("%d ",d[j][bor-i]);
							}
								if(j != bor)
									printf("\n");
						}
						break;
					case 1: 	
						for(int j = 0;j<border;j++){
							for(int i = 0;i<border;i++){
								printf("%d ",d[bor-j][i]);
							}
							if(bor != j)
								printf("\n");
						}
						break;
					case 2:
						for(int i = 0;i<border;i++){ // i j互换
							for(int j = 0;j<border;j++){
								printf("%d ",d[j][i]);
							}
							if(bor != i)
								printf("\n");
						}
					break;
				}
		
	}
	return 0;	
}