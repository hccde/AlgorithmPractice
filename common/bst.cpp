#include <iostream>
#include "lib/bst.hpp"
#include "lib/random.hpp"
using namespace std;

int main(int argc,char** argv){
    vector<int> randnums = random_numbers(100,20);
    // show_vector(randnums); 
    Bst<int>* b = new Bst<int>(randnums);
    // b.traversal(b.root);
    bool is_vaild =  b->vaild_bst(b->root);
    delete b;
    return 0;
}
