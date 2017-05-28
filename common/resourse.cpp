#include <iostream>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <memory>

using namespace std;

class alloc{
private:
	typedef int* storage;
	size_t _size;
	size_t residual;
	storage ram_poll;
	
public:
	alloc(size_t size):_size(size),residual(size){
		int _size = size % sizeof(int) == 0?size/sizeof(int):size/sizeof(int)+1;
		ram_poll = new int[_size];
	}
	
	~alloc(){
		delete []ram_poll;
	}
};


int main(int argc , char** argv){
	alloc s =  alloc(40);
	return 0;
}