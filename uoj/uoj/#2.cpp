//
//  #2.cpp
//  uoj
//
//  Created by admos on 16/9/7.
//  Copyright © 2016年 admos. All rights reserved.
//

#include <iostream>
#include <string.h>
//#include "gtest/gtest.h"
//注意整型溢出 int 溢出到 unsinged int
//注意数组长度的分配！是m+1 而不是 m

using std::cin;
using std::cout;
using std::endl;


int main(int argc,char* argv[]){
    int n(0),m(0);
    cin>>n>>m;
    m = m+1;
    unsigned int* arr = new unsigned int[m];
    for (int i=0; i<n; i++) {
        char op[4];
        int t;
        cin>>op>>t;
        
        if(i == 0){
            for(int j= 0;j<m;j++){
                arr[j] = j;
            }
        }
        
        if(t ==0){
            
        }
        //
        for (int j = 0; j<m; j++) {
            if(op[0] == 'A'){arr[j] = arr[j] & t;}
            if(op[0] == 'O'){arr[j] = arr[j] | t;}
            if(op[0] == 'X'){arr[j] = arr[j] ^ t;}
        }
    }
    //
    unsigned int best(0);
    for (int j = 0; j < m; j++) {
        if(j == 0){best = arr[j];}
        arr[j]>best?best=arr[j]:best;
    }
    cout<<best<<endl;
    return 0;
}
