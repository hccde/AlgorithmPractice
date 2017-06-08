#include <iostream>
#include "lib/bst.hpp"
#include "lib/random.hpp"
using namespace std;

int main(int argc,char** argv){
    Bst<int> b = Bst<int>(random_numbers(50,20));
    return 0;
}