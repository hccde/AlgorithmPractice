#include <iostream>
using namespace std;
void buildGraph(int (*graph)[501],int nl,int nr,int m){
	int count(0);
	int i(0);
	int j(0);
	while(count<m){
		cin>>i>>j;
		graph[i][j] = 1;
		count+=1;
	}
}
void initArray(int (*graph)[501]){
	for(int i = 0;i<=500;i++){
		for(int j =0;j<=500;j++){
			graph[i][j] = 0;
		}
	}
}
void showGrap(int (*graph)[501]){
	for(int i = 1;i<=500;i++){
		for(int j =1;j<=500;j++){
			if(graph[i][j] == 1){
				cout<<"nl "<<i<<" nr "<<j<<endl;
			}
		}
	}
}

int main(int argc,char** argv){
	int nl,nr,m;
	cin>>nl>>nr>>m;
	int graph[501][501];
	initArray(graph);
	buildGraph(graph,nl,nr,m);
	showGrap(graph);
	return 0;
}