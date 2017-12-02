//
//  XXTRuntimeBaseAccessor.mm
//  C-P-P-Learning
//
//  Created by Lee on 2017/12/2.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#import "XXTRuntimeBaseAccessor.h"
#import <objc/runtime.h>
#import <string>

SEL XXTRuntimeBaseAccessor::GetGetterSelector(Class cls, const std::string &propertyName)
{
    objc_property_t objcProperty = class_getProperty(cls, propertyName.c_str());
    const char *getter = property_copyAttributeValue(objcProperty, "G");
    if (!getter) {
        getter = propertyName.c_str();
    }
    return sel_registerName(getter);
}


SEL XXTRuntimeBaseAccessor::GetSetterSelector(Class cls, const std::string &propertyName)
{
    objc_property_t objcProperty = class_getProperty(cls, propertyName.c_str());
    const char *setter = property_copyAttributeValue(objcProperty, "S");
    if (setter) {
        return sel_registerName(setter);
    }
    std::string defaultSetter = "set" + propertyName + ":";
    defaultSetter[3] = std::toupper(propertyName[0]);
    return sel_registerName(defaultSetter.c_str());
}


IMP XXTRuntimeBaseAccessor::GetClassMethodImplementation(Class cls, SEL selector)
{
    return [cls methodForSelector:selector];
}

IMP XXTRuntimeBaseAccessor::GetInstanceMethodImplementation(Class cls, SEL selector)
{
    return [cls instanceMethodForSelector:selector];
}


Class XXTRuntimeBaseAccessor::GetPropertyClass(Class cls, const std::string &propertyName)
{
    objc_property_t property = class_getProperty(cls, propertyName.c_str());
    NSString *attributes = [NSString stringWithUTF8String:property_getAttributes(property)];
    NSArray *splitAttributes = [attributes componentsSeparatedByString:@","];
    if (splitAttributes.count > 0) {
        NSString *encodeType = splitAttributes[0];
        NSArray *splitEncodeTypes = [encodeType componentsSeparatedByString:@"\""];
        NSString *className = splitEncodeTypes[1];
        return NSClassFromString(className);
    }
    return nil;
}

