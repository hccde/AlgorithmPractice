#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Node{
public:
	int value;
	int c;
	int s;

	Node(){

	}

	Node(int va,int cc,int ss):
	value(va),c(cc),s(ss){

	}
};

void pre(Node* node_list,int index){
	Node root =  node_list[index];
	cout<<root.value<<" ";
	if(root.c != 0){
		//先遍历左子树
		pre(node_list,root.c);
		
	}
	if(root.s!=0){

		pre(node_list,root.s);
	}
	
}

void wide(Node* stage_list,int count,Node* save,Node* node_list){
	int num(0);
	Node tem;
	for(int i = 0;i<count;i++){
		tem = stage_list[i];
		cout<<tem.value<<" ";
		//把左儿子 右儿子存起来
		if(tem.c != 0){
			save[num++] = node_list[tem.c];
			if(node_list[tem.c].s != 0){
				save[num++] = node_list[node_list[tem.c].s];
			}
			label:if(save[num-1].s != 0){
				int t = num -1;
				save[num++] = node_list[save[t].s];
				goto label;
			}

		}
	}
	if(num != 0){
		wide(save,num,stage_list,node_list);
	}
}

// void middle(Node* node_list,int index){
// 	Node root = node_list[index];
// 	if(root.c != 0){
// 		middle(node_list,root.c);
// 	}
// 	cout<<root.value<<" ";
// 	if(root.s != 0){
// 		middle(node_list,root.s);
// 	}
// }

void behind(Node* node_list,int index){
	Node root = node_list[index];
	if(root.c != 0){
		behind(node_list,root.c);
	}
	cout<<root.value<<" ";
	if(root.s != 0){
		behind(node_list,root.s);
	}
}

int main()
{ 		
	int node_count;
	cin>>node_count;
	int value,root;
	Node* node_list = new Node[node_count+1];
	for(int i = 0;i<node_count;i++){
		cin>>value;

		if(i == 0){
			root = value;
		}

		node_list[value].value = value;
		cin>>node_list[value].c>>node_list[value].s;
	}
	pre(node_list,root);
	cout<<endl;
	// middle(node_list,root);
	behind(node_list,root);
	cout<<endl;

	Node* stage_list = new Node[node_count];
	Node* stage_list_save = new Node[node_count];
	int stage_list_number = 1;
	stage_list[0] = node_list[root];
	wide(stage_list,stage_list_number,stage_list_save,node_list);

	return 0;	
}