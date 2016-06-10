#include "Student.h"
#include "IOBuffer.h"
#include "FixedFieldBuffer.h"
#include "DelimFieldBuffer.h"

/* FFB */
FixedFieldBuffer fb(StudentFieldSize, NUMOFSTUDENTMEMBER * 3);

/* DFB */
DelimFieldBuffer db(1024);

/* TextIndexedFileInstance.cpp */
DelimFieldBuffer db1(StudentFieldSize * NUMOFSTUDENTMEMBER * 40 * 2);
DelimFieldBuffer db2(StudentFieldSize * NUMOFSTUDENTMEMBER * 40 * 2);
DelimFieldBuffer db3(StudentFieldSize * NUMOFSTUDENTMEMBER * 40 * 2);
DelimFieldBuffer db4(StudentFieldSize * NUMOFSTUDENTMEMBER * 40 * 2);
DelimFieldBuffer db5(StudentFieldSize * NUMOFSTUDENTMEMBER * 40 * 2);
DelimFieldBuffer db6(StudentFieldSize * NUMOFSTUDENTMEMBER * 40 * 2);