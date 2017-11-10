//
//  main.cpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#include <iostream>
#include "enable_if_test.h"
#include "Template-Read.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int i=12;
    short s=12;
//    enableIf_some_func(s);
    enableIf_some_func(i);
    
    testTemplateFunction();
    
    pair<int> myobject (115, 36);
    
    return 0;
}
