#ifndef TextIndexBuffer_h
#define TextIndexBuffer_h

#include "FixedFieldBuffer.h"
#include "TextIndex.h"
#include "classType.h"
#include <iostream>

using namespace std;

class TextIndexBuffer : public FixedFieldBuffer {
protected:
    int MaxKeys;
    int KeySize;
    char* Dummy;
    
    void SetMaxKeys(int);
    void SetKeySize(int);
    void SetDummy();
    
public:
    TextIndexBuffer(int _keySize, int _maxKeys = 100, int extraFields = 0, int extraSize=0);
    
    
    /* Methods */
    int Pack(const TextIndex&);
    int Unpack(TextIndex&);
    void Print(ostream&);
    
    
    /*  Validator */
    void ValidateInput(const int, const char*);
    void ValidateInput(const int, const int);   // 정수의 범위를 검증함.
    void ValidateInput(const int);

    
    ~TextIndexBuffer();
};

#endif /* TextIndexBuffer_h */
