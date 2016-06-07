#ifndef FixedFieldBuffer_h
#define FixedFieldBuffer_h


#include "Buffer.h"
#include "classType.h"

#include <iostream>

using namespace std;

class FixedFieldBuffer : public IOBuffer {
protected:
    ClassType classType;        /* 클래스 타입 */
    
    int FieldSize;              /* 고정 길이 필드의 크기 */
    int MaxNumberOfField;        /* 최대로 이용 가능한 필드 수 */
    
    /* Setter */
    void SetFieldSize(int);
    void SetMaxNumberOfField(int);
public:
    /* Constructor */
    FixedFieldBuffer(int, int);
    FixedFieldBuffer();
    
    /* Virtual functions */
    int Pack(const char*);
    int Pack(const int&);
    
    int Unpack(char*, int);
    int Unpack(int&);
    
    void Write(ostream&);
    void Read(istream&);
    
    int DPack(const char*, int);
    int DPack(const int&, int);
    
    int DUnpack(char*, int, int);
    int DUnpack(int&, int);
    
    void WriteHeader(ostream&);
    void ReadHeader(istream&);
    
    void Clear();
    
    /*  Validator */
    void ValidateInput(const int, const char*);
    void ValidateInput(const int, const int);   // 정수의 범위를 검증함.
    void ValidateInput(const int);

    
    /* Getter */
    int GetFieldSize();
    int GetMaxNumberOfField();
    
    
    /* Destuctor */
    ~FixedFieldBuffer();
};


#endif /* FixedFieldBuffer_h */
