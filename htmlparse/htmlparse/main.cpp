//
//  main.cpp
//  htmlparse
//
//  Created by admos on 16/9/1.
//  Copyright © 2016年 admos. All rights reserved.
//

#include <iostream>
#include "htmlparse/htmlparse.h"
int main(int argc, const char * argv[]) {
    char str[200] = "<html><body><h1>hello world</h1></body></html>";
    htmlParse(str);
    return 0;
}
