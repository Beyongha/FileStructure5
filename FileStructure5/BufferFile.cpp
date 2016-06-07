#include "BufferFile.h"
#include "classType.h"
#include "Buffer.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>

using namespace std;

/*
 class BufferFile {
 protected:
 classType ClassType;
 
 IOBuffer Buffer;
 fstream File;
 char* FileName;
 // header
 
 void SetClassType(ClassType _classType);
 void SetName(const char* _name);
 public:
 BufferFile(IOBuffer& _buffer);
 
 virtual int Open(char* _name);
 virtual int Create(char* _name);
 virtual int Close();
 virtual int rewind();
 virtual int Read();
 virtual int Write();
 virtual int Append( record );


const IOBuffer& GetBuffer() const;
const char* GetFileName() const;
cosnt ClassType GetClassType() const;


~BufferFile();
};
*/