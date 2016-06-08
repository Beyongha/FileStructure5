#include "Student.h"
#include "IOBuffer.h"
#include "FixedFieldBuffer.h"
#include "DelimFieldBuffer.h"

/* FFB */
FixedFieldBuffer fb(StudentFieldSize, NUMOFSTUDENTMEMBER * 3);

/* DFB */
DelimFieldBuffer db(1024);