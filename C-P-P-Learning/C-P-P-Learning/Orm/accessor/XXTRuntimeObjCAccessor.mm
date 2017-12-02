//
//  XXTRuntimeObjCAccessor.m
//  C-P-P-Learning
//
//  Created by caolidong on 2017/12/2.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#import "XXTRuntimeObjCAccessor.h"
#import "XXTCoding.h"

XXTRuntimeObjCAccessor::XXTRuntimeObjCAccessor(Class instanceClass, const std::string &propertyName)
: XXTRuntimeAccessor<id>(instanceClass, propertyName)
, XXTObjCAccessor(generateValueGetter(instanceClass, propertyName), generateValueSetter(instanceClass, propertyName))
, m_columnType(GetColumnType(instanceClass, propertyName))
{
    Class propertyClass = GetPropertyClass(instanceClass, propertyName);
    if (![propertyClass conformsToProtocol:@protocol(XXTColumnCoding)]) {
//        Error::Abort([NSString stringWithFormat:@"Class %@ should conforms to protocol XXTColumnCoding", NSStringFromClass(propertyClass)].UTF8String);
    }
}

XXTRuntimeObjCAccessor::ValueGetter XXTRuntimeObjCAccessor::generateValueGetter(Class instanceClass, const std::string &propertyName)
{
    static const SEL ArchiveSelector = NSSelectorFromString(@"archivedXXTValue");
    Class propertyClass = GetPropertyClass(instanceClass, propertyName);
    IMP implementation = GetInstanceMethodImplementation(propertyClass, ArchiveSelector);
    auto block = ^(InstanceType instance) {
        using Archiver = OCType (*)(InstanceType, SEL);
        PropertyType property = getProperty(instance);
        OCType value = property ? ((Archiver) implementation)(property, ArchiveSelector) : nil;
        return value;
    };
    return [block copy];
}

XXTRuntimeObjCAccessor::ValueSetter XXTRuntimeObjCAccessor::generateValueSetter(Class instanceClass, const std::string &propertyName)
{
    static const SEL UnarchiveSelector = NSSelectorFromString(@"unarchiveWithXXTValue:");
    Class propertyClass = GetPropertyClass(instanceClass, propertyName);
    IMP implementation = GetClassMethodImplementation(propertyClass, UnarchiveSelector);
    auto block = ^(InstanceType instance, OCType value) {
        using Unarchiver = PropertyType (*)(Class, SEL, OCType);
        if (instance) {
            PropertyType property = ((Unarchiver) implementation)(propertyClass, UnarchiveSelector, value);
            setProperty(instance, property);
        }
    };
    return [block copy];
}

XXTColumnType XXTRuntimeObjCAccessor::GetColumnType(Class instanceClass, const std::string &propertyName)
{
    static const SEL ColumnTypeSelector = NSSelectorFromString(@"columnTypeForXXDB");
    Class propertyClass = GetPropertyClass(instanceClass, propertyName);
    if (![propertyClass conformsToProtocol:@protocol(XXTColumnCoding)]) {
//        XXDB::Error::Abort([NSString stringWithFormat:@"[%@] should conform to XXTColumnCoding protocol, which is the class of [%@ %s]", NSStringFromClass(propertyClass), NSStringFromClass(instanceClass), propertyName.c_str()].UTF8String);
    }
    IMP implementation = GetClassMethodImplementation(propertyClass, ColumnTypeSelector);
    using GetColumnTyper = XXTColumnType (*)(Class, SEL);
    return ((GetColumnTyper) implementation)(propertyClass, ColumnTypeSelector);
}

XXTColumnType XXTRuntimeObjCAccessor::getColumnType() const
{
    return m_columnType;
}

