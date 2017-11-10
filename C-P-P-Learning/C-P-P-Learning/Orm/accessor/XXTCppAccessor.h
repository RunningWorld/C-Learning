//
//  XXTCppAccessor.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#include <iostream>
#import "XXTDeclare.h"
#include "column_type.hpp"

#ifndef XXTCppAccessor_h
#define XXTCppAccessor_h

template <typename T, typename Enable = void>
struct ColumnIsCppType : public std::false_type {};

template <typename T>
struct ColumnIsCppType<T,
typename std::enable_if<ColumnInfo<T>::type !=
    ColumnType::Null>::type>
: public std::true_type {
};

#endif /* XXTCppAccessor_h */
