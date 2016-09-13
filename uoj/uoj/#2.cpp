//
//  #2.cpp
//  uoj
//
//  Created by admos on 16/9/7.
//  Copyright © 2016年 admos. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <math.h>
//#include "gtest/gtest.h"
//注意整型溢出 int 溢出到 unsinged int
//注意数组长度的分配！是m+1 而不是 m
//堆上分配的内存要初始化

using std::cin;
using std::cout;
using std::endl;

#define SIZE sizeof(int)*8

 int toBinary(int num,char number[SIZE]){
    int count(0);
    for(int k=0;k<SIZE;k++){
        int tem = num>>1;
        number[k] = ((tem<<1)-num) == 0?'0':'1';
        num = tem;
        count = count+1;
        if(num == 0){break;}
    }
     for(int t=count;t<SIZE-1;t++){
         number[t] = '0';
     }
    return count;
}

typedef struct door{
    char op;
    char number[SIZE];
} Door;

int compute(Door doors[],int doorsize,int bit,char value){
    int tem = value - '0';
    int cases = 0;
    for(int i =0;i<doorsize;i++){
         cases = doors[i].number[bit]-'0';
        if(doors[i].op == 'A'){
            if(cases == 0){
                tem = 0;
            }else{
                tem = 1*tem;
            }
        }
        if(doors[i].op == 'O'){
            if(cases == 0){
                tem = tem+0;
            }else{
                tem = 1;
            }
        }
        if(doors[i].op == 'X'){
            if(tem ==cases){
                tem = 0;
            }else{
                tem = 1;
            }
        }
    }
    return tem;
}

int main(int argc,char* argv[]){

    int n(0),m(0);
    cin>>n>>m;
    Door* doors = new Door[n];
    int t(0);
    char op[3];
    for (int i=0; i<n; i++) {
        cin>>op>>t;
        toBinary(t,doors[i].number);
        doors[i].op = op[0];
    }
    
        char attack[SIZE];
        int result[SIZE]={0};
    
        int count = toBinary(m, attack);//最大的数
        int flag = 0;
        for(int j=(count-1);j>=0;j--){//从高位开始处理
            if(count == 1){
                result[j] = compute(doors,n,j,attack[j]);
                continue;//特殊处理
            }
//            if(compute(doors,n,j,attack[j])==1){
//                if(compute(doors, n, j, <#char value#>)) 0也可以 1也可以 使得1变0 为低位创造条件 #todo
//                result[j]=1;
//            }else{
//                char tem = (!(attack[j]-'0'))+'0';
//                if((flag==0) && (attack[j]=='0')){result[j] = 0;continue;}//之前没有任何一个高位1变0 则不能0变1
//                if(compute(doors,n,j,tem)==1){
//                    if(attack[j]=='1'){flag=1;}//第一次1变0之后都可以0变1
//                    result[j]=1;
//                }else{
//                    if(attack[j]=='1'){flag=1;}
//                    result[j]=0;
//                }
//            }
            if(attack[j] == '1'){
                if(compute(doors,n,j,attack[j])==1){
                    result[j] = 1;
                }else{
                    result[j] = 0;
                    flag = 1;
                }
                if(compute(doors,n,j,'0')==1){
                    flag = 1;
                    result[j] = 1;
                }
            }else{
                if(compute(doors,n,j,attack[j])==1){
                    result[j] = 1;
                }else{
                    if(flag){
                        if(compute(doors,n,j,'1')==1){
                            result[j] = 1;
                        }else{
                            result[j] = 0;
                        }
                    }else{
                        result[j] = compute(doors,n,j,attack[j]);
                    }
                }
            }
        }
    
    for(int j= count;j<(SIZE-1);j++){
        result[j] = compute(doors,n,j,'0');
    }
    
    int maxattack(0);
    for (int i =0; i<(SIZE-1); i++) {
        int tem = (int)pow(2, i);
        maxattack = maxattack+result[i]*tem;
    }
    cout<<maxattack<<endl;
    delete []doors;
    return 0;
    
}
//    int n(0),m(0);
//    cin>>n>>m;
//    m = m+1;
//    unsigned int* arr = new unsigned int[m];
//    for (int i=0; i<n; i++) {
//        char op[4];
//        int t;
//        cin>>op>>t;
//
//        if(i == 0){
//            for(int j= 0;j<m;j++){
//                arr[j] = j;
//            }
//        }
//
//        if(t ==0){
//
//        }
//        //
//        for (int j = 0; j<m; j++) {
//            if(op[0] == 'A'){arr[j] = arr[j] & t;}
//            if(op[0] == 'O'){arr[j] = arr[j] | t;}
//            if(op[0] == 'X'){arr[j] = arr[j] ^ t;}
//        }
//    }
//    //
//    unsigned int best(0);
//    for (int j = 0; j < m; j++) {
//        if(j == 0){best = arr[j];}
//        arr[j]>best?best=arr[j]:best;
//    }
//    cout<<best<<endl;
//    return 0;
//优化之前的算法