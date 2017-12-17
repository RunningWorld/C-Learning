//
//  XXTDeclare.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef XXTDeclare_h
#define XXTDeclare_h

#import <Foundation/Foundation.h>
#include <map>
#include <list>
#include "utility.hpp"
#include "column_type.hpp"

typedef NS_ENUM(int, XXTColumnType) {
    XXTColumnTypeInteger32 = (XXTColumnType) SNS::ColumnType::Integer32,
    XXTColumnTypeInteger64 = (XXTColumnType) SNS::ColumnType::Integer64,
    XXTColumnTypeDouble = (XXTColumnType) SNS::ColumnType::Float,
    XXTColumnTypeString = (XXTColumnType) SNS::ColumnType::Text,
    XXTColumnTypeBinary = (XXTColumnType) SNS::ColumnType::BLOB,
    XXTColumnTypeNil = (XXTColumnType) SNS::ColumnType::Null,
};

class XXTColumnBinding;

//Case insensitive
typedef std::map<std::string,
std::shared_ptr<XXTColumnBinding>,
SNS::CaseInsensiveComparetor>
XXTColumnBindingMap;

typedef std::list<std::shared_ptr<XXTColumnBinding>> XXTColumnBindingList;

#endif /* XXTDeclare_h */
