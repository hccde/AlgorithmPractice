////
////  #93.cpp
////  uoj
////
////  Created by admos on 16/9/21.
////  Copyright © 2016年 admos. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//typedef struct stack{
//    int size;
//    int stack[64];
//    int pointer;
//} STACK;
//
//STACK* stack_init(){
//    STACK *stack = new STACK;
//    stack->pointer = -1;
//    stack->size = 0;
//    return stack;
//}
//
//int stack_pop(STACK *stack){
//    if(stack->size == 0){return -1;}//cout<<"stack is empty"<<endl;
//    int re = stack->stack[stack->pointer];
//    stack->size-=1;
//    stack->pointer-=1;
//    return re;
//}
//
//int stack_push(STACK *stack,int value){
//    if(stack->size >= 64){cout<<"stack is full"<<endl;return -1;}
//    stack->pointer +=1;
//    stack->size +=1;
//    stack->stack[stack->pointer] = value;
//    return stack->pointer;
//}
//
//bool stack_clear(STACK *stack){
//    bool flag(false);
//    stack->pointer = 0;
//    stack->size = 0;
//    return flag;
//}
//void create(STACK *needle[],int p){
//    int i = 0;
//    while (i<3) {
//        needle[i] = stack_init();
//        i = i+1;
//    }
//}
//void init(STACK *needle,int p){
//    for(int i=p-1;i>=0;i--){
//        stack_push(needle, i);//大片在下小片在上
//    }
//}
//
//bool exec(int fir,int sec, STACK *needle[]){
//    bool re(true);
//    int tem = stack_pop(needle[fir]);
//    if(tem < 0){re = false;return re;};
//    int secTop = stack_pop(needle[sec]);
//    if(secTop!=-1 && secTop < tem){
//        re = false;return re;
//    }
//    stack_push(needle[sec], secTop);
//    stack_push(needle[sec], tem);
//    return re;
//}
//
//int main(){
//    int N,P,Q;
//    char enter;
//    STACK *needle[3];
//    scanf("%d",&N);
//    scanf("%c",&enter);
//    create(needle,P);
//    for(int i=0;i<N;i++){
//        scanf("%d %d",&P,&Q);
//        scanf("%c",&enter);
//        init(needle[0],P);
//        stack_clear(needle[1]);
//        stack_clear(needle[2]);
//        
//        int cp(1),fir,sec;
//        bool flag(true);
//        while(cp<= Q){
//        scanf("%d %d",&fir,&sec);
//        if(!exec(fir-1, sec-1, needle)){
//            flag = false;
//        }
//        cp = cp+1;
//    }
//    flag?cout<<"legal"<<endl:cout<<"illegal"<<endl;
//    }
//    return 0;
//}