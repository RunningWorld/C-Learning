//
//  Template-Read.h
//  C-P-P-Learning
//
//  Created by Lee on 2017/11/9.
//  Copyright © 2017年 YYCoding. All rights reserved.
//

#include <iostream>

#ifndef Template_Read_h
#define Template_Read_h

/*
 template <class GenericType>
 GenericType GetMax (GenericType a, GenericType b) { return (a>b?a:b); }
 
 
 */

template <class T> T GetMax (T a, T b) {
    return (a>b?a:b);
}

int testTemplateFunction () {
    int i=5, j=6, k;
    long l=10, m=5, n;
    k=GetMax(i,j);
    n=GetMax(l,m);
    std::cout <<"k = " << k << " \n";
    std::cout <<"n = "<< n <<" \n";
    return 0;
}

template <class T> class pair {
    T value1, value2;
public:
    pair (T first, T second) {
        value1=first;
        value2=second;
    }
    T getmax ();
};

template<typename T1,typename T2>
class myClass{
private:
    T1 I;
    T2 J;
public:
    myClass(T1 a, T2 b);//Constructor
    void show();
};

//这是构造函数
//注意这些格式
template <typename T1,typename T2>
myClass<T1,T2>::myClass(T1 a,T2 b):I(a),J(b){}
//这是void show();
template <typename T1,typename T2>
void myClass<T1,T2>::show()
{
    std::cout<<"I="<<I<<", J="<<J<<"";
}


#endif /* Template_Read_h */
