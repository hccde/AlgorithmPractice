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
        typename vector<T>::iterator begin = nums.begin()+1;
        build_bst(begin,nums.end());
    }

    Node* find_node(T value,Node* node){
        if((node->value >= value && node->left == NULL) ||
        (node->value < value && node->right == NULL)){
            return node;
        }else{
            Node* tem = NULL;
            if(value > node->value){
                tem = node->right;
            }else{
                tem = node->left;
            }
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

    void pre_order_traversal(Node* node){
        if(node != NULL){
            std::cout<<node->value<<" ";
            pre_order_traversal(node->left);
            pre_order_traversal(node->right);
        }
    }

    void in_order_traversal(Node* node){
        if(node != NULL){
            in_order_traversal(node->left);
            std::cout<<node->value<<" ";
            in_order_traversal(node->right);
        }
    }

    void post_order_traversal(Node* node){
        if(node != NULL){
            post_order_traversal(node->left);
            post_order_traversal(node->right);
            std::cout<<node->value<<" ";
        }
    }

    bool vaild_bst(Node* node){
        //need to debug
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
    //remove node
    int remove_node(Node* node){
        if(node == NULL){
            std::cout<<"null node";
            return -1;
        }
        if(node->parent == NULL){
            std::cout<<"try to delete root node";
            return -1;
        }
        if(node->left == NULL && node->right == NULL){
            if(node->parent->value > node->value){
                node->parent->left = NULL;
            }else{
                node->parent->right = NULL;
            }
            delete node;
        }else{
            if(node->right == NULL || node->left == NULL){
                Node* tem=NULL;
                //modif node pointer 
                tem = node->right == NULL?node->left:node->right;
                tem->parent = node->parent;
                if(tem->parent->value > tem->value){
                    tem->parent->left = tem;
                }else{
                    tem->parent->right = tem;
                }

                delete node;
                return 0;
            }else{
                //find next node,copy next node value to this node
                Node* tem = inorder_find_nextnode(node->right);
                node->value = tem->value;
                if(tem->parent->value > tem->value){
                    tem->parent->left = NULL;
                }else{
                    tem->parent->right = NULL;
                }
                delete tem;
                return 0;
            }
        }
        return 0;
    }

    //rightree is right child tree node
    Node* inorder_find_nextnode(Node* rightree){
        if(rightree->left == NULL){
            return rightree;
        }else{
            return inorder_find_nextnode(rightree->left);
        }
    }

    void delete_childtree(Node *node){
        if(node != NULL){
            delete_childtree(node->left);
            delete_childtree(node->right);
            delete node;
        }
    }

    ~Bst(){
        delete_childtree(root);
    }
};

#endif
