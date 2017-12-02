//
//  XXTRuntimeObjCAccessor.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/12/2.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XXTObjCAccessor.h"
#import "XXTRuntimeBaseAccessor.h"
#import <objc/runtime.h>

class XXTRuntimeObjCAccessor : public XXTRuntimeAccessor<id>,
public XXTObjCAccessor {
protected:
    using InstanceType = XXTObjCAccessor::InstanceType;
    using PropertyType = NSObject *; //NSObject<XXTColumnCoding>*
    using PropertyGetter = XXTRuntimeAccessor<id>::Getter;
    using PropertySetter = XXTRuntimeAccessor<id>::Setter;
    using ValueGetter = XXTObjCAccessor::Getter;
    using ValueSetter = XXTObjCAccessor::Setter;
    
public:
    XXTRuntimeObjCAccessor(Class instanceClass,
                           const std::string &propertyName);
    
protected:
    ValueGetter generateValueGetter(Class instanceClass,
                                    const std::string &propertyName);
    ValueSetter generateValueSetter(Class instanceClass,
                                    const std::string &propertyName);
    
    virtual XXTColumnType getColumnType() const override;
    
    XXTColumnType GetColumnType(Class instanceClass,
                                const std::string &propertyName);
    
    const XXTColumnType m_columnType;
};

