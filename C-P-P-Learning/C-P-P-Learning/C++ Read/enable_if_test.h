//
//  enable_if_test.hpp
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#include <iostream>

#ifndef enable_if_test_hpp
#define enable_if_test_hpp

/*
 一、enable_if
 http://www.360doc.com/content/13/0509/17/9200790_284176231.shtml
 
 boost::enable_if就是用来将某些不合要求的模板函数从重载决议列表中踢掉。
 
 template <bool B, class T = void>
 struct enable_if_c {
 typedef T type;
 };
 
 template <class T>
 struct enable_if_c<false, T> {};
 
 template <class Cond, class T = void>
 struct enable_if : public enable_if_c<Cond::value, T> {};
 
 
 可以看到enable_if实际上继承自enable_if_c，而模板enable_if_c需要两个模板参数
 第一个是bool类型，来自enable_if的第一个参数的bool成员value，第二个参数是用户提供的类型T。
 
 enable_if_c的作用就是如果第一个模板参数为true，那么它就将第二个模板参数typedef为type，否则什么也不干。那么enable_if_c<true, T>::type就是T，而enable_if_c<false, T>::type就是错误
 
 
 template <class T>
 typename enable_if_c<boost::is_arithmetic<T>::value, T>::type
 foo(T t) { return t; }
 
 上面这个函数foo只接受算术类型参数
 
 使用enable_if可以写得更简单一些：
 
 template <class T>
 typename enable_if<boost::is_arithmetic<T>, T>::type
 foo(T t) { return t; }
 
 注意：
 enable_if第一个模板参数必须是定义了bool成员value的一个类类型Cond
 第二个参数为任意类型T
 enable_if<true, T>::type为T
 enable_if<false, T>::type无效
 
 二、SFINAE
 SFINAE 是C++ 的一种语言属性，具体内容就是”从一组重载函数中删除模板实例化无效的函数”。
 SFINAE 的的全称是 Substitution Failure Is Not An Error。
 
 */

void enableIf_some_func(int i);

template <typename T> void enableIf_some_func(T t);

#endif /* enable_if_test_hpp */
