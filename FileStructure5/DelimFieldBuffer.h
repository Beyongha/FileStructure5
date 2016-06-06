#ifndef DelimFieldBuffer_h
#define DelimFieldBuffer_h

#include "Buffer.h"
#include "classType.h"

#include <iostream>


class DelimFieldBuffer : public IOBuffer {
protected:
    const char* Delim;		// delimiter를 지정.
    
    void setDelim(char* newDelim);
public:
    /* Constructor */
    DelimFieldBuffer(int, const char*);
    
    /* Virtual functions */
    int Pack(const char*);          // 문자열을 pack함
    int Pack(const int&);           // 수를 pack함
    
    int Unpack(char*, int);         // 문자열을 unpack함
    int Unpack(int&);				// 수를 unpack함
    
    void Write(ostream&);           // 파일이든 표준출력이든, ostream에 바이트를 씀. 다형성 지원
    void Read(istream&);            // 파일이든 표준입력이든, istream에 바이트를 씀. 다형성 지원
    
    void Clear();
    
    void WriteHeader(ostream&);
    void ReadHeader(istream&);
    
    /* getter */
    const char* GetDelim() const;
    
    /* Destuctor */
    ~DelimFieldBuffer();
};



#endif /* DelimFieldBuffer_h */
