//
//  util.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/24.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef util_hpp
#define util_hpp

#include <string.h>

struct CaseInsensiveComparetor {
    bool operator()(const std::string &lhs, const std::string &rhs) const
    {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

#endif /* util_hpp */
