#include <iostream>
#include "lib/bst.hpp"
#include "lib/random.hpp"
using namespace std;

int main(int argc,char** argv){
    vector<int> randnums = random_numbers(20,20);
    // show_vector(randnums); 
    cout<<endl;
    int arr[]={19, 18 ,8 ,7 ,0 ,19, 1, 15, 9, 7, 11, 19, 4, 5, 9, 6, 6, 18, 5, 9};
    vector<int> v(arr,arr+20);
    Bst<int> b = Bst<int>(v);
    // b.node_traversal(b.root);
    return 0;
}
