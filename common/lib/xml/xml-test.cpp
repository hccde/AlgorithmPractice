#include <iostream>
#include "xml.hpp"
using namespace std;
using namespace xml;
int main(int argc,char** argv){
    XML testxml;
    int* node = new int(2);
    testxml.insertNode(node);
    return 0;
}