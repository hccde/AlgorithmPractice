//#include <iostream>
//
//using   std::cin;
//using   std::cout;
//using   std::endl;
//
//
//void reproduce(int n,int *dishes,int (*germ)[2],int germPointer,int length){
//    int (*newgerm)[2] = new int [length*length][2];
//    int newgermPointer(0);
//    for(int i=0;i<germPointer;i++){
//        int x = germ[i][0];
//        int y = germ[i][1];
//        int flag(0);
//        //down
//        if(x+1<length){
//            if(dishes[(x+1)*length+y]==0){
//                flag=1;
//                dishes[(x+1)*length+y] = 1;
//                
//                newgerm[newgermPointer][0]= x+1;
//                newgerm[newgermPointer][1]= y;
//                 newgermPointer = newgermPointer+1;
//            }
//
//        }
//        //up
//        if(x-1>=0){
//            if(dishes[(x-1)*length+y]==0){
//                 flag=1;
//                dishes[(x-1)*length+y]=1;
//                
//                
//                newgerm[newgermPointer][0]= x-1;
//                newgerm[newgermPointer][1]= y;
//                 newgermPointer = newgermPointer+1;
//            }
//
//        }
//        //left
//        if(y+1<length){
//            if(dishes[x*length+y+1]==0){
//                 flag=1;
//                dishes[x*length+y+1]=1;
//                
//                newgerm[newgermPointer][0]= x;
//                newgerm[newgermPointer][1]= y+1;
//                 newgermPointer = newgermPointer+1;
//            }
//        }
//        //right
//        if(y-1>=0){
//            if(dishes[x*length+y-1]==0){
//                 flag=1;
//                dishes[x*length+y-1]=1;
//                
//                newgerm[newgermPointer][0]= x;
//                newgerm[newgermPointer][1]= y-1;
//                 newgermPointer = newgermPointer+1;
//            }
//        }
//        
//    }
//    delete []germ;germ=NULL;
//    if(newgermPointer==0){//再也没有新增加的了
//        cout<<n<<endl;
//    }else{
//        reproduce(n+1, dishes, newgerm, newgermPointer,length);
//    }
//}
//
//
//
//int  main(){
//    int length;
//    cin>>length;
//    //二维数组
//    int dishes[length*length];
//    int (*germ)[2] = new int [length*length][2];
//    int germPointer(0);
//
//    for(int i=0;i<length;i++){
//        int num(0);
//        for(int j=0;j<length;j++){
//            cin>>num;
//            if(num==1){
//                *(*(germ+germPointer)) =i;*(*(germ+germPointer)+1)=j;
//                germPointer = germPointer+1;
//            }
//            dishes[i*length+j] = num;
//        }
//    }
//    int n(0);
//
//    reproduce(n, dishes, germ, germPointer,length);
//    return 0;
//}
//
//
//
//
