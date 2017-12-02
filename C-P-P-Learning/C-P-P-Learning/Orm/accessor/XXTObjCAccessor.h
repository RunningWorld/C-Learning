//
//  XXTObjCAccessor.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/12/2.
//  Copyright © 2017年 YYCoding. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "XXTBaseAccessor.h"
#import <functional>
#import <type_traits>

template <typename T, typename Enable = void>
struct ColumnIsObjCType : public std::false_type {
};

template <typename T>
struct ColumnIsObjCType
<T, typename std::enable_if<std::is_convertible<T,id>::value>::type> : public std::true_type
{    
};

class XXTObjCAccessor : public XXTBaseAccessor {
public:
    using OCType = id; //NSData*, NSString*, NSNumber*
    using Setter = void (^)(InstanceType, OCType);
    using Getter = OCType (^)(InstanceType);
    
    XXTObjCAccessor(Getter getter, Setter setter)
    : getObject(getter), setObject(setter)
    {
    }
    
    virtual XXTAccessorType getAccessorType() const override
    {
        return XXTAccessorObjC;
    }
    
    const Setter setObject;
    const Getter getObject;
};
