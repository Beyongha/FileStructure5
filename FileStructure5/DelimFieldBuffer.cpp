#include "DelimFieldBuffer.h"
#include "classType.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

char* intToString(int);



/* Constructor */
DelimFieldBuffer::DelimFieldBuffer(int _MaxSize)
: IOBuffer(_MaxSize) {
    SetClassType(DELIMFIELDBUFFER);
}

DelimFieldBuffer::DelimFieldBuffer() : IOBuffer() {
    SetClassType(DELIMFIELDBUFFER);
}

    /* Virtual functions */
int DelimFieldBuffer::Pack(const char* Field) {
    ValidateInput(this->MaxSize, Field);
    
    strcpy(this->Buffer + this->Offset, Field);
    this->Offset += strlen(Field);
    
    strcpy(this->Buffer + this->Offset, Delim);
    this->Offset += strlen(Delim);
    
    return 1;
}
int DelimFieldBuffer::Pack(const int& Value){
    return DelimFieldBuffer::Pack(intToString(Value));
}

int DelimFieldBuffer::Unpack(char* Field, int FieldSize){
    ValidateInput(MaxSize, FieldSize);
    
    int i;
    for(i = 0; i < FieldSize ; ++ i, this->Offset += 1) {
        if(this->Buffer[Offset] != *Delim ) {
            Field[i] = this->Buffer[Offset];
        }
        else {
            this->Offset += 1;
            break;
        }
    }
    Field[i] = '\0';
    
    return 1;
}
int DelimFieldBuffer::Unpack(int& Value){
    char* numBuffer = new char[this->MaxSize];
    DelimFieldBuffer::Unpack(numBuffer, this->MaxSize);
    
    Value = atoi(numBuffer);
    return 1;
}

int DelimFieldBuffer::DPack(const char* String, int Address) {
    ValidateInput(this->MaxSize, String);
    
    strcpy(this->Buffer + Address, String);
    strcpy(this->Buffer + Address + strlen(String), Delim);
    /* 문제점: 이렇게 하면 한 필드가 2개로 쪼개지거나, 다른 필드를 침범할 가능성이 있음.
        밀거나 당기거나 해줘야 하는데 어떻게?
        설마 insert인가? 설마 이걸 구현해야 하는가? ㅅㅂ
    */
    
    
    return 1;
}
int DelimFieldBuffer::DPack(const int& Value, int Address){
    return DelimFieldBuffer::DPack(intToString(Value), Address);
}

int DelimFieldBuffer::DUnpack(char* Field, int FieldSize, int Address){
    ValidateInput(MaxSize, FieldSize);
    ValidateInput(MaxSize, Address);
    
    int i;
    for(i = 0; i < FieldSize ; ++ i, Address += 1) {
        if(this->Buffer[Address] != *Delim ) {
            Field[i] = this->Buffer[Address];
        }
        else {
            Address += 1;
            break;
        }
    }
    Field[i] = '\0';
    
    return 1;
}
int DelimFieldBuffer::DUnpack(int& Value, int Address){
    char* numBuffer = new char[this->MaxSize];
    DelimFieldBuffer::DUnpack(numBuffer, this->MaxSize, Address);
    
    Value = atoi(numBuffer);
    delete[] numBuffer;
    return 1;
}

void DelimFieldBuffer::Write(ostream& os){
    os.write(this->Buffer, this->MaxSize);
}
void DelimFieldBuffer::Read(istream& is){
    is.read(this->Buffer, this->MaxSize);
}

void DelimFieldBuffer::DWrite(ostream& os, int Address) {
    ValidateInput(MaxSize, Address);
    os.write(this->Buffer + Address, this->MaxSize - Address);
}
void DelimFieldBuffer::DRead(istream& is, int Address) {
    ValidateInput(MaxSize, Address);
    is.seekg(Address + HeaderSize);
    
    is.read(this->Buffer, this->MaxSize - Address);
}


void DelimFieldBuffer::Clear(){ IOBuffer::Clear(); }

/* Getter */
const char* DelimFieldBuffer::GetDelim() const { return this->Delim; }
    
void DelimFieldBuffer::WriteHeader(ostream& os) {
    IOBuffer::WriteHeader(os);
}
void DelimFieldBuffer::ReadHeader(istream& is) {
    IOBuffer::ReadHeader(is);
}

/* Validator */
void DelimFieldBuffer::ValidateInput(const int MaxSize, const char* Field) {
    IOBuffer::ValidateInput(MaxSize, Field);
    
    for( int i = 0; i < strlen(Field); ++ i ) {
        assert((Field[i] != *Delim) && "Exhibited character included");
    }
}
void DelimFieldBuffer::ValidateInput(const int MaxValue, const int Value){
    IOBuffer::ValidateInput(MaxValue, Value);
}
void DelimFieldBuffer::ValidateInput(const int Value) {
    IOBuffer::ValidateInput(Value);
}



/* Destuctor */
DelimFieldBuffer::~DelimFieldBuffer() { }