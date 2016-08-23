//#include <iostream>
//
//using namespace std;
//int main(){
//    int i,n,max,temp;
//    cin>>n;
//    int num[n];
//    for (i=0;i<n;++i)
//        cin>>num[i];
//    max = temp = num[0]+num[1];
//    
//    for (i=2;i<n;++i) {
//        
//        temp = temp > num[i-1] ?
//        temp     + num[i] :
//        num[i-1] + num[i];
//        if (max<temp)
//            max = temp;
//    }
//    
//    if (max>0) cout<<max;
//    else cout<<"Game Over";
//    
//    return 0;
//}