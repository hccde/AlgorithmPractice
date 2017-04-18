#include <iostream>
using namespace std;

typedef struct Node{
	int value;
	int visited;
} Node;

void buildGraph(Node (*graph)[501],int nl,int nr,int m){
	int count(0);
	int i(0);
	int j(0);
	while(count<m){
		cin>>i>>j;
		graph[i][j].value = 1;
		count+=1;
	}
}
void initArray(Node (*graph)[501]){
	for(int i = 0;i<=500;i++){
		for(int j =0;j<=500;j++){
			graph[i][j].value = 0;
			graph[i][j].visited = 0;
		}
	}
}

void showGrap(Node (*graph)[501]){
	for(int i = 1;i<=500;i++){
		for(int j =1;j<=500;j++){
			if(graph[i][j].value == 1){
				cout<<"nl "<<i<<" nr "<<j<<endl;
			}
		}
	}
}


void showMatch(Node (*graph)[501],int nr,int nl){
	for(int i = 1;i<=nl;i++){
		for(int j = 1;j<=nr;j++){
			if(graph[i][j].value == -1){
				cout<<i<<" "<<j<<endl;
			}
		}
	}
}
// 0 unvisted
// 1 visited
void clearVisited(Node (*graph)[501],int nl,int nr){
	for(int i=1;i<=nl;i++){
		for(int j = 1;j<nr;j++){
			graph[i][j].visited = 0;
		}
	}
}

// 0 no edge
// 1 has edge but dont been match
// -1 has been match
int dfs(Node (*graph)[501],int u,int j,int nl,int nr){

		// for(int j=1;j<=nr;j++){
			if(graph[u][j].value==1 && graph[u][j].visited<1){
				for(int i=1;i<=nl;i++){
					if(graph[i][j].value == -1 && graph[i][j].visited<1){
						cout<<"tt"<<endl;
						for(int t=1;t<=nr;t++){
							int m = dfs(graph,i,t,nl,nr);
							cout<<"m: "<<m<<endl;
							if(m == 0){
								cout<<"mm"<<endl;
								graph[i][j].visited = 1;
								graph[u][j].value = -1;
								graph[u][j].visited=1;
								graph[i][j].value = 1;//revesal
							}
						}
					}
				}
				graph[u][j].value =-1;
				graph[u][j].visited = 1;
				return 0;
			}
			return -1;
}

int main(int argc,char** argv){
	int nl,nr,m;
	cin>>nl>>nr>>m;
	Node graph[501][501];
	initArray(graph);
	buildGraph(graph,nl,nr,m);
	for(int i = 1;i<=nl;i++){
		for(int j=1;j<=nr;j++){
			dfs(graph,i,j,nl,nr);
			showMatch(graph,nr,nl);
			cout<<"--------"<<endl;
			clearVisited(graph,nl,nr);
		}
	}
	return 0;
}