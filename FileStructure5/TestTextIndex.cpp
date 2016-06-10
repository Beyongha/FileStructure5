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


/* instance in TextIndexInstance.cpp */
extern TextIndex textIndex;

using namespace std;

void FFBTestTextIndex() {
    /* Insert test */
    int savedAddress = std1.Pack(fb);
    textIndex.Insert(std1.GetName(), savedAddress);
    textIndex.Print(cout);
    
    savedAddress = std2.Pack(fb);
    textIndex.Insert(std2.GetName(), savedAddress);
    textIndex.Print(cout);
    
    savedAddress = std3.Pack(fb);
    textIndex.Insert(std3.GetName(), savedAddress);
    textIndex.Print(cout);
    
    /* 버퍼값 조사 */
    fb.Write(cout);
    
    /* Search Test */
    cout << textIndex.Search(std2.GetName()) << endl;
    
    
    /* Remove test */
    textIndex.Remove(std2.GetName());
    textIndex.Print(cout);
    
    textIndex.Remove(std1.GetName());
    textIndex.Print(cout);
}

void DFBTestTextIndex() {
    // 구현...
}