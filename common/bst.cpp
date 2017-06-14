#include <iostream>
#include "lib/bst.hpp"
#include "lib/random.hpp"
using namespace std;

int main(int argc,char** argv){
    vector<int> randnums = random_numbers(100,20);
    // show_vector(randnums); 
    Bst<int>* b = new Bst<int>(randnums);
    // b->pre_order_traversal(b->root);
    // b->in_order_traversal(b->root);
    b->remove_node(b->root->right);
    cout<<endl;
    b->in_order_traversal(b->root);
    delete b;
    return 0;
}
