#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int SUM = 45;
const int MULT = 362880;

int tempSum(int arr[],int i,int j){
    int tem = 0;
    int sum = 0;
    int mult = 1;
    int result = 1;
    for(int n=0;n<3;n++){
        for (int m=0; m<3; m++) {
            tem = arr[(n+j)*9+i+m];
            sum = tem+sum;
            mult = mult*tem;
        }
    }
    if(!(sum == SUM &&mult == MULT)){
        result = 0;
    }
    
    return result;
}

int  tempCheck(int arr[],int resultValue){
    for(int i=0;i<7;){
        for (int j=0; j<7;) {
            resultValue = tempSum(arr, i, j);
            if(!resultValue){
                break;
            }
            j=j+3;
        }
        i =i+3;
    }
    return resultValue;
}

int main(){
    
    int count(0);
    int result[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cin>>count;
    
    for (int k = 0; k<count; k++) {//total sudokuNumber
        int sudoku[81] ={0};
        bool switchButton = true;
        for(int i = 0;i< 9 ;i++){
            
            int rowSum = 0;
            int rowmult = 1;
            for(int j = 0;j<9;j++){
                int tem = 0;
                cin>>tem;
                if(switchButton){
                    sudoku[j+i*9] = tem;
                    rowSum = tem+rowSum;
                    rowmult = tem*rowmult;
                }
            }
            //row
            if(!(rowSum==SUM&&rowmult==MULT)){
                result[k] = 0;
                switchButton = false;
                break;
            }
        }
        
        //col
        if(switchButton){
            for(int n = 0;n<9;n++){
                int colSum = 0;
                int colmult = 1;
                for (int m = 0; m<9; m++) {
                    int tem = sudoku[m*9+n];
                    colmult = colmult*tem;
                    colSum  = colSum + tem;
                }
                if(!(colSum == SUM&&colmult == MULT)){
                    result[k] = 0;
                    switchButton = false;
                    break;
                }
            }
        }
        //temp 3*3
        if(switchButton){
            result[k] = tempCheck(sudoku,result[k]);
        }
    }
    
    for(int i = 0;i<count;i++){
        result[i]?cout<<"Right"<<endl:cout<<"Wrong"<<endl;
    }
    return 0;
}