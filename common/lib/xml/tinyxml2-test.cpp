#include <iostream>
#include "tinyxml2.h"
#include "tinyxml2.cpp"
using namespace tinyxml2;
using namespace std;

int main(int argc,char** argv){
    XMLDocument doc;
    XMLElement* ele =  doc.NewElement("mydiv");
    doc.NewDeclaration();
    ele->SetAttribute("test",10);
    doc.LinkEndChild(ele);
    if(!doc.SaveFile("test.xml")){
        cout<<"success";
    };
    return 0;
}