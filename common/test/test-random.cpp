#include <iostream>
#include "../lib/random.hpp"
using namespace std;
int main(int argc,char** argv){
	cout<<random_number(10)<<endl;
	cout<<random_number(12)<<endl;
	cout<<random_number(12)<<endl;
	cout<<random_number(12)<<endl;
	// random_numbers(10,10);
	return 0;
}

// g++11 test-random.cpp ../lib/random.cpp -o rando