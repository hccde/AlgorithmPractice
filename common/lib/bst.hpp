#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include "random.hpp"
#include <vector>

template <typename T>
class Bst{
    public:
    struct Node{
        T value;
        Node pre;
        Node left;
        Node right;
    };
    Bst(vector nums){

    }
    void insert_node(T value,Node left,Node right){

    }
};

#endif
