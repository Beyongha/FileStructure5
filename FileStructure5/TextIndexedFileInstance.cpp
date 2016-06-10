#include "TextIndexedFile.h"
#include "Student.h"
#include "DelimFieldBuffer.h"


extern DelimFieldBuffer db1;
extern DelimFieldBuffer db2;
extern DelimFieldBuffer db3;
extern DelimFieldBuffer db4;
extern DelimFieldBuffer db5;
extern DelimFieldBuffer db6;


TextIndexedFile<Student> textIndexedFile1(db1, StudentFieldSize, 100);
TextIndexedFile<Student> textIndexedFile2(db2, StudentFieldSize, 100);
TextIndexedFile<Student> textIndexedFile3(db3, StudentFieldSize, 100);
TextIndexedFile<Student> textIndexedFile4(db4, StudentFieldSize, 100);
TextIndexedFile<Student> textIndexedFile5(db5, StudentFieldSize, 100);
TextIndexedFile<Student> textIndexedFile6(db6, StudentFieldSize, 100);