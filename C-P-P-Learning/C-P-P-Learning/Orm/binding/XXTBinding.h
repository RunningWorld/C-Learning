//
//  XXTBinding.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//


#ifndef XXTBinding_hpp
#define XXTBinding_hpp

#include "XXTColumnBinding.h"
#include "XXTDeclare.h"

class XXTBinding {
public:
    XXTBinding(Class);

#pragma mark - Column
    template <typename T>
    std::shared_ptr<XXTColumnBinding>
    addColumnBinding(const std::string &propertyName, const std::string &columnName)
    {
        std::shared_ptr<XXTColumnBinding> columnBinding(new XXTColumnBinding(m_cls , propertyName, columnName, (T*) nullptr));
        _addColumnBinding(columnName, columnBinding);
        return columnBinding;
    }
    
protected:
    void _addColumnBinding(const std::string &propertyName,
                           const std::shared_ptr<XXTColumnBinding> &columnBinding);
    Class m_cls;
    
    //TODO :
    
    XXTColumnBindingMap m_columnBindingMap;   //columnName->column binding
    XXTColumnBindingList m_columnBindingList; //ordered column binding
};

#endif /* XXTBinding_hpp */
