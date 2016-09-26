//
//  #108.cpp
//  uoj
//
//  Created by admos on 16/9/21.
//  Copyright © 2016年 admos. All rights reserved.
// 暴力解法
//可以考虑缓存查询，比如说当前一次查询是当前一次查询的子集，那么前一次的计算结果可以复用
//暴力不 AC 改用线段树
//处理成满二叉树

#include <stdio.h>
#include <iostream>
#include <math.h>
using std::endl;
using std::cin;
using std::cout;

//数据结构
typedef struct node{
    int start;
    int end;
    int sum;
} NODE;

static int dep;

int sum(int a[],int m,int n){
    int re(0);
    for(int i=m;i<=n;i++){
        re = re+a[i-1];
    }
    return re;
}
int pre_dep(int length){
    int i(0);
    while(pow(2,i)-length<0){
        i += 1;
    }
    return i;
}

int pre_length(int dep){
    int res(0);
    for(int i = 0;i<=dep;i++){
        res = pow(2, i)+res;
    }
    return res;
}
//定义有关线段树的操作
NODE *create_node(int start,int end,int sum){
    NODE *node = new NODE;
    node->start = start;
    node->end = end;
    node->sum = sum;
    return node;
}
int init_tree(NODE *a,int dep){
    int next = pow(2, dep+1);
    int cur = pow(2, dep);
    if(dep == 0){
        //根节点处理 todo
        a[cur] = *create_node(a[next].start,a[next+1].end,(a[next].sum+a[next+1].sum));
        return 0;
    }else{
        //处理本层节点
        for(int i=0;i<cur;i++){
            a[cur+i] = *create_node(a[next+i*2].start,a[next+1+i*2].end,(a[next+i*2].sum+a[next+1+i*2].sum));
        }
        dep -= 1;
        init_tree(a, dep);
    }
    return 0;
}

int query(NODE *a,int m,int n,int root){
    int res(0);
    NODE rootnode = a[root];
    int mid = (rootnode.start+rootnode.end)/2;
    if(m==rootnode.start && n == rootnode.end){
        res = rootnode.sum;
    }else if(n<=mid){//都在左边
        res  = query(a, m, n, 2*root);
    }else if(m>mid){//都在右边
        res = query(a, m, n, 2*root+1);
    }else{
        res = query(a, m,mid, 2*root)+query(a,mid+1, n, 2*root+1);
    }
    return res;
}

int answerQ(NODE *a,int m,int n){
    return query(a,m, n,1);
}

int main(){
    int N,M,n,m,totalLength;
    char enter;
    scanf("%d %d",&N,&M);
    scanf("%c",&enter);
    
    dep = pre_dep(N);
    totalLength = pre_length(dep);
    NODE *a = new NODE [totalLength+1];
    int yeap = pow(2, dep);
    
    for(int i = yeap;i<=totalLength;i++){
        int value;
        if(i-yeap<N){
            scanf("%d",&value);//叶节点
            a[i] =  *create_node(i-yeap+1, i-yeap+1, value);
        }else{
            a[i] = *create_node(i-yeap+1, i-yeap+1, 0);
        }
    }
    scanf("%c",&enter);
    //pre 构建线段树
    init_tree(a,dep-1);
    for(int i = 1;i<=M;i++){
        scanf("%d %d",&m,&n);
        scanf("%c",&enter);
        printf("%d\n",answerQ(a, m, n));
    }
    
    return 0;
}