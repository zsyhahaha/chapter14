#include <iostream>
#include "myArray.hpp"
using namespace std;


void print(myArray<int> &arr)
{
    for (int j = 0; j < arr.get_Size(); ++j) {
        cout<<arr[j]<<endl;
    }
}

void test01()
{
    myArray<int> arr1(5);
    myArray<int> arr2(arr1);
    myArray<int>arr3(100);
    arr3 = arr1;
}

void test02()
{
    myArray<int> arr1(5);
    for (int i = 0; i < 5; ++i) {
        arr1.Push_Back(i);
    }
    cout<<"���"<<endl;
    print(arr1);
    cout<<"ɾ��ĩβԪ��"<<endl;
    arr1.Pop_Back();
    cout<<"���"<<endl;
    print(arr1);

}

void test03()
{
    myArray<int> arr1(5);
    cout<<"arr1������"<<endl;
    int capacity = arr1.get_Capacity();
    cout<<capacity<<endl;
    cout<<"arr1�Ĵ�С"<<endl;
    int size = arr1.get_Size();
    cout<<size<<endl;
}
int main() {
    test02();

    //system("pause");

    return 0;
}