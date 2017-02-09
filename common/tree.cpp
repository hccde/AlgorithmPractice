#include <iostream>
using namespace std;

template <class T>
int getArrayLen(T& array){
return (sizeof(array) / sizeof(array[0]));
}

//array describe tree,node type is int 
class Node{
private:
	int value;//node value
	int parent;
public:
	Node(){
		//
	}

	Node(int v,int p){
		value = v;
		parent = p;
	}

};

// typedef Node Node;
#define temp_nodes_stack_length 50
class Tree{
	private:
		Node* nodes;
		Node temp_nodes[temp_nodes_stack_length];
		int length;
		int temp_length;


		int get_length(){
			return sizeof(*nodes) / sizeof(Node);
		}

		void copyNode(Node){

		}
		//
		void sync_appendNode(){
			if(temp_length == 0){
				return;
			}
			int new_length = length+temp_nodes_stack_length;
			Node* new_nodes = new Node[new_length];
			for (int i = 0; i < length;i++){
				new_nodes[i] = nodes[i];
			}
			for(int i = length;i<temp_length;i++){
				new_nodes[i] = temp_nodes[i];
			}
			length = new_length;
			delete[] nodes;
			nodes = new_nodes;
			temp_length = 0;
		}

	public:
	Tree(){
		length = 0;
		temp_length = 0;
		nodes = NULL;
	}
	Tree(int total_nodes){
		nodes = new Node[total_nodes];
		length = total_nodes;
		temp_length = 0;

	}
	void appendNode(Node node){
		temp_nodes[temp_length] = node;
		temp_length+=1;
		if(temp_length == temp_nodes_stack_length){
			sync_appendNode();
		}
	}

};

int main(){
	Tree tree = Tree();
	tree.appendNode(Node(0,0));
}