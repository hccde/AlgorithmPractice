#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
//要先找到满二叉树的根
class Node {
public:
	int value;
	int left;
	int right;
	Node(){
		value = 0;
		left = 0;
		right = 0;
	}
	Node(int v,int l,int r):value(v),
	left(l),right(r){

	}
};

void walk(Node* init_list,Node* tool_list,int num,Node* node_list){
	int c(0);
	Node tem;
	for(int i = 0;i < num;i++){
		tem = init_list[i];
		cout<<tem.value<<endl;
		if(tem.left>0){
			if(node_list[tem.left].value != 0){
				tool_list[c++] = node_list[tem.left];
			}else{
				tool_list[c++] = Node(tem.left,0,0);
			}
		}
		if(tem.right>0){
			if(node_list[tem.right].value !=0){
				tool_list[c++] = node_list[tem.right];
			}else{
				tool_list[c++] = Node(tem.right,0,0);
			}
		}
	}
	if(c>0)
		walk(tool_list,init_list,c,node_list);
}



int main()
{ 		
	int count;
	int root;
	cin>>count;
	Node node_list[1024];
	Node tool_list[1024];
	Node init_list[1024];
	int root_list[1024] = {0};

	int value;
	int length = count/2;
	for(int i = 0;i <length;i++){
		cin>>value;
		if(i == 0 ){
			root = value;
		}
		root_list[value] += value;
		node_list[value].value = value;
		cin>>node_list[value].left >> node_list[value].right;
		root_list[node_list[value].left] = node_list[value].left * -1;
		root_list[node_list[value].right] = node_list[value].right * -1;
	}
	for(int i = 0;i<1024;i++){
		if(root_list[i] > 0){
			root = i;
			break;
		}
	}
	init_list[0] = node_list[root];
	walk(init_list,tool_list,1,node_list);

	return 0;	
}