#include <iostream>
#include <fstream>
#include <cstdio>

/* User defined class */


using namespace std;

/* FixedFieldBuffer test using Student instances */
void FFBSaveStudentInstance();
void FFBLoadStudentInstance();

/* DelimFieldBuffer test using Student instances */
void DFBSaveStudentInstance();
void DFBLoadStudentInstance();

/* BufferFile test using Student instances */
void FFBBufferFileSaveStudentInstance();
void FFBBufferFileLoadStudentInstance();

void DFBBufferFileSaveStudentInstance();
void DFBBufferFileLoadStudentInstance();

int main() {
    cout << "Hello!" << endl;
    FFBBufferFileSaveStudentInstance();
    
    FFBBufferFileLoadStudentInstance();
}