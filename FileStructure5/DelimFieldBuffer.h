#ifndef DelimFieldBuffer_h
#define DelimFieldBuffer_h

#include "IOBuffer.h"
#include "classType.h"

#include <iostream>



class DelimFieldBuffer : public IOBuffer {
protected:
    const char* Delim = "|";
public:
    /* Constructor */
    DelimFieldBuffer(int);
    DelimFieldBuffer();
    
    /* Virtual functions */
    int Pack(const char*);          // 문자열을 pack함
    int Pack(const int&);           // 수를 pack함
    
    int Unpack(char*, int);         // 문자열을 unpack함
    int Unpack(int&);				// 수를 unpack함
    
    void Write(ostream&);           // 파일에 씀.
    void Read(istream&);            // 파일에서 읽어옴.
    
    virtual void DWrite(ostream&, int);
    virtual void DRead(istream&, int);
    
    int DPack(const char*, int);
    int DPack(const int&, int);
    
    int DUnpack(char*, int, int);
    int DUnpack(int&, int);
    
    void Clear();
    
    void WriteHeader(ostream&);
    void ReadHeader(istream&);
    
    /* getter */
    const char* GetDelim() const;
    
    /* Validator */
    void ValidateInput(const int, const char*);
    void ValidateInput(const int, const int);   // 정수의 범위를 검증함.
    void ValidateInput(const int);

    
    /* Destuctor */
    ~DelimFieldBuffer();
};



#endif /* DelimFieldBuffer_h */
