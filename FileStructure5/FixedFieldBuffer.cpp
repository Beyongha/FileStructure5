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
    SetClassType(FIXEDFIELDBUFFER);
}
FixedFieldBuffer::FixedFieldBuffer() : IOBuffer() {
    SetClassType(FIXEDFIELDBUFFER);
}


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

int FixedFieldBuffer::DPack(const char* String, int Address) {
    ValidateInput(FieldSize, String);
    ValidateInput(MaxSize, Address);
    
    memset(this->Buffer + Address, '\0', FieldSize - (Address % FieldSize));
    strncpy(this->Buffer + Address, String, FieldSize - (Address % FieldSize));
    return 1;
}
int FixedFieldBuffer::DPack(const int& Value, int Address){
    ValidateInput(MaxSize, Address);
    return FixedFieldBuffer::DPack(intToString(Value), Address);
}

int FixedFieldBuffer::DUnpack(char* Field, int EmptyFieldSize, int Address){
    /* Check */
    ValidateInput(FieldSize, EmptyFieldSize);
    ValidateInput(MaxSize, Address);
    
    memset(Field, '\0', EmptyFieldSize);
    strncpy(Field, this->Buffer + Address, this->FieldSize - (Address % FieldSize));
    
    return 1;
}
int FixedFieldBuffer::DUnpack(int& Value, int Address){
    ValidateInput(MaxSize, Address);
    char* numBuffer = new char[this->FieldSize - (Address % FieldSize)];
    FixedFieldBuffer::DUnpack(numBuffer, FieldSize - (Address % FieldSize), Address);
    
    Value = atoi(numBuffer);
    delete[] numBuffer;
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
    os.width(instBufferSize); os.fill('\0'); os << left << FieldSize;
    
    os.width(instBufferSize); os.fill('\0'); os << left << MaxNumberOfField;
}
void FixedFieldBuffer::ReadHeader(istream& is) {
    IOBuffer::ReadHeader(is);
    
    int instBufferSize = 5;
    char inst[instBufferSize];
    
    is.read(inst, instBufferSize);
    this->FieldSize = atoi(inst);
    
    is.read(inst, instBufferSize);
    this->MaxNumberOfField = atoi(inst);
    
}

void FixedFieldBuffer::Clear() { IOBuffer::Clear(); }

/* Validator */
void FixedFieldBuffer::ValidateInput(const int MaxSize, const char* Field) {
    IOBuffer::ValidateInput(MaxSize, Field);
}
void FixedFieldBuffer::ValidateInput(const int MaxValue, const int Value){
    IOBuffer::ValidateInput(MaxValue, Value);
}
void FixedFieldBuffer::ValidateInput(const int Value) {
    IOBuffer::ValidateInput(Value);
}


/* Getter */
int FixedFieldBuffer::GetFieldSize(){ return this->FieldSize; }
int FixedFieldBuffer::GetMaxNumberOfField(){ return this->MaxNumberOfField; }


FixedFieldBuffer::~FixedFieldBuffer(){
    IOBuffer::~IOBuffer();
}