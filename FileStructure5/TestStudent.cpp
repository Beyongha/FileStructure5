#include "Student.h"
#include "FixedFieldBuffer.h"

#include <iostream>
#include <fstream>



void FFBSaveStudentInstance() {
    Student std1 = Student("201424546", "JIN", "geyongnam", 14, 85);
    Student std2 = Student("111122222", "HA", "pusan", 11, 112);
    Student std3 = Student("123453213", "LEE", "geumjung", 12, 123);
    
    FixedFieldBuffer fb(StudentFieldSize, NUMOFSTUDENTMEMBER * 3);
    std1.Pack(fb);
    std2.Pack(fb);
    std3.Pack(fb);
    
    ofstream file;
    file.open("student.txt");
    fb.Write(file);
    file.close();
}

void FFBLoadStudentInstance() {
    ifstream file2;
    file2.open("student.txt");
    
    FixedFieldBuffer fb2;
    fb2.Read(file2);
    
    Student std4 = Student();
    Student std5 = Student();
    Student std6 = Student();
    
    std4.Unpack(fb2);
    std5.Unpack(fb2);
    std6.Unpack(fb2);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;
}