//
//  #3.cpp
//  uoj
//
//  Created by admos on 16/9/13.
//  Copyright © 2016年 admos. All rights reserved.
//

//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main(int argc,char* argv[]){
//    int n(0),m(0);
//    cin>>n>>m;
//    
//    int* polynomialer = new int[n+1];
//    int* polynomialee = new int[m+1];
//    int* result = new int[n+m+2];
//
//    //init
//    for(int i = 0;i<n+m+2;i++){
//        result[i] = 0;
//    }
//    //input
//    for (int i = 0; i<= n; i++) {
//        cin>>polynomialer[i];
//    }
//    for (int i = 0; i<= m; i++) {
//        cin>>polynomialee[i];
//    }
//    
//    //test input
////    for (int i = 0; i<= n; i++) {
////        cout<<polynomialer[i]<<"  ";
////    }
////    for (int i = 0; i<= m; i++) {
////        cout<<polynomialee[i]<<"  ";
////    }
//    
//    //compute
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=m;j++){
//            result[i+j] = polynomialer[i]*polynomialee[j]+result[i+j];
//        }
//    }
//    
//    //remove 0 in end
//    int flag(0);
//    for(int i = n+m+1;i>=0;i--){
//        if(result[i]!=0){
//            flag = i;
//            break;
//        }
//    }
//    
//    //test output
//    for (int i = 0; i<=flag; i++) {
//        cout<<result[i]<<" ";
//    }
//    
//    
//    return 0;
//}
