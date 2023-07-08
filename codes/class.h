// class.h
#ifndef CLASS_H
#define CLASS_H
#include <cstdio>
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;
// Date类
class Date {
  public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
    // 重载输出运算符
    friend ostream &operator<<(ostream &os, Date const &birthday);
    int year, month, day;
};
// Person类
class Person {
  protected:
    string name, id, gender;
    Date birthday;

  public:
    Person(string n = "", string i = "", string g = "", Date b = Date())
        : name(n), id(i), gender(g), birthday(b) {}
    // 析构函数设为虚函数
    virtual ~Person(){};
    // 输入信息
    virtual void inputData();
    // 打印信息
    virtual void displayDetails();
};
// 定义哈希表，将id映射到基类对象指针，便于查询
extern unordered_map<string, Person *> table;
// Student类
class Student : public virtual Person {
  protected:
    string studentNo, schoolName, classIn;

  public:
    Student(string n = "", string i = "", string g = "", Date b = Date(),
            string sNo = "", string sName = "", string cIn = "")
        : Person(n, i, g, b), studentNo(sNo), schoolName(sName), classIn(cIn) {}
    void inputData();
    void displayDetails();
};
// Teacher类
class Teacher : public virtual Person {
  protected:
    string teacherNo, schoolName, department;

  public:
    Teacher(string n = "", string i = "", string g = "", Date b = Date(),
            string tNo = "", string sName = "", string dept = "")
        : Person(n, i, g, b), teacherNo(tNo), schoolName(sName),
          department(dept) {}
    void inputData();
    void displayDetails();
};
// UnderGraduate类
class UnderGraduate : public Student {
  private:
    string major;

  public:
    UnderGraduate(string n = "", string i = "", string g = "", Date b = Date(),
                  string sNo = "", string sName = "", string cIn = "",
                  string m = "")
        : Person(n, i, g, b), Student(n, i, g, b, sNo, sName, cIn), major(m) {}
    void inputData();
    void displayDetails();
};
// Graduate类
class Graduate : public Student {
  protected:
    string direction, adviserName;

  public:
    Graduate(string n = "", string i = "", string g = "", Date b = Date(),
             string sNo = "", string sName = "", string cIn = "", string d = "",
             string aName = "")
        : Person(n, i, g, b), Student(n, i, g, b, sNo, sName, cIn),
          direction(d), adviserName(aName) {}
    void inputData();
    void displayDetails();
};
// TA类
class TA : public Graduate, public Teacher {
  public:
    TA(string n = "", string i = "", string g = "", Date b = Date(),
       string sNo = "", string sName = "", string cIn = "", string d = "",
       string aName = "", string tNo = "", string dept = "")
        : Person(n, i, g, b), Graduate(n, i, g, b, sNo, sName, cIn, d, aName),
          Teacher(n, i, g, b, tNo, sName, dept) {}
    void inputData();
    void displayDetails();
};
#endif
