//#include <iostream>
//#include <stdio.h>
//using std::cin;
//using std::cout;
//using std::endl;
//
//typedef struct Number {
//    char pointLeft[250];
//    char pointright[250];
//} Number;
//int length(char arr[]){
//    int lens= 0;
//    for(int i = 0;1;i++){
//        if(arr[i] == '\0'){
//            lens = i;
//            break;
//        }
//    }
//    return lens;
//}
//
//char* reverse(char arr[]){
//    int lengths =  length(arr);
//    int save[250];
//    for (int i = 0; i<lengths; i++) {
//        save[i] = arr[lengths-1-i];
//    }
//    
//    for(int i = 0;i<lengths;i++){
//        arr[i] = save[i];
//    }
//    arr[lengths] = '\0';
//    return arr;
//}
//
//void pushin (char arr[],char value){
//    int lens = length(arr);
//    arr[lens] = value;
//    arr[lens+1] = '\0';
//}
//
//void newNumber(char arr[],Number *number){
//    int flag = 0;
//    int lens = length(arr);
//    for(int i = 0;i<lens;i++){
//        if(arr[i] == '.'){
//            flag = 1;
//            continue;
//        }
//        if(flag){
//            pushin(number->pointright,arr[i]);
//        }else{
//            pushin(number->pointLeft,arr[i]);
//        }
//    }
//}
//
//int maps(char letter){
//    switch (letter) {
//        case '0':
//            return 0;
//            break;
//        case '1':
//            return 1;
//            break;
//        case '2':
//            return 2;
//            break;
//        case '3':
//            return 3;
//            break;
//        case '4':
//            return 4;
//            break;
//        case '5':
//            return 5;
//            break;
//        case '6':
//            return 6;
//            break;
//        case '7':
//            return 7;
//            break;
//        case '8':
//            return 8;
//            break;
//        case '9':
//            return 9;
//            break;
//        default:
//            break;
//    }
//    return 0;
//}
//
//int  sumPart(char adder[],char addee[],char resultpart[],int overflow){
//
//    int adderlens = length(adder);
//    int addeelens = length(addee);
//    int maxvalue = std::max(addeelens,adderlens);
//    int flag = 0;
//    for(int i = 0;i<maxvalue;i++){
//        int tem;
//        if(i == 0){
//            cout<<overflow<<"overflow"<<endl;
//            tem = maps(adder[i]) + maps(addee[i])+overflow;
//        }else{
//            tem = maps(adder[i]) + maps(addee[i])+flag;
//        }
//
//        if(tem >=10){
//            resultpart[i] = tem % 10 +'0';
//            flag = 1;
//        }else{
//            resultpart[i] = tem +'0';
//            flag = 0;
//        }
//    }
//        resultpart[maxvalue] = '\0';
//        return flag;
//}
//
//
//void sum(Number* addee,Number* adder,char result[]){
//
//    char resultright[250]={'\0'},resultleft[250] = {'\0'};
//    int flag(0),overflow(0);//最好的做法，小数点补0
//    flag = sumPart(reverse(addee->pointright), reverse(adder->pointright), resultright, 0);
//    overflow = sumPart(reverse(addee->pointLeft), reverse(adder->pointLeft), resultleft, flag);
//
//    if(overflow){
//      pushin(resultleft,overflow+'0');
//    }
//    reverse(resultleft);
//    reverse(resultright);
//
////    cout<<resultleft<<"resultleft"<<endl;
////    cout<<resultright<<"reslutright"<<endl;
//    
//    int lensleft = length(resultleft);
//    int count = 0;
//    for(int i = 0;i<lensleft;i++){
//        if(resultleft[i] != '0'){
//        result[count] = resultleft[i];
//            count = count+1;
//        }
//    }
//    result[count] = '.';
//    count = count+1;
//    int lensright = length(resultright);
//    for (int i = 0; i<lensright; i++) {
//        if(resultright[i] != '0'){
//            result[count] = resultright[i];
//            count = count+1;
//        }
//    }
//}
//
//int main(){
//    char last[250] = {'\0'};
//    char now[250] = {'\0'};
//    char result[255]={'\0'};
//    
//    cin>>last;
//    cin>>now;
//
//    Number adder,addee;
//    
//    newNumber(last,&adder);
//    newNumber(now,&addee);
//    sum(&adder,&addee,result);
//    cout<<result<<endl;
//    return 0;
//}