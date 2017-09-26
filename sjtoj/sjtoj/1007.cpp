#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Number{
private:
	string value;
public:
	Number(string val):value(val){

	}
	Number(const char* val):value(val){

	}
	Number(){
		value = "0.00";
	}
	string getValue() const{
		return value;
	}
	friend Number operator+(const Number& lv,const Number& rv);
	friend ostream& operator<<(ostream& cout,const Number& val);
};



Number operator+ (const Number& lv,const Number& rv){
	string lvs = lv.getValue();
	int lv_length = lvs.size();
	string rvs = rv.getValue();
	int rv_length = rvs.size();

	unsigned short int flag(0); //进位
	char result[202];
	char temp[202];
	unsigned short int res;

	string max_length_str;
	string min_length_str;
	int min_length;
	int length;

	if(lv_length>rv_length){
		length = lv_length;
		min_length = rv_length;
		max_length_str = lvs;
		min_length_str = rvs;
	}else{
		length = rv_length;
		min_length = lv_length;
		max_length_str = rvs;
		min_length_str = lvs;
	}

	strcpy(result,max_length_str.c_str());
	strcpy(temp+(length-min_length),min_length_str.c_str());

	for(int i=length-1,j=0;i>=0;i--,j++){
		if(i == length-3){
			result[i] = '.';
			continue;
		}
		if(j< min_length){
			res =  (unsigned short int)result[i]-48 + (unsigned short int)temp[i]-48+flag;
			if(res>=10){flag = 1;res-=10;}else{flag = 0;}
			// cout<<res<<endl;
			result[i] = res+48;
		}else{
			if(flag>0){
				unsigned short int tem = (unsigned short int)result[i]-48 + flag;
				if(tem>10){
					flag = 1;
					tem-=10;
				}else{
					flag = 0;
				}
				result[i] = tem+48;

			}else{
				break;
			}
		}
	}
	char sum_number[202];

	if(flag>0){
		sum_number[0] = '1';
		strcpy(sum_number+1,result);

		return Number(sum_number);
	}else{
		return Number(result);
	}
}

ostream& operator<<(ostream& cout,const Number& val){
	cout<<val.getValue()<<endl;
	return cout;
}

int main()
{ 	
	char add[202];
	char added[202];
	cin>>add>>added;
	Number t(added);
	Number s(add);
	cout<< s+t <<endl;
	return 0;	
}