//
//  #24.cpp
//  uoj
//
//  Created by admos on 2016/10/7.
//  Copyright © 2016年 admos. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

bool isPrime(int num){
    int i = 3;
    bool res(true);
    if( num == 2||num == 3){return true;}
    if(num % 2 == 0 || num == 1){return false;}
    
    while (i <= sqrt(num)) {
        if(num % i == 0){
            res = false;
            break;
        }
        i = i+2;
        
    }
    return res;
}
int move(int num,int step){
    if(isPrime(num)){
        return num;
    }else{
        if(isPrime(num+step)){return num+step;}
        if(step<0){
            step = -step;
            return move(num,step);
        }else{
            step = (-step)+2;
            return move(num,step);
        }
    }
}

int main(){
    int num(0);
    int step(0);
    int N(0);
    scanf("%d",&N);
    
    for(int i = 0;i<N;i++){
        scanf("%d",&num);
        step = -(num % 2 +1);
        int nearest = move(num,step);
        printf("%d %d\n",nearest,abs(num-nearest));
    }
    return 0;
}
