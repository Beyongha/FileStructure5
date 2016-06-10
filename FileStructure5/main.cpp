#include <iostream>

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


/* RecordFile Test using Student instances */
void FFBRecordFileSaveStudentInstance();
void FFBRecordFileLoadStudentInstance();


void DFBRecordFileSaveStudentInstance();
void DFBRecordFileLoadStudentInstance();


/* TextIndex test using Student instances */
void FFBTestTextIndex();

/* TextIndexBuffer test using Student instances */
void TestPackTextIndexBuffer();
void TestUnpackTextIndexBuffer();


/* TestTextIndexedFile test using Student instances */
void TestSaveTextIndexedFile1();
void TestSaveTextIndexedFile2();
void TestLoadTextIndexedFile1();
void TestLoadTextIndexedFile2();
void TestSearchTextIndexedFile();

const char* fileName1 = "TestTextIndexedFile1";
const char* fileName2 = "TestTextIndexedFile2";

int main() {
    
    TestSaveTextIndexedFile1();
    TestSaveTextIndexedFile2();
    
    TestLoadTextIndexedFile1();
    TestLoadTextIndexedFile2();
    
    TestSearchTextIndexedFile();
}