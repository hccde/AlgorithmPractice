////
////  #117.cpp
////  uoj
////
////  Created by admos on 2016/9/27.
////  Copyright © 2016年 admos. All rights reserved.
////逆序数
////归并
//
//#include <stdio.h>
//#include <iostream>
//
//using std::cin;
//using std::cout;
//using std::endl;
//
//void prinarray(int len,int *arr){
//    for (int i = 0; i<len; i++) {
//        cout<<arr[i]<<"  测试 "<<endl;
//    }
//}
//
//static int step = 100;
//static int total = 0;
//
//int  domerge(int *mergearray,int *lastarray,int lastlen,int *array,int len){
//    if(lastarray == NULL){
//        for(int i = 0;i<len;i++){
//            mergearray[i] = array[i];
//        }
//        return 0;
//    }
//    int newlen(0);
//    int j = 0;
//    for(int i = 0;i<lastlen;i++){
//        for(;j<len;j++){
//            if(lastarray[i]<array[j]){
//                mergearray[newlen] = lastarray[i];
//                newlen+=1;
//                break;
//            }else{
//                mergearray[newlen] = array[j];
//                newlen+=1;
//            }
//        }
//        mergearray[newlen] = lastarray[i];
//        newlen+=1;
//    }
//
//    if(j<len){
//        for(int i = j;i<len;i++){
//            mergearray[newlen] = array[i];
//            newlen+=1;
//        }
//    }
//    return 0;
//}
//
//int findcout(int lastarray[],int array[],int len,int lastlen){
//    int res(0);
//    
//    for(int i = 0;i<len;i++){
//        for(int j = 0;j<lastlen;j++){
//            if(array[i]<lastarray[j]){
//                res+=1;
//            }
//        }
//    }
//    return res;
//}
//
//int *merge(int lastarray[],int array[],int len,int *lastlen){
//    int *mergearray = new int[len+(*lastlen)];
//    //找到逆序数
//    total+=findcout(lastarray,array,len,*lastlen);
//    //数组合并
//   domerge(mergearray,lastarray,*lastlen,array,len);
//    
//    //更新lastlen
//    *lastlen = *lastlen+len;
//    
//    prinarray(*lastlen, mergearray);
//    cout<<" --- "<<endl;
////    cout<<len<<" len "<<*lastlen<<" lastlem"<<endl;
//    return mergearray;
//}
//
//int *get_big_array(int *array){
//    int *newarray = new int [step+100];
//    for (int i = 0; i<step; i++) {
//        newarray[i] = array[i];
//    }
//    step +=100;
//    return newarray;
//}
//
//int main(){
//    int N(0);
//    //test
//    N = 5;
////    scanf("%d",&N);
//    int num(0);
//    int lastnum = -1;
//    int lastlen = 0;
//    int *lastarray = NULL ;
//    int *array = new int[step];
//    int len(0);
//    for (int i = 0; i<N; i++) {
//        scanf("%d",&num);
//        //判断辅助数组未满
//        if(len<100){
//            if(num>lastnum){
//                lastnum = num;
//                array[len] = num;
//                len+=1;
//            }else{
//            //出现逆序
//            //归并当前和上一个数组
//                //lastlen的值在merge中更新
//                lastarray = merge(lastarray,array,len,&lastlen);
//                len = 0;
//                lastnum = num;
//            //覆写当前数组
//                array[len] = num;
//                len +=1;
//            }
//        }else{
//            //辅助数组满了
//            //更换更大的数组
//            array = get_big_array(array);
//        }
//        
//    }
//    // 归并最后一次
//    lastarray =  merge(lastarray, array, len, &lastlen);
//    
//    //test
//     for(int i = 0;i<N;i++){
//        cout<<lastarray[i]<<" mergearr"<<endl;
//    }
//    
//    cout<<total<<" total"<<endl;
//    //注意清除分配的数组 TODO
//    return 0;
//}