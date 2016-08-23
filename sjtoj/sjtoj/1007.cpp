#include <iostream>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;

int length(char arr[]){
    int lens= 0;
    for(int i = 0;1;i++){
        if(arr[i] == '\0'){
            lens = i;
            break;
        }
    }
    return lens;
}

void reverse(char arr[]){
    int lengths =  length(arr);
    int save[250];
    for (int i = 0; i<lengths; i++) {
        save[i] = arr[lengths-1-i];
    }
    for(int i = 0;i<lengths;i++){
        arr[i] = save[i];
    }
}

int map(char letter){
    switch (letter) {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            break;
    }
    return 0;
}

void sum(char adder[],char addee[],char result[]){
    int adderlens = length(adder);
    int addeelens = length(addee);
    int maxValue = std::max(addeelens,adderlens);
    int flag = 0;
    for (int i = 0; i<maxValue; i++) {
        int tem;
        if(adder[i] != '.'){
            tem = map(addee[i]) + map(adder[i]);
            if(tem >= 10){
                tem = tem / 10;
                result[i] = (tem+flag) + '0';
                flag = 1;
            }else{
                result[i] = (tem+flag) + '0';
                flag = 0;
            }
        }
        else{
            result[i] = '.';
        }
    }
    reverse(result);
}

int main(){
    char last[250];
    char now[250];
    char result[255];
    
    cin>>last;
    cin>>now;

    reverse(last);
    sum(last,now,result);
    
    cout<<result<<endl;

    return 0;
}