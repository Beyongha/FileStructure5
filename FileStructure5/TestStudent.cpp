#include "Student.h"
#include "FixedFieldBuffer.h"
#include "DelimFieldBuffer.h"

#include <iostream>
#include <fstream>


/* instancaes in StudentInstance.cpp */
extern Student std1;
extern Student std2;
extern Student std3;

extern Student std4;
extern Student std5;
extern Student std6;

/* instancaes in BufferInstance.cpp */
extern FixedFieldBuffer fb;
extern DelimFieldBuffer db;


void FFBSaveStudentInstance() {
    
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

    fb.Read(file);
    
    std4.Unpack(fb);
    std5.Unpack(fb);
    std6.Unpack(fb);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;
}

void DFBSaveStudentInstance() {
    
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
    
    db.Read(file);
    
    std4.Unpack(db);
    std5.Unpack(db);
    std6.Unpack(db);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;
}