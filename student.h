//
// Created by »ªË¶ on 20/7/2022.
//

#ifndef CHAPTER14_STUDENT_H
#define CHAPTER14_STUDENT_H
#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class Student {
private:
    typedef valarray<double> ArrayDb;
    string name;
    ArrayDb scores;
    ostream & arr_out(ostream & os) const;
public:
    Student() : name("Null Student"),scores() {}
    explicit Student(int n) : name("Nully"),scores(n) {}
    explicit Student(const string & s) : name(s),scores() {}
    Student(const string & s, int n) : name(s),scores(n) {}
    Student(const string & s, const ArrayDb & a) : name(s),scores(a) {}
    Student(const char * str, const double * pd, int n) : name(str),scores(pd,n) {}
    ~Student() {}
    double Average() const;
    const string & Name () const;
    double & operator [] (int i);
    double operator [] (int i) const;

    friend istream & operator >> (istream & is,Student & stu);
    friend istream & getline (istream & is,Student & stu);
    friend ostream & operator << (ostream & os,Student & stu);
};


#endif //CHAPTER14_STUDENT_H
