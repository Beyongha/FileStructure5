//
//  TestBufferFile.cpp
//  FileStructure5
//
//  Created by JIN Beyongha on 2016. 6. 8..
//  Copyright © 2016년 JIN Beyongha. All rights reserved.
//

#include "BufferFile.h"
#include "FixedFieldBuffer.h"
#include "DelimFieldBuffer.h"
#include "Student.h"

#include <iostream>
#include <fstream>

using namespace std;


Student s1 = Student("201424546", "JIN", "geyongnam", 14, 85);
Student s2 = Student("111122222", "HA", "pusan", 11, 112);
Student s3 = Student("123453213", "LEE", "geumjung", 12, 123);

Student s4 = Student();
Student s5 = Student();
Student s6 = Student();

const char* fileName = "student.txt";

void FFBBufferFileSaveStudentInstance() {
    FixedFieldBuffer fb(StudentFieldSize, NUMOFSTUDENTMEMBER * 3);
    s1.Pack(fb);
    s2.Pack(fb);
    s3.Pack(fb);
    
    BufferFile bufferFile(fb);
    bufferFile.Create(fileName);
    bufferFile.Append();
    bufferFile.Close();
}

void FFBBufferFileLoadStudentInstance() {
    FixedFieldBuffer fb;
    BufferFile bufferFile(fb);
    bufferFile.Open(fileName);
    bufferFile.Read();
    
    s4.Unpack(fb);
    s5.Unpack(fb);
    s6.Unpack(fb);
    
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
}


void DFBBufferFileSaveStudentInstance() {
    DelimFieldBuffer db(1024);
    s1.Pack(db);
    s2.Pack(db);
    s3.Pack(db);
    
    BufferFile bufferFile(db);
    bufferFile.Create(fileName);
    bufferFile.Append();
    bufferFile.Close();
}

void DFBBufferFileLoadStudentInstance() {
    DelimFieldBuffer db;
    BufferFile bufferFile(db);
    bufferFile.Open(fileName);
    bufferFile.Read();
    
    s4.Unpack(db);
    s5.Unpack(db);
    s6.Unpack(db);
    
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
}
