#include "FixedFieldBuffer.h"
#include "classType.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

char* intToString(int);

/*
 ClassType classType;
 int FieldSize;
 int MaxNumberOfField;
 */

void FixedFieldBuffer::SetFieldSize(int _newFieldSize) {
    /* Check input */
    IOBuffer::ValidateInput(MaxBufferSize, _newFieldSize);
    
    this->FieldSize = _newFieldSize;
}
void FixedFieldBuffer::SetMaxNumberOfField(int _newMaxNumberOfField) {
    /* Check input */
    IOBuffer::ValidateInput(MaxBufferSize, _newMaxNumberOfField);
    
    this->MaxNumberOfField = _newMaxNumberOfField;
}

FixedFieldBuffer::FixedFieldBuffer(int _fieldSize, int _maxNumberOfField)
: IOBuffer(_fieldSize * _maxNumberOfField){
    SetFieldSize(_fieldSize);
    SetMaxNumberOfField(_maxNumberOfField);
}
FixedFieldBuffer::FixedFieldBuffer() : IOBuffer() {}


int FixedFieldBuffer::Pack(const char* String){
    /* Check input */
    ValidateInput(this->FieldSize, String);
    
    /* Check if there is space */
    assert((MaxNumberOfField * FieldSize > Offset) && "Offset Overflowed!!");
    
    memset(this->Buffer + Offset, '\0', FieldSize);
    strcpy(this->Buffer + Offset, String);
    
    this->Offset += FieldSize;
    return 1;
}
int FixedFieldBuffer::Pack(const int& Value){
    return FixedFieldBuffer::Pack(intToString(Value));
}

int FixedFieldBuffer::Unpack(char* Field, int EmptyFieldSize){
    /* Check */
    ValidateInput(FieldSize, EmptyFieldSize);
    
    memset(Field, '\0', EmptyFieldSize);
    strncpy(Field, this->Buffer + Offset, EmptyFieldSize);
    this->Offset += FieldSize;
    return 1;
}
int FixedFieldBuffer::Unpack(int& Value){
    char* numBuffer = new char[this->FieldSize];
    FixedFieldBuffer::Unpack(numBuffer, FieldSize);
    
    Value = atoi(numBuffer);
    return 1;
}

void FixedFieldBuffer::Write(ostream& os){
    WriteHeader(os);
    
    os.write(this->Buffer, this->MaxSize);
}
void FixedFieldBuffer::Read(istream& is){
    ReadHeader(is);
    
    is.read(this->Buffer, this->MaxSize);
}

void FixedFieldBuffer::WriteHeader(ostream& os) {
    IOBuffer::WriteHeader(os);
    
    int instBufferSize = 5;
    char instBuffer[instBufferSize];
    
    memset(instBuffer, '\0', instBufferSize);
    strcpy(instBuffer, intToString(FieldSize));
    os.write(instBuffer, FieldSize);
    
    memset(instBuffer, '\0', instBufferSize);
    strcpy(instBuffer, intToString(MaxNumberOfField));
    os.write(instBuffer, FieldSize);
}
void FixedFieldBuffer::ReadHeader(istream& is) {
    IOBuffer::ReadHeader(is);
    
    int instBufferSize = 5;
    char instBuffer[instBufferSize];
    
    memset(instBuffer, '\0', instBufferSize);
    is.read(instBuffer, instBufferSize);
    this->FieldSize = atoi(instBuffer);
    
    memset(instBuffer, '\0', instBufferSize);
    is.read(instBuffer, instBufferSize);
    this->MaxNumberOfField = atoi(instBuffer);
}

int FixedFieldBuffer::GetFieldSize(){ return this->FieldSize; }
int FixedFieldBuffer::GetMaxNumberOfField(){ return this->MaxNumberOfField; }


FixedFieldBuffer::~FixedFieldBuffer(){
    IOBuffer::~IOBuffer();
}