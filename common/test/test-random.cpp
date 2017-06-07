#include <iostream>
#include "../lib/random.hpp"
using namespace std;
int main(int argc,char** argv){
	auto nums =  random_numbers(10,10);
	for(auto i:nums){
		cout<<nums[i]<<endl;
	}
	return 0;
}

// g++11 test-random.cpp ../lib/random.cpp -o rando