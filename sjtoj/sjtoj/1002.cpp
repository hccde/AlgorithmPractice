////
////  main.cpp
////  sjtoj
////
////  Created by admos on 16/8/10.
////  Copyright © 2016年 admos. All rights reserved.
////
//
////有两条测试用例没过
//
//#include <iostream>
//#include <stdio.h>
//
//using std::cin;
//using std::cout;
//using std::endl;
//
// int l(0),w(0);
// int L(0),W(0);
// int best(0);
//
//inline int* tem(int start,int list[],int area[]){
//    for(int i=0;i<l;i++){
//        list[i]= 0;
//        for(int j=0;j<w;j++){
//            list[i] = list[i]+area[(j+start)*L+i];
//        }
//    }
//    return  list;
//    
//}
//
//inline int* move(int startw,int startl,int list[],int area[]){
//    int newele = 0;
//    for(int i=0;i<w;i++){
//        int temres = startl+l-1;
//        newele = newele+area[(i+startw)*L+temres];
//    }
//    //调整
//    for (int i=1; i<l; i++) {
//        list[i-1]=list[i];
//    }
//    list[l-1] = newele;
//    
//    return list;
//}
//
//inline int compare(int list[],int best){
//    int cache(0);
//    for(int i=0;i<l;i++){
//        cache = list[i]+cache;
//    }
//    cache>best?best=cache:best;
//    return best;
//}
//
//int main(){
//    cin>>W>>L;
//    int area[1001*1001];
//    
//    for(int i=0;i<W;i++){
//        for(int j=0;j<L;j++){
////            cin>>area[i*L+j];
//            scanf("%d", &area[i*L+j]);
//        }
//    }
//    
//    cin>>w>>l;
//    
//    int list[1001];
//    for(int i=0;i<=W-w;i++){
//        tem(i,list,area);
//        best = compare(list,best);
//        
//        for (int j=1; j<=L-l; j++) {
//            move(i,j,list,area);
//            best = compare(list,best);
//        }
//    }
//    
//    cout<<best<<endl;
//    return 0;
//}