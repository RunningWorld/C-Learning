//
//  column_type.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef column_type_hpp
#define column_type_hpp

#include "column_type.h"

//Null
template <ColumnType T = ColumnType::Null>
struct ColumnTypeInfo {
    static constexpr const bool isNull = true;
    static constexpr const bool isFloat = false;
    static constexpr const bool isInteger32 = false;
    static constexpr const bool isInteger64 = false;
    static constexpr const bool isText = false;
    static constexpr const bool isBLOB = false;
    static constexpr const bool isBaseType = false;
    using CType = void;
    static constexpr const ColumnType type = ColumnType::Null;
    static constexpr const char *name = "";
};
template <typename T, typename Enable = void>
struct ColumnInfo : public ColumnTypeInfo<ColumnType::Null> {
};

#endif /* column_type_hpp */
