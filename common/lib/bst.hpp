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
        // show_vector(nums);
        // std::cout<<std::endl;
        build_bst(nums.begin()++,nums.end());
    }

    Node* find_node(T value,Node* node){
        if((node->value > value && node->left == NULL) ||
        (node->value <= value && node->right == NULL)){
            return node;
        }else{
            Node* tem = NULL;
            value >= node->value?tem = node->right:tem = node->left;
            return find_node(value,tem);
        }
    }

    void insert_node(T value){
        std::cout<<value<<std::endl;
        Node* parent = find_node(value,root);
        Node* node  = new Node(value,parent,NULL,NULL);
        parent->value > value ? parent->left = node:parent->right = node;
    }

    void build_bst(typename vector<T>::iterator iter,typename vector<T>::iterator end){
        // if(iter!=end){
        //     insert_node(*iter);
        //     typename vector<T>::iterator iters = iter+1;
        //     build_bst(iters,end);
        // }
        for(;iter!=end;iter++){
            // std::cout<<*iter<<" ";
            insert_node(*iter);
        }
    }

    void traversal(Node* node){
        // if(node != NULL){
        //     std::cout<<node->value<<" ";
        //     traversal(node->left);
        //     traversal(node->right);
        // }
    }
    ~Bst(){
        //todo
    }
};

#endif
