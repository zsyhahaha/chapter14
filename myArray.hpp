//
// Created by ��˶ on 12/7/2022.
//

#ifndef TEST_MYARRAY_HPP
#define TEST_MYARRAY_HPP
#pragma once
#include <iostream>

using namespace std;

template<class T>
class myArray {
public:
    myArray(int capacity)//�вι���
    {
        cout<<"�вι���"<<endl;
        this->myCapacity = capacity;
        this->mySize = 0;
        this->pAddress = new T[this->myCapacity];
    }
    ~myArray()//����
    {
        cout<<"����"<<endl;
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }
    myArray(const myArray& arr)//���
    {
        cout<<"���"<<endl;
        this->myCapacity = arr.myCapacity;
        this->mySize = arr.mySize;
        this->pAddress = new T[arr.myCapacity];
        for (int i = 0; i < this->mySize; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    myArray& operator=(const myArray& arr)//���������ʵ�����
    {
        cout<<"���������"<<endl;
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

    void Push_Back(const T & val)//β�巨
    {
        if(this->myCapacity == this->mySize)
        {
            return;
        }
        this->pAddress[this->mySize] = val;
        this->mySize++;
    }

    void Pop_Back()//βɾ��
    {
        if(this->mySize == 0)
        {
            return;
        }
        this->mySize--;
    }

    T& operator[](int index)//ͨ���±���������е�Ԫ�أ���д�����
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
    T * pAddress;//ָ�����
    int myCapacity;//��������
    int mySize;//�����С

};


#endif //TEST_MYARRAY_HPP
