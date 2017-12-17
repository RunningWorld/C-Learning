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
#import "XXTBaseAccessor.h"

#ifndef XXTCppAccessor_h
#define XXTCppAccessor_h

template <typename T, typename Enable = void>
struct ColumnIsCppType : public std::false_type {};

template <typename T>
struct ColumnIsCppType<T,
typename std::enable_if<SNS::ColumnInfo<T>::type !=
    SNS::ColumnType::Null>::type>
: public std::true_type {
};

template <XXTColumnType t>
class XXTCppAccessor : public XXTBaseAccessor {
public:
    using CType = typename SNS::ColumnTypeInfo<(SNS::ColumnType)t>::CType;
    using Setter = void (^)(InstanceType, CType);
    using Getter = CType (^)(InstanceType);
    
    XXTCppAccessor(Getter getter, Setter setter)
    : getValue(getter), setValue(setter)
    {
    }
    
    virtual XXTColumnType getColumnType() const override
    {
        return (XXTColumnType) t;
    };
    virtual XXTAccessorType getAccessorType() const override
    {
        return XXTAccessorCpp;
    }
    
    const Setter setValue;
    const Getter getValue;
};


#endif /* XXTCppAccessor_h */
