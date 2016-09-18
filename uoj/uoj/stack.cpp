////
////  stack.cpp
////  uoj
////
////  Created by admos on 16/9/13.
////  Copyright © 2016年 admos. All rights reserved.
////括号匹配
////clear 栈的时候把t栈顶指针变为0，这里设计需要优化，
//
//#include <iostream>
//#include <stdio.h>
//using std::cin;
//using std::cout;
//using std::endl;
//
//class Stack{
//private:
//    char _stack[10000];
//    int _top;
//    
//public:
//    Stack(){
//        for(int i = 0;i<10000;i++){
//            _stack[i] = '0';
//        }
//        _top = 0;
//    }
//    
//    int push(char value){
//        if(isfull()){cout<<"stackoverflow"<<endl;_top=10000;return -1;}
//        _stack[_top+1] = value;
//        _top = _top+1;
//        return _top;
//    }
//    
//    int pop(void){
//        if(isempty()){cout<<"stack is empty"<<endl;_top=0;return -1;}
//        char tem = _stack[_top];
//        _stack[_top] = '0';
//        _top = _top-1;
//        return tem;
//    }
//    
//    bool isfull(void){
//        if(_top >= 10000 ){
//            return true;
//        }else{
//            return false;
//        }
//    }
//    
//    bool isempty(void){
//        if(_top <= 0){
//            return true;
//        }else{
//            return false;
//        }
//    }
//    void clear_stack(){
//        _top = 0;
//        for(int i=0;i<=_top;i++){
//            _stack[i] = '0';
//        }
//    }
//    
//    char get_top(){
//        return _stack[_top];
//    }
//    int get_top_pointer(){
//        return _top;
//    }
//};
//
//bool compare(char value,char compValue){
//    bool isMatch=false;
//    
//    if(value=='('){isMatch = compValue==')'?true:false;}
//    if(value=='['){isMatch = compValue==']'?true:false;};
//    
//    return isMatch;
//}
//
//int main(int argc,char* argv[]){
//    int n(0);
//    char enter;
//    scanf("%d",&n);
//    scanf("%c",&enter);
//    Stack* stack = new Stack();
//    char letter('0');
//    
//    for(int i=0;i<n;i++){
//        while(1){
//            scanf("%c",&letter);
//            if(letter == '\n'){break;}
//            compare(stack->get_top(),letter)?stack->pop():stack->push(letter);
//        }
//        
//        stack->isempty()?cout<<"Yes"<<endl:cout<<"No"<<endl;
//        stack->clear_stack();
//        
//        letter = '0';
//    }
//    
//    return 0;
//
//}
