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
        void insertNode(T* node,T* addedNode=NULL){
            if(addedNode == NULL){//root
                std::cout<<"haha";
            }else{//insert node

            }
            // doc.InsertAfterChild(node,addedNode);
        }

        //default circle
        template <class T>
        XMLElement* createNode(T* node){
            //create circle element
            return doc.NewElement("circle");    
        }

        void printDoc(){

        }

        ~XML(){
            // delete doc;
        }
    };
}

#endif