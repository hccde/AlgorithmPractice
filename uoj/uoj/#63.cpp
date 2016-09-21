////
////  #63.cpp
////  uoj
////
////  Created by admos on 16/9/21.
////  Copyright © 2016年 admos. All rights reserved.
////满二叉树，左子树 2K 右子树 2K+1
////模拟 比较暴力的算法
//
//#include <stdio.h>
//#include <iostream>
//#include <math.h>
//
//using std::cin;
//using std::cout;
//using std::endl;
//
//static int length;
//
//int run(bool *tree,int index){
//    if(tree[index]){
//        tree[index] = false;
//        if(2*index+1 >= length){
//            return index;
//        }
//        return run(tree, 2*index+1);
//    }else{
//        tree[index] = true;
//        if(2*index >= length){
//            return index;
//        }
//        return run(tree, 2*index);
//    }
//}
//
//int main(){
//    int d,I;
//    
//    //init tree
//    while(1){
//        scanf("%d %d",&d,&I);
//        if(!d && !I){break;}
//        length = pow(2, d);
//        bool *tree = new bool[length];
//        for(int i = 0;i<length;i++){
//            tree[i] = false;
//        }
//        for (int i = 1; i <I; i++) {
//            run(tree, 1);
//        }
//        cout<<run(tree, 1)<<endl;
//    }
//    
////    delete []tree;
//    return 0;
//}