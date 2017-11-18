//
//  describable.cpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#include "describable.hpp"


Describable::Describable(const std::string &description)
: m_description(description)
{
}

Describable::Describable(const char *description) : m_description(description)
{
}

const std::string &Describable::getDescription() const
{
    return m_description;
}

bool Describable::isEmpty() const
{
    return m_description.empty();
}

Describable::operator const std::string &() const
{
    return m_description;
}
