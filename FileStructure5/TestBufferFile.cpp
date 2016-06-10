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

void FFBBufferFileSaveStudentInstance() {
    FixedFieldBuffer fb(StudentFieldSize, NUMOFSTUDENTMEMBER * 3);
    std1.Pack(fb);
    std2.Pack(fb);
    std3.Pack(fb);
    
    BufferFile bufferFile(fb);
    bufferFile.Create(fileName1);
    bufferFile.Append();
    bufferFile.Close();
}

void FFBBufferFileLoadStudentInstance() {
    FixedFieldBuffer fb;
    BufferFile bufferFile(fb);
    bufferFile.Open(fileName1);
    bufferFile.Read();
    
    std4.Unpack(fb);
    std5.Unpack(fb);
    std6.Unpack(fb);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;
}


void DFBBufferFileSaveStudentInstance() {
    DelimFieldBuffer db(1024);
    std1.Pack(db);
    std2.Pack(db);
    std3.Pack(db);
    
    BufferFile bufferFile(db);
    bufferFile.Create(fileName1);
    bufferFile.Append();
    bufferFile.Close();
}

void DFBBufferFileLoadStudentInstance() {
    DelimFieldBuffer db;
    BufferFile bufferFile(db);
    bufferFile.Open(fileName1);
    bufferFile.Read();
    
    std4.Unpack(db);
    std5.Unpack(db);
    std6.Unpack(db);
    
    cout << std4 << endl;
    cout << std5 << endl;
    cout << std6 << endl;
}
