#include "TextIndexBuffer.h"
#include "TextIndex.h"
#include "Student.h"

using namespace std;

extern Student std1;
extern Student std2;
extern Student std3;

extern Student std4;
extern Student std5;
extern Student std6;

extern FixedFieldBuffer fb;

extern TextIndexBuffer textIndexBuffer;


void TestPackTextIndexBuffer() {
    
    TextIndex textIndex(100, 1);
    
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
    
    textIndexBuffer.Pack(textIndex);
    
    textIndexBuffer.Print(cout);
    cout << endl;
    
}

void TestUnpackTextIndexBuffer() {
    textIndexBuffer.Clear();
    TextIndex textIndex(100, 1);
    textIndexBuffer.Unpack(textIndex);
    
    textIndex.Print(cout);
}