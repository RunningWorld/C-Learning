//
//  explicit-Read.h
//  C-P-P-Learning
//
//  Created by caolidong on 2017/11/18.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef explicit_Read_h
#define explicit_Read_h


/*
 
 关键字explicit，可以阻止不应该允许的经过转换构造函数进行的隐式转换的发生。声明为explicit的构造函数不能在隐式转换中使用。
 
      class Test1
　　{
　　public:
　　Test1(int n) { num = n; } //普通构造函数
　　private:
　　int num;
　　};
　　class Test2
　　{
　　public:
　　explicit Test2(int n) { num = n; } //explicit(显式)构造函数
　　private:
　　int num;
　　};
　　int main()
　　{
　　Test1 t1 = 12; //隐式调用其构造函数, 成功
　　Test2 t2 = 12; //编译错误,不能隐式调用其构造函数
　　Test2 t3(12); //显示调用成功
　　return 0;
　　}
　　Test1的构造函数带一个int型的参数，代码19行会隐式转换成调用Test1的这个构造函数。而Test2的构造函数被声明为explicit（显式），这表示不能通过隐式转换来调用这个构造函数，因此代码20行会出现编译错误。
 
     
 
 */

#endif /* explicit_Read_h */
