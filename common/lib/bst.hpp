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
        ~Node(){
            if(left!=NULL){
            delete left;
            }
            if(right != NULL){
                delete right;
            }
        }
    };

    typedef void* handler(Node*);
    void default_handler(Node* node){
        std::cout<<node->value<<" ";
    }
    void vaild_handler(Node* node){
        std::cout<<"ha";
    }

    Node* root;
    Bst(vector<T> nums){
        root = new Node(nums[0],NULL,NULL,NULL);
        typename vector<T>::iterator begin = nums.begin()+1;
        build_bst(begin,nums.end());
    }

    Node* find_node(T value,Node* node){
        if((node->value >= value && node->left == NULL) ||
        (node->value < value && node->right == NULL)){
            return node;
        }else{
            Node* tem = NULL;
            value > node->value?tem = node->right:tem = node->left;
            return find_node(value,tem);
        }
    }

    void insert_node(T value){
        Node* parent = find_node(value,root);
        Node* node  = new Node(value,parent,NULL,NULL);
        parent->value >= value ? parent->left = node:parent->right = node;
    }

    void build_bst(typename vector<T>::iterator iter,typename vector<T>::iterator end){
        if(iter!=end){
            insert_node(*iter);
            typename vector<T>::iterator iters = iter+1;
            build_bst(iters,end);
        }
    }

    void traversal(Node* node){
        if(node != NULL){
            std::cout<<node->value<<" ";
            traversal(node->left);
            traversal(node->right);
        }
    }

    bool vaild_bst(Node* node){
        bool res(true);
        if(node != NULL){
            if(node->left!=NULL){
                if(node->left->value>node->value){
                    return false;
                }   
            }
            if(node->right!=NULL){
                if(node->right->value<=node->value){
                    return false;
                }
            }
            res = vaild_bst(node->left);
            if(!res){return false;}
            res = vaild_bst(node->right);
            if(!res){return false;}
        }
        return res;
    }
    void delete_node(Node* node){
        if(node != NULL){         
            delete_node(node->left);
            delete_node(node->right);
            // delete  node;
        }
    }

    ~Bst(){
        delete root;
    }
};

#endif
