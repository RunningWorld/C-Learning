//
//  column_def.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef column_def_hpp
#define column_def_hpp

#include "column.hpp"

class ColumnDef : public Describable
{
public:
    ColumnDef(const Column &column, ColumnType type);
};

#endif /* column_def_hpp */
