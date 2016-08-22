#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int SUM = 45;
const int MULT = 362880;

int compare(int num,int numlist[]){
    int result = 0;
    for(int i=0;i<9;i++){
        if(numlist[i] == num){result=1;break;};
    }
    return result;
}

int tempcompare(int arr[],int i,int j){
    int result = 0;
    int numlist[9] = {0};
    for(int n=0;n<3;n++){
        for (int m=0; m<3; m++) {
            int res = 0;
            int tem =0;
            tem = arr[(n+j)*9+i+m];
            res = compare(tem, numlist);
            numlist[n*3+m] = tem;
            if(res){
                result = 1;
                break;
            }
        }
    }
    return result;
}

int temcheckEvery(int arr[]){
    int result = 1;
    for(int i=0;i<7;){
        for (int j=0; j<7;) {
            int res = 0;
            res = tempcompare(arr, i,j);
            if(res){//res == 1 break
                result = 0;
                break;
            }
            j=j+3;
        }
        i =i+3;
    }
    return result;
}

int checkEvery(int arr[]){
    int result = 1;
    bool switchButton =true;
    //row
    for(int i = 0;i< 9 ;i++){
        int temlist[9]={0};
        for(int j = 0;j<9;j++){
            int res=0;
            res = compare(arr[i*9+j], temlist);
            temlist[j] = arr[i*9+j];
            if(res){result=0;switchButton=false;break;}
        }
    }
    
    //col
    if(switchButton){
        for(int i = 0;i< 9 ;i++){
            int temlist[9]={0};
            for(int j = 0;j<9;j++){
                int res;
                res = compare(arr[j*9+i], temlist);
                temlist[j] = arr[j*9+i];
                if(res){result=0;switchButton=false;break;}
            }
        }
    }
    
    //tem
    if (switchButton) {
        result = temcheckEvery(arr);
    }
    return result;
}

int main(){
    
    int count(0);
    int result[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cin>>count;
    
    for (int k = 0; k<count; k++) {//total sudokuNumber
        int sudoku[81] ={0};
        bool switchButton = true;
        for(int i = 0;i< 9 ;i++){
            for(int j = 0;j<9;j++){
                int tem = 0;
                cin>>tem;
                if(switchButton){
                    sudoku[j+i*9] = tem;
                }
            }
        }

        
        if(1){
           result[k] =  checkEvery(sudoku);
        }
    }
    
    for(int i = 0;i<count;i++){
        result[i]?cout<<"Right"<<endl:cout<<"Wrong"<<endl;
    }
    return 0;
}