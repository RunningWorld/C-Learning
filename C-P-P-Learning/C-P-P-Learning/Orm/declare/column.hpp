//
//  column.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef column_hpp
#define column_hpp

#include "declare.hpp"
#include "describable.hpp"

class Column : public Describable
{
public:
    static const Column Any;
    static const Column Rowid;
    Column();
    Column(const char *name);
    Column(const std::string &name);
    const std::string &getName() const;
    Column inTable(const std::string &table) const;
    operator ColumnList() const;
    bool operator==(const Column &column) const;
};


#endif /* column_hpp */
