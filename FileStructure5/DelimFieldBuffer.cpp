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

void DelimFieldBuffer::DPack(const char*, int) {
    
}
void DelimFieldBuffer::DPack(const int&, int){
    
}

void DelimFieldBuffer::DUnpack(char*, int){
    
}
void DelimFieldBuffer::DUnpack(int&, int){
    
}

void DelimFieldBuffer::Write(ostream& os){
    DelimFieldBuffer::WriteHeader(os);
    
    os.write(this->Buffer, this->MaxSize);
}
void DelimFieldBuffer::Read(istream& is){
    DelimFieldBuffer::ReadHeader(is);
    
    is.read(this->Buffer, this->MaxSize);
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