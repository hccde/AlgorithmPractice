#include <iostream>
#include "../lib/random.hpp"
using namespace std;
int main(int argc,char** argv){
	produce(10);
	return 0;
}

// g++11 test-random.cpp ../lib/random.cpp -o random