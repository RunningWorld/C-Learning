//
//  column_type.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef column_type_h
#define column_type_h

enum class ColumnType : int {
    Null,
    Float,
    Integer32,
    Integer64,
    Text,
    BLOB,
};

#endif /* column_type_h */
