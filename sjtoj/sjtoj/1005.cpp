#include <iostream>
using namespace std;
bool vaild(unsigned short int* item[]){
	bool res(false);
	unsigned short int testArray(1);
	unsigned short int testArray2(1);

	for(int i = 0;i<9;i++){
		testArray2 = testArray = 1^1;
		for(int j = 0; j < 9; j++){
			unsigned short int temp = 1;
			temp = temp<<(item[i][j]-1);

			unsigned short int temp2 = 1;
			temp2 = temp2<<(item[j][i]-1);

			testArray =  testArray | temp;
			testArray2 =  testArray2 | temp;
		}
		if(testArray == 511 && testArray ==  511){
		}else{
			return res;
		}
	}
	
	//小矩阵检测
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			testArray = 1^1;
			for(int m = 0;m<3;m++){
				for(int n = 0;n<3;n++){
					unsigned short int temp = 1;
					temp = temp<<(item[i*3+m][j*3+n]-1);
					testArray =  testArray | temp;
				}
			}

			if(testArray == 511){

			}else{
				return res;
			}

		}
	}
	return !res;

}

int main()
{ 

	int count;
	cin>>count;
	for(int i = 0;i<count;i++){
		unsigned short int* item[9];
		for(int m = 0;m < 9; m++){
			unsigned short int* col = new unsigned short int[9];
			for(int n = 0;n < 9; n++){
				cin>>col[n];
			}
			item[m] = col;
		}

		if(vaild(item)){
			cout<<"Right"<<endl;
		}else{
			cout<<"Wrong"<<endl;
		}

		// destory
		for(int j = 0;j<9;j++){
			delete[] item[j];
		}
	}
	return 0;	
}