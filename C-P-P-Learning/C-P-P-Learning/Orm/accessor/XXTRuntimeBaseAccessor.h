//
//  XXTRuntimeBaseAccessor.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/12/2.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef XXTRuntimeBaseAccessor_hpp
#define XXTRuntimeBaseAccessor_hpp

#import <Foundation/Foundation.h>
#import <functional>

class XXTRuntimeBaseAccessor {
protected:
    using InstanceType = id;
    static SEL GetGetterSelector(Class cls, const std::string &propertyName);
    static SEL GetSetterSelector(Class cls, const std::string &propertyName);
    static IMP GetClassMethodImplementation(Class cls, SEL selector);
    static IMP GetInstanceMethodImplementation(Class cls, SEL selector);
    static Class GetPropertyClass(Class cls, const std::string &propertyName);
};

template <typename PropertyType>
class XXTRuntimeAccessor : public XXTRuntimeBaseAccessor {
public:
    using Setter = void (^) (InstanceType , PropertyType);
    using Getter = PropertyType (^) (InstanceType);
    
    XXTRuntimeAccessor(Class cls, const std::string &propertyName)
    : getProperty(GenerateGetter(cls, propertyName))
    , setProperty(GenerateSetter(cls, propertyName))
    {
        
    }
    
    const Setter setProperty;
    const Getter getProperty;
    
protected:
    Getter GenerateGetter(Class cls, const std::string &propertyName)
    {
        SEL selector = GetGetterSelector(cls, propertyName);
        IMP imp = GetInstanceMethodImplementation(cls, selector);
        auto block = ^(InstanceType instance) {
            using IMPGetter = PropertyType (*)(id, SEL);
            return ((IMPGetter) imp)(instance, selector);
        };
        return block;
    }
    
    Setter GenerateSetter(Class cls, const std::string &propertyName)
    {
        SEL selector = GetSetterSelector(cls, propertyName);
        IMP imp = GetInstanceMethodImplementation(cls, selector);
        auto block = ^(InstanceType instance, PropertyType value) {
            using IMPSetter = void (*)(InstanceType, SEL, PropertyType);
            return ((IMPSetter) imp)(instance, selector, value);
        };
        return [block copy];
    }
};


#endif /* XXTRuntimeBaseAccessor_hpp */
