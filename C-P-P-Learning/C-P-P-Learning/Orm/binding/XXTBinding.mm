//
//  XXTBinding.cpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#include "XXTBinding.h"
#include"XXTCoding.h"
#import <objc/runtime.h>

XXTBinding::XXTBinding(Class cls)
: m_cls(cls) 
{
    if (![m_cls conformsToProtocol:@protocol(XXTTableCoding)]) {
        class_addProtocol(m_cls, @protocol(XXTTableCoding));
    }
}

void XXTBinding::_addColumnBinding(const std::string &columnName, const std::shared_ptr<XXTColumnBinding> &columnBinding)
{
    m_columnBindingList.push_back(columnBinding);
    m_columnBindingMap.insert({columnName, columnBinding});
}

