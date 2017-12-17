//
//  XXTColumnBinding.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef XXTColumnBinding_hpp
#define XXTColumnBinding_hpp


#import "XXTCppAccessor.h"
#import "XXCommonHeader.h"
#import "XXTBaseAccessor.h"
#import "XXTDeclare.h"
#import "XXTRuntimeObjCAccessor.h"
#include "column_def.hpp"

class XXTColumnBinding {
public:
    template <typename T>
    XXTColumnBinding(
                     Class cls,
                     const std::string &pn,
                     const std::string &cn,
                     T * = nullptr,
                     typename std::enable_if<ColumnIsCppType<T>::value>::type * = nullptr)
                     : columnName(cn)
                     , accessor(new XXTRuntimeObjCAccessor(cls, pn))
                     , m_columnDef(cn, (SNS::ColumnType) accessor->getColumnType())
                     , m_isAutoIncrement(false)
                     , m_isPrimary(false)
    {
    }
    
    const std::string columnName;
    const std::shared_ptr<XXTBaseAccessor> accessor;
    
protected:
    bool m_isPrimary;
    bool m_isAutoIncrement;
    SNS::ColumnDef m_columnDef;
};

#endif /* XXTColumnBinding_hpp */
