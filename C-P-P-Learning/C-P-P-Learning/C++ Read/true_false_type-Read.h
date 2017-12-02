//
//  true_false_type-Read.h
//  C-P-P-Learning
//
//  Created by caolidong on 2017/12/2.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef true_false_type_Read_h
#define true_false_type_Read_h

/*
 type_traits是利用C++模板特性和static、enum特性定义编译器常量
 
 我理解的type_traits是利用C++模板特性和static、enum特性定义编译器常量，例如
 
 //std::integral_constant源码
 typelate<class T, T v>
 struct integral_constant
 {
 static const T value = v;
 typedef T value_type;
 typedef integral_constant<T, v> type;
 operator value_type() {return value;}
 };

 这里利用的是static常量为编译器常量的特，定义了value。使用方法：从std::integral_constant派生，无需自己定义static const常量或enum类型，例如
 
 template<typename T>
 struct GetSize : std::integral_constant<int, 1>
 {
 };
 
 1.is_void
 
 声明：
 
 template<class T>
 struct is_void;
 
 作用：
 
 T是否为void类型
 
 源码：
 
 template<class T, class U>
 struct is_same : std::false_type
 {};
 
 template<class T>
 struct is_same : std::true_type
 {};
 
 template<class T>
 struct is_void : std::is_same<void, typename std::remove_cv<T>::type>
 {};
 
 首先利用模板的匹配实现用以判断两种类型是否一致的is_same，再将T去除c（const）、v（volatile）限定符后与void类型判断是否一致。下面有些简单的代码就不解释了。
 
 false_type Typedef
 保留包含值 false 的整数常量。
 
 ture_type Typedef
 保留包含值 ture 的整数常量。
 
 */



#endif /* true_false_type_Read_h */
