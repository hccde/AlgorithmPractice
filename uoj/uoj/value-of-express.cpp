////#35
////迭代器 next 保持状态，遇到括号等突变，先考虑最简单的情况 1+2 ,然后考虑括号，是否可以用递归解决
////space的状态考虑进去
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//typedef enum type{
//    number=1,
//    symbol,
//    leftbracket,
//    rightbracket,
//    space
//} TYPE;
////状态
//typedef struct state{
//    TYPE type;
//    char colloct[65];
//    int pointer;
//} STATE;
//
//typedef struct nstack{
//    double stack[1001];
//    int pointer;
//} NSTACK;
//
//typedef struct sstack{
//    char stack[2001];
//    int pointer;
//} SSTACK;
//
////
//int ss_push(SSTACK *sstack,char letter){
//   
//        sstack->pointer+=1;
//        sstack->stack[sstack->pointer] = letter;
//        return sstack->pointer;
//}
//
//char ss_pop(SSTACK *sstack){
//    char result;
//    result = sstack->stack[sstack->pointer];
//    sstack->pointer -=1;
//    return result;
//}
//
//int no_push(NSTACK *notack,double letter){
//    
//    notack->pointer+=1;
//    notack->stack[notack->pointer] = letter;
//    return notack->pointer;
//}
//
//double no_pop(NSTACK *notack){
//    double result;
//    result = notack->stack[notack->pointer];
//    notack->pointer -=1;
//    return result;
//}
//
//char ss_get_top(SSTACK *sstack) {
//    int pointer = sstack->pointer;
//    if(pointer == -1){
//        return '+';
//    }
//    return sstack->stack[pointer];
//}
//
//
//
//static STATE state;
//
//TYPE get_type(char letter){
//    TYPE type;
//    if(letter == '+'||letter == '-'||letter == '*'||letter == '/'||letter == '='){type = symbol;return type;}
//    if(letter == '('){type = leftbracket;return type;}
//    if(letter == ')'){type = rightbracket;return type;}
//    if(letter == ' '){type = space;return type;}
//    type = number;
//    return type;
//}
////执行两个数计算的函数
//double execcompute(char sym,double noee,double noer){// = 不会进来，因为没有边缘
//    double result(0);
//    if (sym == '+') {result = noee+noer;}
//    if (sym == '-') {result = noee-noer;}
//    if (sym == '*') {result =  noee*noer;}
//    if (sym == '/') {result =  noee/noer;}
//    return result;
//}
////
//double compute(NSTACK *nostac,char symbol){
//    double result(0);
//        double er = no_pop(nostac);
//        double ee = no_pop(nostac);
//        no_push(nostac,execcompute(symbol, ee, er));//
//    return result;
//}
//
////
//int dispatch_handle(TYPE type,NSTACK *nostack,SSTACK *symstack){//type是新字符的类型
//    switch (state.type) {
//        case number:
//            if(type == symbol||type == space){
//                state.colloct[state.pointer] = '\0';
////                cout<<atof(state.colloct)<<"number"<<endl;
//                no_push(nostack,atof(state.colloct));
//            }else if(type == rightbracket){
//                //遇到右括号 ，相当于回车
//            }
//            break;
//        case symbol:
//            if(type == number || type == space){
//                compute(nostack, state.colloct[0]);
//            }else if (type == leftbracket){
//                //遇到左括号，开始考虑递归，注意state
//            }
//            break;
//        case leftbracket:
//            ;
//            break;
//        case rightbracket:
//            ;
//            break;
//        case space:
//            ;
//            break;
//        default:
//            break;
//    }
//    return 0;
//}
////消费者
//int  consum(char letter,NSTACK *nostack,SSTACK *symstack){
//    TYPE type = get_type(letter);
//        if(type != state.type){//边缘触发
////            if(dispatch_handle(type,nostack,symstack) == -1){return 0;}
//            dispatch_handle(type,nostack,symstack);
//            state.colloct[0] = letter;
//            state.pointer = 1;
//            state.type = type;
//            return 0;
//    }
//    if(type == space){return 0;}
//    state.colloct[state.pointer] = letter;
//    state.pointer +=1;
//    return 0;
//}
////功能函数
//bool compare(char letter,char top){
//    bool result(true);
//    if(letter=='+' || letter =='-'){
//        result = top == '+' || top == '-'||top == '('?true:false;
//    }else if (letter == '*' || letter == '/'){
//        result = top == '+' || top == '-'||top == '('?true:false;
//    }
//    return result;//
//}
////中缀表达式转后缀表达式
//static TYPE flagstate = symbol;
//
//int pre_deal(char letter,SSTACK *dealedstack,SSTACK *sym){
//    if(letter == '='){return 0;}
//   TYPE type =  get_type(letter);
////    cout<<letter<<" letter"<<endl;
//    switch (type) {
//        case number:
//            ss_push(dealedstack, letter);
//            flagstate = number;
//            break;
//        case symbol:
//            flagstate == number?ss_push(dealedstack,' '):flagstate=symbol;
//            if(compare(letter,ss_get_top(sym))){//letter 和栈顶优先级
//                ss_push(sym, letter);
//            }else{//letter优先级小于top
//                while(sym->pointer != -1 ){
//                    char test = ss_pop(sym);
//                    if(test == '('){ss_push(sym, '(');break;}
//                    ss_push(dealedstack,test);
//                    ss_push(dealedstack,' ');
//                }
//                ss_push(sym, letter);
//            }
//            break;
//        case leftbracket:
//            flagstate == number?ss_push(dealedstack,' '):flagstate=leftbracket;
//            ss_push(sym, letter);
//            break;
//        case rightbracket:
//            flagstate == number?ss_push(dealedstack,' '):flagstate=rightbracket;
//            while(1){
//                char item = ss_pop(sym);
//                if(item == '('){break;}
//                ss_push(dealedstack, item);
//                ss_push(dealedstack,' ');
//            }
//            break;
//        default:
//            break;
//    }
//    return 0;
//}
//
////输入
//double input(){
//    char letter('0');
//    NSTACK number;
//    SSTACK sym;
//    SSTACK dealednumber;
//    
//    dealednumber.pointer = -1;
//    number.pointer = -1;
//    sym.pointer = -1;
//    
//    while (1) {
//        scanf("%c",&letter);
//        if(letter == '\n'){
//            //符号栈中元素全部出栈
//            break;
//        }
//        //中缀表达式变为后缀 然后再用栈计算
//        pre_deal(letter,&dealednumber,&sym);
//    }
//    while(1){
//        if(sym.pointer == -1){break;}
//        ss_push(&dealednumber, ss_pop(&sym));
//        ss_push(&dealednumber, ' ');
//    }
//    ss_push(&dealednumber, '\0');
//    sym.pointer = 0;
//    for(int i = 0;i<=dealednumber.pointer;i++){
//        consum(dealednumber.stack[i],&number,&sym);
//    }
//    return no_pop(&number);
//}
//
//int main(){
//    
//    char enter;
//    int n;
//    scanf("%d%c",&n,&enter);
//    
//    //状态
//    for(int i = 0;i<n;i++){
//        printf("%.2f",input());
//    }
//    
//    return 0;
//}