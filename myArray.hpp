//
// Created by 华硕 on 12/7/2022.
//

#ifndef TEST_MYARRAY_HPP
#define TEST_MYARRAY_HPP
#pragma once
#include <iostream>

using namespace std;

template<class T>
class myArray {
public:
    myArray(int capacity)//有参构造
    {
        cout<<"有参构造"<<endl;
        this->myCapacity = capacity;
        this->mySize = 0;
        this->pAddress = new T[this->myCapacity];
    }
    ~myArray()//析构
    {
        cout<<"析构"<<endl;
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }
    myArray(const myArray& arr)//深拷贝
    {
        cout<<"深拷贝"<<endl;
        this->myCapacity = arr.myCapacity;
        this->mySize = arr.mySize;
        this->pAddress = new T[arr.myCapacity];
        for (int i = 0; i < this->mySize; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    myArray& operator=(const myArray& arr)//重载运算符实现深拷贝
    {
        cout<<"运算符重载"<<endl;
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->myCapacity = 0;
            this->mySize = 0;
        }
        this->myCapacity = arr.myCapacity;
        this->mySize = arr.mySize;
        this->pAddress = new T[arr.myCapacity];
        for (int i = 0; i < this->mySize; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    void Push_Back(const T & val)//尾插法
    {
        if(this->myCapacity == this->mySize)
        {
            return;
        }
        this->pAddress[this->mySize] = val;
        this->mySize++;
    }

    void Pop_Back()//尾删法
    {
        if(this->mySize == 0)
        {
            return;
        }
        this->mySize--;
    }

    T& operator[](int index)//通过下标访问数组中的元素，重写运算符
    {
        return this->pAddress[index];
    }

    int get_Capacity()
    {
        return this->myCapacity;
    }

    int get_Size()
    {
        return this->mySize;
    }

private:
    T * pAddress;//指向堆区
    int myCapacity;//数组容量
    int mySize;//数组大小

};


#endif //TEST_MYARRAY_HPP
