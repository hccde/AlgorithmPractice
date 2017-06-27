#ifndef __XML_HPP_
#define __XML_HPP_
#include <iostream>
#include "tinyxml2.h"
using namespace tinyxml2;
namespace xml {
    class XML {
        public:
        XMLDocument doc;//doc object
        XML(){
            std::cout<<"constructor"<<std::endl;
        }

        template <class T>
        void insertNode(XMLElement* node,XMLElement* addedNode=NULL,int dire=0){
            if(addedNode == NULL){//root
                doc.InsertFirstChild(node);
            }else if(dire == 0){//insert left node
                addedNode.InsertFirstChild(node);
            }else{ //insert right node
                addedNode.InsertEndChild(node);
            }
        }

        //default circle
        template <class T>
        XMLElement* createNode(T* node){
            //create circle element
            XMLElement* ele =  doc.NewElement("node");
            //set attribute
            return ele;
        }

        void printDoc(){

        }

        ~XML(){
            // delete doc;
        }
    };
}

#endif