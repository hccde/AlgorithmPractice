#include <iostream>
#include "lib/bst.hpp"
#include "lib/random.hpp"
using namespace std;

int main(int argc,char** argv){
    vector<int> randnums = random_numbers(50,20);
    show_vector(randnums); 
    cout<<endl;
    Bst<int> b = Bst<int>(randnums);
    b.traversal(b.root);
    return 0;
}
