//#include <iostream>
//#include <stdio.h>
//using std::cin;
//using std::cout;
//using std::endl;
//
//typedef struct RoadInfo {
//    int m = 0;
//    int t = 0;
//    int u = 0;
//    int f = 0;
//    int d = 0;
//    
//} RoadInfo;
//
//int main(){
//    RoadInfo roadinfo;
//    cin>>roadinfo.m>>roadinfo.t>>roadinfo.u>>roadinfo.f>>roadinfo.d;
//    char segment ='u';
//    
//    int time= 0;
//    int farest =0;
//    bool switchButton = true;
//    for (int i=1; i<=roadinfo.t; i++) {
//        cin>>segment;
//        if(!switchButton) {continue;}
//        
//        segment=='f'?time = time + roadinfo.f*2: time = time + roadinfo.u+roadinfo.d;
//        time<roadinfo.m?farest = i:switchButton=false;
//    }
//    
//    cout<<farest<<endl;
//    return 0;
//}