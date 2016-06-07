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

// append, rewind 수정필요함.

/*
 class BufferFile {
 protected:
 ClassType classType;
 
 IOBuffer& Buffer;
 fstream File;
 char* FileName;

*/

void BufferFile::SetName(const char* _name) {
    strcpy(this->FileName, _name);
}

void BufferFile::SetClassType(ClassType _classType) {
    this->classType = _classType;
}

BufferFile::BufferFile(IOBuffer& _buffer)
: Buffer(_buffer) {
    SetClassType(BUFFERFILE);
}

int BufferFile::Open(char* _name) {
    assert(!strcmp(_name, "") && "_name is null");
    
    File.open(_name, ios::in);
    return 1;
}
int BufferFile::Create(char* _name) {
    assert(!strcmp(_name, "") && "_name is null");
    
    File.open(_name, ios::out | ios::trunc);
    return 1;
}
int BufferFile::Close() {
    if(IsFileOpened(File)) {
        File.close();
        return 1;
    }
    else return 0;
}
int BufferFile::rewind() {
    /* rewind에 대한 정확한 정의가 필요함.
     Buffer를 rewind 할 것인가
     File을 rewind할 것인가.
     */
    
    return 1;
}
int BufferFile::Read() {
    if(IsFileOpened(File)) {
        Buffer.Read(File);
        return 1;
    }
    else return 0;
}
int BufferFile::Write() {
    if(IsFileOpened(File)) {
        Buffer.Write(File);
        return 1;
    }
    else return 0;
}
int BufferFile::Append() {
    /* 이부분도 문제임. Record를 넣는건 알겠는데 무슨 Record를? */
    return 1;
}

int BufferFile::IsFileOpened(fstream& File) {
    if(File.is_open()) return 1;
    else {
        assert(0 && "File is closed");
        return 0;
    }
}


const IOBuffer& BufferFile::GetBuffer() const {
    return this->Buffer;
}
const char* BufferFile::GetFileName() const {
    return this->FileName;
}
const ClassType BufferFile::GetClassType() const {
    return this->classType;
}


BufferFile::~BufferFile() { }
