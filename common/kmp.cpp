#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
void log_arr(string arr[]){
	int i = 0;
	while(arr[i] != "\0"){
		cout<<arr[i]<<",";
		i+=1;
	}
}

int get_common_ele(string arr_pre[],string arr_post[],int length){
	string common_ele("");
	for(int i = 0;i<length;i++){
		// arr_pre[i]
		for(int j = 0;j<length;j++){
			if(arr_pre[i] == arr_post[j]){
				common_ele = arr_pre[i];
			}
		}
	}
	return (int)common_ele.size();
}

void next(string str,int arr[]){
	string::const_iterator collect = str.begin();
	string temp = "";
	string *prefix_arr = new string[str.size()+1];
	memset(arr,0,sizeof(int)*(int)str.size()); 

	for(string::const_iterator i = collect;i!=str.end();i++){
		temp+=*i;
		prefix_arr[i-collect] = temp;
		string *postfix_arr = new string[i-collect];
		string post_temp = "";
		for(string::const_iterator j = temp.begin()+(i-collect);j>=temp.begin()+1;j--){
			post_temp = *j+post_temp;
			postfix_arr[j-temp.begin()-1] = post_temp;
		}
		log_arr(postfix_arr);
		arr[i-collect] = get_common_ele(prefix_arr,postfix_arr,i-collect);
		// cout<<arr[i-collect]<<endl;
		delete[] postfix_arr;
	}
	delete[] prefix_arr;
}

int main(){
	string child_str = "ABCDABD";
	int length = child_str.size();
	string parent_str = "ababababababababab";
	int *next_arr = new int[length];
	next(child_str,next_arr);
}