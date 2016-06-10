#include "TextIndex.h"

#include <string>
#include <cassert>
#include <iostream>
#include <cstring>

/*
    ClassType classType;
    int MaxKeys;
    int NumKeys;
    char** Keys;
    int* Addresses;

    int Unique;
*/

/* Private methods */
int TextIndex::Find(const string& key) const {
    /* Binary Search */
    int start = 0, end = NumKeys -1;
    int mid = (start + end) / 2;
    
    for(; start <= end; mid = (start + end ) / 2) {
        if( key == Keys[mid]) return mid;
        else if( Keys[mid] > key) end = mid -1;
        else start = mid + 1;
    }
    
    
    /* Linear Search
    for( int i = 0; i < NumKeys; ++ i ) {
        if( Keys[i] == key) return i;       // Key found
    }
     */
    return -1;      // Not found
     
}
int TextIndex::Init(int maxKeys, int unique) {
    ValidateInput(maxKeys);
    SetMaxKeys(maxKeys);
    SetKeys(maxKeys);
    SetAddresses(maxKeys);
    SetUnique(unique);
    return 1;
}


/* Setter */
void TextIndex::SetMaxKeys(int _maxKeys) {
    ValidateInput(_maxKeys);
    this->MaxKeys = _maxKeys;
}
void TextIndex::SetNumKeys(int _numKeys){
    ValidateInput(MaxKeys, _numKeys);
    
    this->NumKeys = _numKeys;
}
void TextIndex::SetKeys(int _maxSize){
    ValidateInput(_maxSize);
    
    assert(this->MaxKeys == _maxSize && "MaxKeys is different with _maxSize");
    
    Keys = new string[_maxSize];
}
void TextIndex::SetAddresses(int _maxSize){
    ValidateInput(_maxSize);
    
    assert(this->MaxKeys == _maxSize && "MaxKeys is different with _maxSize");
    
    Addresses = new int[_maxSize];
}
void TextIndex::SetUnique(int _unique) {
    Unique = _unique != 0;
    this->Unique = _unique;
}
void TextIndex::SetClassType(ClassType _classType) {
    this->classType = _classType;
}

TextIndex::TextIndex(int _maxKeys, int _unique){
    Init(_maxKeys, _unique);
    SetNumKeys(0);
    SetClassType(TEXTINDEX);
}
    
    
/* Validator */
void TextIndex::ValidateInput(const int MaxSize, const char* String) {
    /* strlen error occured */
    assert((strlen(String) > 0) && "strlen(String) is Negative or Zero");
        
    /* MaxSize range error */
    assert((MaxSize > 0 ) && "MaxSize is Negative or Zero");
        
    /* Overflow occured */
    assert((MaxSize >= strlen(String)) && "strlen(String) is greater than MaxSize");
    
}
void TextIndex::ValidateInput(const int MaxValue, const int Value) {
    /* Check if Value is negative */
    assert((Value >= 0) && "Value is Zero");
        
    /* Check if MaxValue is valid */
    assert((MaxValue > 0 ) && "MaxValue is Negative or Zero");
        
    /* Check if Value is smaller than MaxValue */
    assert((MaxValue >= Value) && "MaxValue is smaller than Value");
}
void TextIndex::ValidateInput(const int Value) {
    /* Check if Value is negative */
    assert((Value > 0) && "Value is Zero");
}

/* Methods */
int TextIndex::Insert(const string key, int Address) {
    int i;
    int index = Find(key);
    
    /* Check if possible */
    if( Unique && index >= 0) return 0;
    if( NumKeys == MaxKeys) return 0;
    
    for(i = NumKeys -1; i >= 0; --i) {
        if( key > Keys[i]) break;
        Keys[i+1] = Keys[i];
        Addresses[i+1] = Addresses[i];
    }
    
    Keys[i+1] = string(key);
    Addresses[i+1] = Address;
    NumKeys ++;
    return 1;
}
int TextIndex::Remove(const string key) {
    int index = Find(key);
    if( index < 0 ) return 0;
    // i < NumKeys-1 아닌가?
    for( int i = index; i < NumKeys; ++ i ) {
        Keys[i] = Keys[i+1];
        Addresses[i] = Addresses[i+1];
    }
    NumKeys--;
    return 1;
}
int TextIndex::Search(const string key) {
    int index = Find(key);
    if( index < 0) return -1;
    return Addresses[index];
}
void TextIndex::Print(ostream& os) const {
    os << "Text Index max keys " << MaxKeys
    << " num Keys " << NumKeys << endl;
    
    for(int i = 0; i < NumKeys; ++ i ) {
        os << "\tKey[" << i << "] " << Keys[i]
        << " Addresses " << Addresses[i] << endl;
    }
}

/* Getter */
int TextIndex::GetMaxKeys() const { return this->MaxKeys;}
int TextIndex::GetNumKeys() const { return this->NumKeys; }
int TextIndex::GetUnique() const { return this->Unique; }
ClassType TextIndex::GetClassType() const { return this->classType; }


/* Desturctor */
TextIndex::~TextIndex() {
    delete[] Keys;
    delete[] Addresses;
}

