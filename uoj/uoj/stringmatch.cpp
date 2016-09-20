////
////  stringmatch.cpp
////  uoj
////
////  Created by admos on 16/9/17.
////  Copyright © 2016年 admos. All rights reserved.
////连续匹配的KMP算法
////对于char字符数组，定义一个数据结构 char[0] = length，最后一位放 '\0'
////因为是char数组，length在使用的时候注意要转换为int型，使用结构体更恰当，不容易错
//
//#include <stdio.h>
//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//typedef struct charstr {
//    int length;
//    char arr[1000];
//} CHARSTR;
//
//int match(CHARSTR *str,CHARSTR *strchild,int nextarr[]){
//    int count(0);
//    int length = str->length;
//    int child_length = strchild->length;
//    //移动子串
//    int j = 1;
//    for(int i=1;i<=length;){
//        bool ismatch(true);
//        for(;j<=child_length;j++){
//            if(str->arr[i+j-1]!=strchild->arr[j]){//不匹配
//                ismatch = false;
//                int offset = (j-1-nextarr[j-1]);
//                j = j-offset;
//                offset = offset>0?offset:1;
//                i = i+offset;
//                break;
//            }else{
//                //当前位匹配
//            }
//        }
//        //完全匹配
//        if(ismatch){
//            //为下次匹配做准备
//        int offset = (child_length-nextarr[child_length]);
//        j = j -offset;
//        offset = offset>0?offset:1;
//        i = i+offset;
//        count = count+1;
//        }
//    }
//    return count;
//}
//
//int each_next(CHARSTR *str,int cur){//cur == length
//    int common(0);
//    for (int i = (cur-1); i >= 1; i--) {//前缀
//        bool flag(true);
//        for (int j = 1; j<=i; j++) {
//            if(str->arr[j] != str->arr[cur-i+j]){
//                flag = false;
//                common = 0;//不相同
//                break;
//            }
//            common = common+1;//计算共有长度
//        }
//        if(flag){break;}//找到相同的元素,common已经计算出
//    }
//    return common;
//}
//
//void next(CHARSTR *strchild,int nextarr[]){
//    int length = strchild->length;
//    for (int i = 1; i<=length; i++) {
//        nextarr[i] = each_next(strchild,i);
//    }
//}
//
//void input(CHARSTR *str){
//    for(int j = 1;j<1001;j++){
//        char letter('0');
//        scanf("%c",&letter);
//        if(letter == '\n'){
//            str->length = (j-1);
//            break;
//        }
//        str->arr[j] = letter;
//    }
//}
//
//int main(){
//    int n(0);
//    char enter;
//    scanf("%d",&n);
//    scanf("%c",&enter);
//    int* result = new int[n];
//    CHARSTR strchild;
//    CHARSTR str;
//    for (int i = 0; i<n; i++) {
//        input(&strchild);
//        input(&str);
//        int nextarr[11]={0};//与字符串数据结构一致
//        next(&strchild,nextarr);
//        result[i] =match(&str,&strchild,nextarr);
////        cout<<match(str,strchild,nextarr)<<endl;
//    }
//    
//    for(int i = 0;i<n;i++){
//        if(i == n-1){
//            cout<<result[i];
//        }else{
//            cout<<result[i]<<endl;
//        }
//        
//    }
//    delete []result;
//    return 0;
//}