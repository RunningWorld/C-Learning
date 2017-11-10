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
#import "column_type.h"

typedef NS_ENUM(int, XXTColumnType) {
    XXTColumnTypeInteger32 = (XXTColumnType) ColumnType::Integer32,
    XXTColumnTypeInteger64 = (XXTColumnType) ColumnType::Integer64,
    XXTColumnTypeDouble = (XXTColumnType) ColumnType::Float,
    XXTColumnTypeString = (XXTColumnType) ColumnType::Text,
    XXTColumnTypeBinary = (XXTColumnType) ColumnType::BLOB,
    XXTColumnTypeNil = (XXTColumnType) ColumnType::Null,
};

typedef ColumnDef XXTColumnDef;

#endif /* XXTDeclare_h */
