#include "TextIndex.h"
#include "Student.h"
#include "FixedFieldBuffer.h"
#include "DelimFieldBuffer.h"

#include <iostream>
#include <string>

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

using namespace std;



void FFBTestTextIndex() {
    TextIndex textIndex(100, 1);
    
    
    // Student 가 Pack할 때 자기 위치를 return 하도록 개선하자.
    /* Insert test */
    std1.Pack(fb);
    textIndex.Insert(std1.GetName(), fb.GetFieldSize() * NUMOFSTUDENTMEMBER);
    textIndex.Print(cout);
    
    std2.Pack(fb);
    textIndex.Insert(std2.GetName(), fb.GetFieldSize() * NUMOFSTUDENTMEMBER * 2);
    textIndex.Print(cout);
    
    std3.Pack(fb);
    textIndex.Insert(std3.GetName(), fb.GetFieldSize() * NUMOFSTUDENTMEMBER * 3);
    textIndex.Print(cout);
    
    /* Search Test */
    cout << textIndex.Search(std2.GetName()) << endl;
    
    
    /* Remove test */
    textIndex.Remove(std2.GetName());
    textIndex.Print(cout);
    
    textIndex.Remove(std1.GetName());
    textIndex.Print(cout);
    
}