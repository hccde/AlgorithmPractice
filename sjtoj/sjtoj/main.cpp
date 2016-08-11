//
//  main.cpp
//  sjtoj
//
//  Created by admos on 16/8/10.
//  Copyright © 2016年 admos. All rights reserved.
//

#include <iostream>
using namespace std;
int* templeSum(int **p,int sizew,int sizel,int *save,int w,int l){
    int *result = new int [sizel+1];
    int n=0;
    
    result[sizel]=0;
    //求和
    if(*save!=-1){
        save[sizel]= save[sizel]-save[0];
        for(int t=0;t<sizel-1;t++){
            *(result+t) = save[t+1];
        }
        *(result+sizel) = save[sizel];
        n = sizel-1;
    }
    int colSum;
    
    for(;n<sizel;n++){
        colSum=0;
        for(int m=0;m<sizew;m++){
            colSum = *(*(p+w+m)+l+n)+colSum;
        }
        *(result+n)=colSum;
        *(result+sizel) = *(result+sizel)+colSum;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    //读取
    
    int w,l;
    cin>>w>>l;
    const int L =l;
    int **width = new int *[w];
    int *length;
    int  sizel,sizew;
    
    for(int i=0;i<w;i++){
        length = new int[L];
        for(int j=0;j<l;j++){
           cin>> *(length+j);
        }
        *(width+i)= length;
    }
    cin>>sizel>>sizew;
   
    // 计算
    int best =0;
    for(int m=0;m<w-sizew+1;m++){
        int arrs[1];
        int *arr = arrs;
        *arr = -1;//flag

        for(int n=0;n<l-sizel+1;n++){
                arr = templeSum(width,sizew,sizel,arr,m,n);
                *(arr+sizel)>best?best=*(arr+sizel):best;
        }
        if(m>0){
            delete arr;
        }
    }
    
//    输出
    cout<<best<<endl;
    //clear
    delete []width;
    return 0;
}
