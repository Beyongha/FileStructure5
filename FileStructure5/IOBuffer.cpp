#include "classType.h"
#include "Buffer.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>

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
    
}
IOBuffer::IOBuffer() { }

void IOBuffer::Clear() { this->Offset = 0; }

void IOBuffer::WriteHeader(ostream& os) {
    int instBufferSize = 5;
    char instBuffer[instBufferSize];
    
    memset(instBuffer, '\0', instBufferSize);
    strcpy(instBuffer, intToString(classType));
    os.write(instBuffer, instBufferSize);
    
    cout << instBuffer << endl;
    
    memset(instBuffer, '\0', instBufferSize);
    strcpy(instBuffer, intToString(MaxSize));
    
    cout << instBuffer << endl;
    
    os.write(instBuffer, instBufferSize);
}
void IOBuffer::ReadHeader(istream& is) {
    int instBufferSize = 5;
    char instBuffer[instBufferSize];
    
    memset(instBuffer, '\0', instBufferSize);
    is.read(instBuffer, instBufferSize);
    this->classType = static_cast<ClassType>(atoi(instBuffer));
    
    memset(instBuffer, '\0', instBufferSize);
    is.read(instBuffer, instBufferSize);
    this->MaxSize = atoi(instBuffer);
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
    assert((MaxValue > 0 ) && "MaxValue is Negative or Zero");
    
    /* Check if Value is smaller than MaxValue */
    assert((MaxValue >= Value) && "MaxValue is smaller than Value");
}
void IOBuffer::ValidateInput(const int Value) {
    /* Check if Value is negative */
    assert((Value >= 0) && "Value is Zero");
}

IOBuffer::~IOBuffer() {
    // 왜 SIGABRT가 뜨는지 모르겠음.
    //delete[] Buffer;
}