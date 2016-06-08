#include "FixedFieldBuffer.h"
#include "DelimFieldBuffer.h"
#include "Student.h"
#include "BufferFile.h"
#include "RecordFile.h"
#include "classType.h"

#include <iostream>
#include <fstream>

using namespace std;


Student S1 = Student("201424546", "JIN", "geyongnam", 14, 85);
Student S2 = Student("111122222", "HA", "pusan", 11, 112);
Student S3 = Student("123453213", "LEE", "geumjung", 12, 123);

Student S4 = Student();
Student S5 = Student();
Student S6 = Student();

const char* fileName2 = "student.txt";


void FFBRecordFileSaveStudentInstance() {
    FixedFieldBuffer fb(StudentFieldSize, NUMOFSTUDENTMEMBER * 3);
    
    RecordFile<Student> recordFile(fb);
    recordFile.Create(fileName2);
    recordFile.Append(S1);
    recordFile.Append(S2);
    recordFile.Append(S3);
    
    recordFile.Close();
}


void FFBRecordFileLoadStudentInstance() {
    FixedFieldBuffer fb;
    
    RecordFile<Student> recordFile(fb);
    recordFile.Open(fileName2);
    
    recordFile.Read(S4);
    recordFile.Read(S5);
    recordFile.Read(S6);
    
    cout << S4 << endl;
    cout << S5 << endl;
    cout << S6 << endl;
}


void DFBRecordFileSaveStudentInstance() {
    DelimFieldBuffer db(1024);
    
    RecordFile<Student> recordFile(db);
    recordFile.Create(fileName2);
    recordFile.Append(S1);
    recordFile.Append(S2);
    recordFile.Append(S3);
    
    recordFile.Close();
    
}

void DFBRecordFileLoadStudentInstance() {
    DelimFieldBuffer db;
    
    RecordFile<Student> recordFile(db);
    recordFile.Open(fileName2);
    
    recordFile.Read(S4);
    recordFile.Read(S5);
    recordFile.Read(S6);
    
    cout << S4 << endl;
    cout << S5 << endl;
    cout << S6 << endl;

}
