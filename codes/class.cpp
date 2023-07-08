// class.cpp
#include "class.h"
// 定义哈希表
unordered_map<string, Person *> table;
// 实现重载
ostream &operator<<(ostream &os, Date const &birthday) {
    os << birthday.year << "-" << birthday.month << "-" << birthday.day;
    return os;
}
// 成员函数实现
void Person::inputData() {
    cout << "Name: ";
    cin >> name;
    cout << "ID: ";
    cin >> id;
    table[id] = this;
    cout << "Gender: ";
    cin >> gender;
    cout << "Birthday (Year Month Day): ";
    cin >> birthday.year >> birthday.month >> birthday.day;
}
void Person::displayDetails() {
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Gender: " << gender << endl;
    cout << "Birthday: " << birthday << endl;
}
void Student::inputData() {
    Person::inputData();
    cout << "Student No: ";
    cin >> studentNo;
    cout << "School Name: ";
    cin >> schoolName;
    cout << "Class: ";
    cin >> classIn;
}
void Student::displayDetails() {
    Person::displayDetails();
    cout << "Student No: " << studentNo << endl;
    cout << "School Name: " << schoolName << endl;
    cout << "Class: " << classIn << endl;
}
void Teacher::inputData() {
    Person::inputData();
    cout << "Teacher No: ";
    cin >> teacherNo;
    cout << "School Name: ";
    cin >> schoolName;
    cout << "Department: ";
    cin >> department;
}
void Teacher::displayDetails() {
    Person::displayDetails();
    cout << "Teacher No: " << teacherNo << endl;
    cout << "School Name: " << schoolName << endl;
    cout << "Department: " << department << endl;
}
void UnderGraduate::inputData() {
    Student::inputData();
    cout << "Major: ";
    cin >> major;
}
void UnderGraduate::displayDetails() {
    Student::displayDetails();
    cout << "Major: " << major << endl;
}
void Graduate::inputData() {
    Student::inputData();
    cout << "Direction: ";
    cin >> direction;
    cout << "Adviser Name: ";
    cin >> adviserName;
}
void Graduate::displayDetails() {
    Student::displayDetails();
    cout << "Direction: " << direction << endl;
    cout << "Adviser Name: " << adviserName << endl;
}
void TA::inputData() {
    Graduate::inputData();
    cout << "Teacher No: ";
    cin >> teacherNo;
    cout << "Department: ";
    cin >> department;
}
void TA::displayDetails() {
    Graduate::displayDetails();
    cout << "Teacher No: " << teacherNo << endl;
    cout << "Department: " << department << endl;
}
