//
//  describable.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef describable_hpp
#define describable_hpp

#include <list>
#include <string>
#include <type_traits>

class Describable {
public:
    template <typename T>
    static std::string GetListDescription(const std::list<const T> &t)
    {
        std::string s;
        GetDescription(t, s);
    }
    
    const std::string &getDescription() const;
    bool isEmpty() const;
    explicit operator const std::string &() const;
    
protected:
    template <typename T>
    static void GetDescription(const std::list<const T> &list , std::string &output)
    {
        bool flag = false;
        for (const auto &t : list) {
            if (flag) {
                output.append(",");
            } else {
                flag = true;
            }
            output.append(std::string(t));
        }
    }
    
    Describable(const std::string &description);
    Describable(const char *description);
    
    std::string m_description;
};

#endif /* describable_hpp */
