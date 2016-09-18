//
//  sortchar.cpp
//  uoj
//
//  Created by admos on 16/9/15.
//  Copyright © 2016年 admos. All rights reserved.
//使用冒泡排序

//#include <stdio.h>
//#include <iostream>
//
//using std::cin;
//using std::cout;
//using std::endl;
//
//int main(){
//    int n(0);
//    char enter;
//    scanf("%d",&n);
//    scanf("%c",&enter);
//    for (int i = 0; i<n; i++) {
//        char letter('0');
//        char group[3]={'0'};
//        for (int j = 0; j<3; j++) {
//            scanf("%c",&letter);
//            group[j] = letter;
//        }
//        scanf("%c",&enter);
//        for (int j = 0; j<2; j++) {
//            for(int k = 0;k<2;k++){
//                if (group[k]-'0'>group[k+1]-'0') {
//                    char tem;
//                    tem = group[k];
//                    group[k] = group[k+1];
//                    group[k+1] = tem;
//                }
//            }
//        }
//        cout<<group[0]<<" "<<group[1]<<" "<<group[2]<<endl;
//    }
//    return 0;
//}
