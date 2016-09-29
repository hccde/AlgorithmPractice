////
////  #22.cpp
////  uoj
////
////  Created by admos on 2016/9/30.
////  Copyright © 2016年 admos. All rights reserved.
////素数筛法--
////算了。题目的意思不适合用筛法
//
//#include <stdio.h>
//#include <math.h>
//
//bool
//isPre(int num){
//    if(num == 1){return false;}
//    bool flag = true;
//    for (int i = 2; i<=sqrt(num); i++) {
//        if(num % i == 0){flag = false;return flag;}
//    }
//    return flag;
//}
//int main(){
//    int M(0);
//    scanf("%d",&M);
//    for (int j = 0; j<M; j++) {
//    int N(0);
//        scanf("%d",&N);
//    int num(0);
//    int sum(0);
//    for (int i = 0; i<N; i++) {
//        scanf("%d",&num);
//        sum = isPre(num)?sum+num:sum;
//    }
//    printf("%d\n",sum);
//    }
//    
//    return 0;
//}