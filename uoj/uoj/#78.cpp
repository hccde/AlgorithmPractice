#include <iostream>
using namespace std;
typedef struct  edge{
	int start;
	int end;
} Edge;

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

void showGrap(int (*graph)[501],int u){
	for(int i = 1;i<=500;i++){
		for(int j =1;j<=500;j++){
			if(graph[i][j] == 1){
				cout<<"nl "<<i<<" nr "<<j<<endl;
			}
		}
	}
}

int hasMatch(int (*graph)[501],int itemr,int nl){
	for(int i = 1;i<=nl;i++){
		if(graph[i][itemr]<0){
			return i;
		}
	}
	return -1;
}
// 0 no edge
// 1 has a edge
// -1 this edge has been match
int  dfs(int (*graph)[501],int u,int begin,int nr,int nl){
	for(int i=begin;i<=nr;i++){
		if(graph[u][i]>0){
			int iteml = hasMatch(graph,i,nl);
			if(iteml != -1){
				if(dfs(graph,iteml,1,nr,nl) == 0){
					graph[u][i] = -1;
					graph[iteml][i] = 1;//reverse
					cout<<"change"<<endl;
				}
			}else{
				graph[u][i] = -1;
				cout<<"tt";
				return 0;
			}
		}
	}	
	return -1;
}

int DFS(int (*graph)[501],int u,int nr,int nl){
	for(int i=1;i<=nr;i++){
		if(graph[u][i]>0){
			dfs(graph,u,i,nr,nl);
		}
	}
	return 0;
}

void showMatch(int (*graph)[501],int nr,int nl){
	for(int i = 1;i<=nr;i++){
		for(int j = 1;j<=nr;j++){
			if(graph[i][j] == -1){
				cout<<i<<" "<<j<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	int nl,nr,m;
	// Edge match[501];
	// initMatch(match);

	cin>>nl>>nr>>m;
	int graph[501][501];
	initArray(graph);
	buildGraph(graph,nl,nr,m);
	for(int i = 1;i<=nl;i++){
		DFS(graph,i,nr,nl);
	}
	showMatch(graph,nr,nl);
	return 0;
}