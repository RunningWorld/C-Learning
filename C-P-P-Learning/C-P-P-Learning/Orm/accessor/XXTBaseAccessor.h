//
//  XXTBaseAccessor.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef XXTBaseAccessor_h
#define XXTBaseAccessor_h

#include "XXTDeclare.h"

typedef NS_ENUM(int, XXTAccessorType) {
    XXTAccessorCpp,
    XXTAccessorObjC,
};

class XXTBaseAccessor {
public:
    using InstanceType = id; //NSObject<WCTTableCoding>*
    virtual XXTColumnType getColumnType() const = 0;
    virtual XXTAccessorType getAccessorType() const = 0;
};

#endif /* XXTBaseAccessor_h */
