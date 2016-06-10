#include "BufferFile.h"
#include "classType.h"
#include "IOBuffer.h"

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

int BufferFile::Open(const char* _name) {
    assert(strcmp(_name, "") && "_name is null");
    
    File.open(_name, ios::in);
    
    Buffer.ReadHeader(File);
    return 1;
}
int BufferFile::Create(const char* _name) {
    assert(strcmp(_name, "") && "_name is null");
    
    File.open(_name, ios::out | ios::trunc);
    
    Buffer.WriteHeader(File);
    return 1;
}
int BufferFile::Close() {
    if(IsFileOpened(File)) {
        File.close();
        return 1;
    }
    else return 0;
}
int BufferFile::Rewind() {
    IsFileOpened(File);
    
    File.seekp(0, ios::beg);
    File.seekp(0, ios::beg);
    
    return 1;
}

/* 내가 Read, Write에 대해 편견을 가지고 있었음.
 Open할 때 FileStream을 가지고 있고, Buffer는 외부에서 record를 따로 받을 수 있음.
 */

int BufferFile::Read(int Address) {
    IsFileOpened(File);
    if( Address == -1 ) {
        Buffer.Read(File);
        return 0;
    } else {
        Buffer.DRead(File, Address);
        return Address;
    }
}
int BufferFile::Write(int Address) {
    IsFileOpened(File);
    if( Address == -1 ) {
        Buffer.Write(File);
        return -1;
    } else {
        Buffer.DWrite(File, Address);
        return Address;
    }
}
int BufferFile::Append() {
    File.seekp(0, ios::end);
    
    /* 버퍼에 있는 것들을 file에 씀 */
    Buffer.Write(File);
    //Buffer.Clear();
    return 1;
}

int BufferFile::IsFileOpened(fstream& File) {
    if(File.is_open()) return 1;
    else {
        assert(0 && "File is closed");
        return 0;
    }
}


IOBuffer& BufferFile::GetBuffer() {
    return this->Buffer;
}
const char* BufferFile::GetFileName() const {
    return this->FileName;
}
const ClassType BufferFile::GetClassType() const {
    return this->classType;
}

fstream& BufferFile::GetFile() { return this->File; }

BufferFile::~BufferFile() { }
