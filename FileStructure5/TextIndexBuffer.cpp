#include "TextIndexBuffer.h"
#include "classtype.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 class TextIndexBuffer : public FixedFieldBuffer {
 protected:
 int MaxKeys;
 int KeySize;
 char* Dummy;
 
 int Pack(const TextIndex&);
 int Unpack(TextIndex&);
 void Print(ostream&) const;
 
 ~TextIndexBuffer();
 };
*/

//FixedFieldBuffer::FixedFieldBuffer(int _fieldSize, int _maxNumberOfField)

void TextIndexBuffer::SetMaxKeys(int _maxKeys) {
    ValidateInput(_maxKeys);
    this->MaxKeys = _maxKeys;
}
void TextIndexBuffer::SetKeySize(int _keySize) {
    ValidateInput(_keySize);
    this->KeySize = _keySize;
}
void TextIndexBuffer::SetDummy() {
    ValidateInput(KeySize);
    this->Dummy = new char[KeySize];
    memset(Dummy, '\0', KeySize);
}


TextIndexBuffer::TextIndexBuffer(int _keySize, int _maxKeys, int extraFields, int extraSize)
: FixedFieldBuffer( _keySize + extraSize, 1 + _maxKeys * 2 + extraFields){
    SetMaxKeys(_maxKeys);
    SetKeySize(_keySize);
    SetDummy();
    SetClassType(TEXTINDEXBUFFER);
}

/* Methods */
int TextIndexBuffer::Pack(const TextIndex& index) {
    Clear();
    int result;
    result = FixedFieldBuffer::Pack(index.GetNumKeys());
    
    for(int i = 0; i < index.GetNumKeys(); ++ i ) {
        result = result && FixedFieldBuffer::Pack(index.Keys[i].c_str());
        result = result && FixedFieldBuffer::Pack(index.Addresses[i]);
    }
    return result;
}
int TextIndexBuffer::Unpack(TextIndex& index) {
    int result;
    result = FixedFieldBuffer::Unpack(index.NumKeys);
    
    for(int i = 0; i < index.GetNumKeys(); ++ i ) {
        char* instance = new char[KeySize];
        result = result && FixedFieldBuffer::Unpack(instance, KeySize);
        string* instString = new string(instance);
        index.Keys[i] = *instString;
        
        result = result && FixedFieldBuffer::Unpack(index.Addresses[i]);
    }
    return result;
}
void TextIndexBuffer::Print(ostream& os) {
    os << "TextIndexBuffer: KeySize " << KeySize
    << " MaxKeys " << MaxKeys << endl;
    
    FixedFieldBuffer::Print(os);
}


/*  Validator */
void TextIndexBuffer::ValidateInput(const int MaxSize, const char* String) {
    FixedFieldBuffer::ValidateInput(MaxSize, String);
}
void TextIndexBuffer::ValidateInput(const int MaxValue, const int Value) {
    FixedFieldBuffer::ValidateInput(MaxValue, Value);
}
void TextIndexBuffer::ValidateInput(const int Value) {
    FixedFieldBuffer::ValidateInput(Value);
}


TextIndexBuffer::~TextIndexBuffer() {
    delete[] Dummy;
}