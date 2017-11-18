//
//  operator-Read.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/17.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#ifndef operator_Read_h
#define operator_Read_h

/*
 C++ operator关键字（重载操作符）
 https://www.cnblogs.com/xiangxiaodong/archive/2012/02/12/2348144.html
 
 为什么使用操作符重载？
 对于系统的所有操作符，一般情况下，只支持基本数据类型和标准库中提供的class，对于用户自己定义的class，如果想支持基本操作，比如比较大小，判断是否相等，等等，则需要用户自己来定义关于这个操作符的具体实现。比如，判断两个人是否一样大，我们默认的规则是按照其年龄来比较，所以，在设计person 这个class的时候，我们需要考虑操作符==，而且，根据刚才的分析，比较的依据应该是age。那么为什么叫重载呢？这是因为，在编译器实现的时候，已经为我们提供了这个操作符的基本数据类型实现版本，但是现在他的操作数变成了用户定义的数据类型class，所以，需要用户自己来提供该参数版本的实现。
 
 class person{
 private:
 int age;
 public:
 person(int a){
 this->age=a;
 }
 inline bool operator == (const person &ps) const;
 };
 实现方式如下：
 inline bool person::operator==(const person &ps) const
 {
 
 if (this->age==ps.age)
 return true;
 return false;
 }
 调用方式如下：
 #include
 using namespace std;
 int main()
 {
 
 person p1(10);
 person p2(20);
 if(p1==p2) cout<<”the age is equal!”< return 0;
 }
 
 */


#endif /* operator_Read_h */
