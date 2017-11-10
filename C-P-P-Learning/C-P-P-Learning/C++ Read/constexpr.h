//
//  constexpr.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/10.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef constexpr_h
#define constexpr_h

/*
 
 关键字 constexpr 于 C++11 中引入并于 C++14 中得到改善。它表示常数表达式。
 * 与 const 相同，它可应用于变量，因此如果任何代码试图修改该值，均将引发编译器错误。
 * 与 const 不同，constexpr 也可应用于函数和类构造函数。
 * constexpr 指示值或返回值是常数，并且如果可能，将在编译时计算值或返回值。
 
 1 constexpr 变量
 const 和 constexpr 变量之间的主要区别在于：const 变量的初始化可以延迟到运行时，而 constexpr 变量必须在编译时进行初始化。所有 constexpr 变量均为常量，因此必须使用常量表达式初始化。
 constexpr float x = 42.0;
 constexpr float y{108};
 constexpr float z = exp(5, 3);
 constexpr int i; // Error! Not initialized
 int j = 0;
 constexpr int k = j + 1; //Error! j not a constant expression
 
 2 constexpr 函数
 constexpr 函数是在使用需要它的代码时，可以在编译时计算其返回值的函数。
 当其参数为 constexpr 值并且在编译时使用代码需要返回值时（例如，初始化一个 constexpr 变量或提供一个非类型模板参数），它会生成编译时常量。
 使用非constexpr 参数调用时，或编译时不需要其值时，它将与正则函数一样，在运行时生成一个值。
 
 3 constexpr和指针
 还记得const与指针的规则吗？如果关键字const出现在星号左边，表示被指物是常量；如果出现在星号右边，表示指针本身是常量；如果出现在星号两边，表示被指物和指针两者都是常量。
 与const不同，在constexpr声明中如果定义了一个指针，限定符constexpr仅对指针有效，与指针所指对象无关。
 
 const int *p     = 0; // non-const pointer, const data
 constexpr int *q = 0; // const pointer, non-const data
 
 与其它常量指针类似，const指针既可以指向常量也可以指向一个非常量：
 
 int j = 0;
 constexpr int i = 2;
 constexpr const int *p = &i; // const pointer, const data
 constexpr int *p1 = &j; // const pointer, non-const data
 
 */

#endif /* constexpr_h */
