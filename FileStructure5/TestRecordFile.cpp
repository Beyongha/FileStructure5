#include "FixedFieldBuffer.h"
#include "DelimFieldBuffer.h"
#include "Student.h"
#include "BufferFile.h"
#include "RecordFile.h"
#include "classType.h"

#include <iostream>
#include <fstream>

using namespace std;

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


extern char* fileName1;


void FFBRecordFileSaveStudentInstance() {
    FixedFieldBuffer fb(StudentFieldSize, NUMOFSTUDENTMEMBER * 3);
    
    RecordFile<Student> recordFile(fb);
    recordFile.Create(fileName1);
    recordFile.Append(std1);
    recordFile.Append(std2);
    recordFile.Append(std3);
    
    recordFile.Close();
}


void FFBRecordFileLoadStudentInstance() {
    FixedFieldBuffer fb;
    
    RecordFile<Student> recordFile(fb);
    recordFile.Open(fileName1);
    
    recordFile.Read(std4);
    recordFile.Read(std5);
    recordFile.Read(std6);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;
}


void DFBRecordFileSaveStudentInstance() {
    DelimFieldBuffer db(1024);
    
    RecordFile<Student> recordFile(db);
    recordFile.Create(fileName1);
    recordFile.Append(std1);
    recordFile.Append(std2);
    recordFile.Append(std3);
    
    recordFile.Close();
    
}

void DFBRecordFileLoadStudentInstance() {
    DelimFieldBuffer db;
    
    RecordFile<Student> recordFile(db);
    recordFile.Open(fileName1);
    
    recordFile.Read(std4);
    recordFile.Read(std5);
    recordFile.Read(std6);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;

}
