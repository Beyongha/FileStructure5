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

int main() {
    DFBSaveStudentInstance();
    
    DFBLoadStudentInstance();
}