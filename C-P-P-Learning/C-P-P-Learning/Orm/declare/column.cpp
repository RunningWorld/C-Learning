//
//  column.cpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#include "column.hpp"

const Column Column::Rowid("rowid");
const Column Column::Any("*");

Column::Column() : Describable("")
{
}

Column::Column(const char *name) : Describable(name)
{
}

Column::Column(const std::string &name) : Describable(name)
{
}

const std::string &Column::getName() const
{
    return m_description;
}

Column Column::inTable(const std::string &table) const
{
    return Column(table + "." + getName());
}

bool Column::operator==(const Column &column) const
{
    return getDescription() == column.getDescription();
}

