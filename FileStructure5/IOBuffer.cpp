#include "classType.h"
#include "IOBuffer.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

using namespace std;
/*
 class IOBuffer {
 protected:
 ClassType classType;
 char* Buffer;           // 문자열 저장하는 버퍼
 int MaxSize;            // 버퍼의 최대 길이
 int Offset;             // pack의 오프셋.
 */

char* intToString(int number);

/* Setter */
void IOBuffer::SetBuffer(int _bufferSize) {
    assert((_bufferSize >= 0) && "_BufferSize is negative");
    
    this->Buffer = new char[_bufferSize];
    memset(Buffer, '\0', _bufferSize);
}
void IOBuffer::SetMaxSize(int _newSize) {
    assert((_newSize >= 0) && "_newSize is negative");
    
    this->MaxSize = _newSize;
}
void IOBuffer::SetOffset(int newOffset) {
    ValidateInput(this->MaxSize, newOffset);
    
    this->Offset = newOffset;
}
void IOBuffer::SetClassType(ClassType _classType) {
    this->classType = _classType;
}

IOBuffer::IOBuffer(int _maxSize) {
    SetBuffer(_maxSize);
    SetMaxSize(_maxSize);
    SetOffset(0);
    SetClassType(IOBUFFER);
    HeaderSize = 10;
}
IOBuffer::IOBuffer() {
    SetOffset(0);
    HeaderSize = 10;
}

void IOBuffer::Clear() { this->Offset = 0; }

void IOBuffer::WriteHeader(ostream& os) {
    int instBufferSize = 5;
    os.width(instBufferSize); os.fill('\0'); os << left << classType;
    
    os.width(instBufferSize); os.fill('\0'); os << left << MaxSize;
}
void IOBuffer::ReadHeader(istream& is) {
    int instBufferSize = 5;
    char inst[instBufferSize];
    
    is.read(inst, instBufferSize);
    classType = static_cast<ClassType>(atoi(inst));
    
    is.read(inst, instBufferSize);
    MaxSize = atoi(inst);
    
    SetBuffer(MaxSize);
}


void IOBuffer::ValidateInput(const int MaxSize, const char* String) {
    /* strlen error occured */
    assert((strlen(String) > 0) && "strlen(String) is Negative or Zero");
    
    /* MaxSize range error */
    assert((MaxSize > 0 ) && "MaxSize is Negative or Zero");
    
    /* Overflow occured */
    assert((MaxSize >= strlen(String)) && "strlen(String) is greater than MaxSize");
    
}
void IOBuffer::ValidateInput(const int MaxValue, const int Value) {
    /* Check if Value is negative */
    assert((Value >= 0) && "Value is Zero");
    
    /* Check if MaxValue is valid */
    assert((MaxValue >= 0 ) && "MaxValue is Negative or Zero");
    
    /* Check if Value is smaller than MaxValue */
    assert((MaxValue >= Value) && "MaxValue is smaller than Value");
}
void IOBuffer::ValidateInput(const int Value) {
    /* Check if Value is negative */
    assert((Value >= 0) && "Value is Zero");
}

/* Getter */
char* IOBuffer::GetBuffer() const { return this->Buffer; }
int IOBuffer::GetMaxSize() const { return this->MaxSize; }
int IOBuffer::GetOffset() const { return this->Offset; }

ClassType IOBuffer::GetClassType() const { return this->classType; }


IOBuffer::~IOBuffer() {
    // 왜 SIGABRT가 뜨는지 모르겠음.
    //delete[] Buffer;
}