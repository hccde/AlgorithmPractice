#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include "random.hpp"
#include <vector>

template <typename T>
class Bst{
    public:
    class Node{
        public:
        T value;
        Node* parent;
        Node* left;
        Node* right;
        Node(T _value,Node* _parent,Node* _left,Node* _right ):
        value(_value),parent(_parent),left(_left),right(_right){

        }
    };
    Node* root;

    Bst(vector<T> nums){
        root = new Node(nums[0],NULL,NULL,NULL);
        build_bst((nums.begin()+1),nums.end());
    }

    Node* find_node(T value,Node* node){
        if((node->value >= value && node->left == NULL) ||
        (node->value < value && node->right == NULL)){
            return node;
        }else{
            Node* tem = value >= node->value?node->right:node->left;
            return find_node(value,tem);
        }
    }

    Node* insert_node(T value){
        Node* parent = find_node(value,root);
        Node* node  = new Node(value,parent,NULL,NULL);
        node->parent = parent;
        parent->value > value ? parent->left = node:parent->right = node;
        return parent;
    }

    void build_bst(typename vector<T>::iterator iter,typename vector<T>::iterator end){
        if(iter!=end){
            Node* node = insert_node(*iter);
            build_bst(iter+1,end);
        }
    }

    void traversal(Node* node){
        if(node != NULL){
            std::cout<<node->value<<" ";
            traversal(node->left);
            traversal(node->right);
        }
    }
};

#endif
