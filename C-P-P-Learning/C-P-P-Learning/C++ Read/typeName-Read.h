//
//  TypeName-Read.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef TypeName_Read_h
#define TypeName_Read_h

/*
 
 typename:
 "typename"是一个C++程序设计语言中的关键字。相当用于泛型编程时是另一术语"class"的同义词。这个关键字用于指出模板声明（或定义）中的非独立名称（dependent names）是类型名，而非变量名
 也可以用class 来替代
 
 类型名指示符
 template <class T>
 void foo(const T& t)
 {
     // 声明一个指向某个类型为T::bar的对象的指针
     T::bar * p;
 }
  
 struct StructWithBarAsType
 {
     typedef int bar;
 };
  
 int main()
 {
     StructWithBarAsType x;
     foo(x);
 }
 
 这段代码看起来能通过编译，但是事实上这段代码并不正确。因为编译器并不知道T::bar究竟是一个类型的名字还是一个某个变量的名字。究其根本，造成这种歧义的原因在于，编译器不明白T::bar到底是不是“模板参数的非独立名字”，简称“非独立名字”。注意，任何含有名为“bar”的项的类T，都可以被当作模板参数传入foo()函数，包括typedef类型、枚举类型或者变量等。
 为了消除歧义，C++语言标准规定：
 A name used in a template declaration or definition and that is dependent on a template-parameter is assumed not to name a type unless the applicable name lookup finds a type name or the name is qualified by the keyword typename.
 意即出现上述歧义时，编译器将自动默认bar为一个变量名，而不是类型名。所以上面例子中的代码 T::bar * p 会被解释为乘法，而不是声明p为指向T::bar类型的对象的指针。
 
 解决问题的最终办法，就是显式地告诉编译器，T::bar是一个类型名。这就必须用typename关键字
 
 */


#endif /* TypeName_Read_h */
