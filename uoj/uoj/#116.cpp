////
////  #116.cpp
////  uoj
////
////  Created by admos on 2016/9/27.
////  Copyright © 2016年 admos. All rights reserved.
////树状数组
//
//#include <stdio.h>
//#include <iostream>
//
//using std::cin;
//using std::cout;
//using std::endl;
//
//static int N,M;
//
//int getci(int *a,int t){
//    int res(0);
//    int begin = t+1-(t&(-t));
//    for(int i = begin;i<=t;i++){
//        res = res+a[i];
//    }
//    return  res;
//}
//
//void init_tree_array(int *a,int *c){
//    for(int i = 1;i<=N;i++){
//        c[i] =getci(a, i);
//    }
//}
//
//void update(int *c,int t,int addvalue){
//    while (t<=N) {
//        c[t]+=addvalue;
//        t+=t&(-t);
//    }
//}
//
//int getsum(int *c,int t){
//    int res(0);
//    while (t>0) {
//        res+=c[t];
//        t-=t&(-t);
//    }
//    return res;
//}
//
//int main(){
//    int m,n;
//    
//    char enter;
//    
//    scanf("%d %d",&N,&M);
//    int *a = new int[N+1];
//    int *c = new int[N+1];
//    
//    for (int i = 1; i<=N; i++) {
//        scanf("%d",&a[i]);
//    }
//    
//    init_tree_array(a,c);
//    
//    scanf("%c",&enter);
//    
//    //输入指令
//    char cmd[6];
//    for(int i = 1;i<=M;i++){
//        scanf("%s %d %d",cmd,&m,&n);
//        if(cmd[0] == 'A'){//update
//            update(c,m,n);
//        }else{// query
//            if(m != 1){
//                printf("%d\n",getsum(c, n)-getsum(c,m-1));
//            }else{
//                printf("%d\n",getsum(c,n));
//            }
//        }
//    }
//    scanf("%c",&enter);
//    return 0;
//}