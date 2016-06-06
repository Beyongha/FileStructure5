#include "Student.h"
#include "FixedFieldBuffer.h"
#include "DelimFieldBuffer.h"

#include <iostream>
#include <fstream>

Student std1 = Student("201424546", "JIN", "geyongnam", 14, 85);
Student std2 = Student("111122222", "HA", "pusan", 11, 112);
Student std3 = Student("123453213", "LEE", "geumjung", 12, 123);

Student std4 = Student();
Student std5 = Student();
Student std6 = Student();


void FFBSaveStudentInstance() {
    FixedFieldBuffer fb(StudentFieldSize, NUMOFSTUDENTMEMBER * 3);
    std1.Pack(fb);
    std2.Pack(fb);
    std3.Pack(fb);
    
    ofstream file;
    file.open("student.txt", ios::out | ios::trunc);
    fb.Write(file);
    file.close();
}

void FFBLoadStudentInstance() {
    ifstream file;
    file.open("student.txt", ios::in);
    
    FixedFieldBuffer fb;
    fb.Read(file);
    
    std4.Unpack(fb);
    std5.Unpack(fb);
    std6.Unpack(fb);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;
}

void DFBSaveStudentInstance() {
    DelimFieldBuffer db(1024);
    std1.Pack(db);
    std2.Pack(db);
    std3.Pack(db);
    
    ofstream file;
    file.open("student.txt", ios::out | ios::trunc);
    db.Write(file);
    file.close();
}

void DFBLoadStudentInstance() {
    ifstream file;
    file.open("student.txt", ios::in);
    
    DelimFieldBuffer db;
    db.Read(file);
    
    std4.Unpack(db);
    std5.Unpack(db);
    std6.Unpack(db);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;
}