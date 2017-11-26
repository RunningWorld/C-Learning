//
//  XXTColumnBinding.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef XXTColumnBinding_hpp
#define XXTColumnBinding_hpp


#include "XXTCppAccessor.h"
#import "XXCommonHeader.h"
#include "XXTBaseAccessor.h"
#include "XXTDeclare.h"
#include "declare.hpp"
#include "column_def.hpp"

class XXTColumnBinding {
public:
    template <typename T>
    XXTColumnBinding(
                     Class cls,
                     const std::string &pn,
                     const std::string &cn,
                     T * = nullptr, typename std::enable_if<ColumnIsCppType<T>::value>::type * = nullptr)
    : columnName(cn) 
    , m_columnDef(cn, (ColumnType) accessor->getColumnType()) 
    , m_isAutoIncrement(false)
    , m_isPrimary(false)
    {
    }
    
    const std::string columnName;
    const std::shared_ptr<XXTBaseAccessor> accessor;
    
protected:
    bool m_isPrimary;
    bool m_isAutoIncrement;
    XXTColumnDef m_columnDef;
};

#endif /* XXTColumnBinding_hpp */
