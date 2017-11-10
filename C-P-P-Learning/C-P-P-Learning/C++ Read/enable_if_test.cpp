//
//  enable_if_test.cpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#include "enable_if_test.h"

void enableIf_some_func(int i) {
    std::cout << "void some_func(" << i << ")\n";
}

template <typename T> void enableIf_some_func(T t) {
    typename T::type variable_of_nested_type;
    std::cout <<"template <typename T> void some_func(" << t << ")\n";
}

