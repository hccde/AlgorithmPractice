//#35
//迭代器 next 保持状态，遇到括号等突变，先考虑最简单的情况 1+2 ,然后考虑括号，是否可以用递归解决

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef enum type{
    number=1,
    symbol,
    leftbracket,
    rightbracket
} TYPE;
//状态
typedef struct state{
    TYPE type;
    char colloct[65];
    int pointer;
} STATE;

typedef struct nstack{
    double stack[1000];
    int pointer;
} NSTACK;

typedef struct sstack{
    char stack[1000];
    int pointer;
} SSTACK;

static STATE state;

TYPE get_type(char letter){
    TYPE type;
    if(letter == '+'||letter == '-'||letter == '*'||letter == '/'||letter == '='){type = symbol;return type;}
    if(letter == '('){type = leftbracket;return type;}
    if(letter == ')'){type = rightbracket;return type;}
    type = number;
    return type;
}
//执行两个数计算的函数
double execcompute(char sym,double noee,double noer){// = 不会进来，因为没有边缘
    double result(0);
    if (sym == '+') {return noee+noer;}
    if (sym == '-') {return noee-noer;}
    if (sym == '*') {return noee*noer;}
    if (sym == '/') {return noee/noer;}
    return result;
}
//
double compute(NSTACK *nostac,SSTACK *symstack){
    double result;
    if(nostac->pointer == 1){//到栈底了
        result =  nostac->stack[0];
    }else{
//        symstack->pointer-=1;
//        symstack->stack[symstack->pointer];//符号出栈
        //数字出栈两个
        nostac->stack[nostac->pointer-2] = execcompute(symstack->stack[symstack->pointer-1],nostac->stack[nostac->pointer-2],nostac->stack[nostac->pointer-1]);
        nostac->pointer -=1;
        symstack->pointer -=1;
        result = compute(nostac, symstack);//递归计算自己
    }
    return result;
}

//
int dispatch_handle(TYPE type,NSTACK *nostack,SSTACK *symstack){//type是新字符的类型
    switch (state.type) {
        case number:
            if(type == symbol){
                state.colloct[state.pointer] = '\0';
                nostack->stack[nostack->pointer] = atof(state.colloct);
                nostack->pointer+=1;
            }else if(type == rightbracket){
                //遇到右括号 ，相当于回车
            }
            break;
        case symbol:
            if(type == number){
                symstack->stack[symstack->pointer] = state.colloct[0];
                symstack->pointer+=1;
            }else if (type == leftbracket){
                //遇到左括号，开始考虑递归，注意state
            }
            break;
        case leftbracket:
            ;
            break;
        case rightbracket:
            ;
            break;
        default:
            //state.type为0是初始状态，收集即可
//            state.type = type;
//            return -1;
            break;
    }
    return 0;
}
//消费者
int  consum(char letter,NSTACK *nostack,SSTACK *symstack){
    TYPE type = get_type(letter);
        if(type != state.type){//边缘触发
//            if(dispatch_handle(type,nostack,symstack) == -1){break;}
            dispatch_handle(type,nostack,symstack);
            state.colloct[0] = letter;
            state.pointer = 1;
            state.type = type;
            return 0;
    }
    state.colloct[state.pointer] = letter;
    state.pointer +=1;
    return 0;
}
//输入
double input(){
    char letter('0');
    NSTACK number;
    SSTACK sym;
    number.pointer = 0;
    sym.pointer = 0;
    while (1) {
        scanf("%c",&letter);
        if(letter == '\n'){break;}
        //中缀表达式变为后缀 然后再用栈计算
        consum(letter,&number,&sym);
    }
    return compute(&number,&sym);
}

int main(){
    
    char enter;
    int n;
    scanf("%d%c",&n,&enter);
    
    //状态
    for(int i = 0;i<n;i++){
        printf("%.2f",input());
    }
    
    return 0;
}