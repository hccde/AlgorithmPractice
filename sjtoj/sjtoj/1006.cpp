//#include <iostream>
//
//using std::cin;
//using std::cout;
//using std::endl;
//
//int sum(int arr[],int i,int j){
//    int result = 0;
//    for (int n = i; n<=j; n++) {
//        result = result + arr[n];
//    }
//    return  result;
//}
//
//int main(){
//    int result = -9999;
//    int n= 0;
//    cin>>n;
//    
//    int key[1000000] = {0};
//    //input
//    for (int i = 0; i < n; i++) {
//        cin>>key[i];
//    }
//    
//    for (int i = 0; i < n; i++) {
//        for (int j = (i+1); j < n; j++) {
//            int tem;
//            tem = sum(key,i,j);
//            tem>result?result = tem:result;
//        }
//    }
//    
//    result>0?cout<<result<<endl:cout<<"Game Over"<<endl;
//    return 0;
//}
