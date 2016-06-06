#ifndef Buffer_h
#define Buffer_h


#include "classType.h"

#include <iostream>

using namespace std;

const int MaxBufferSize = 1024;


/* IO class들의 parent */
class IOBuffer {
protected:
    ClassType classType;
    char* Buffer;           // 문자열 저장하는 버퍼
    int MaxSize;            // 버퍼의 최대 길이
    int Offset;             // pack의 오프셋.
    
    /* Setter */
    void SetBuffer(int);                        // 버퍼를 설정
    void SetMaxSize(int);                       // 버퍼의 최대 크기
    void SetOffset(int);                        // 현재까지 처리한 수(오프셋)
    void SetClassType(ClassType);    // 클래스 타입을 가지고 있음.
    
    void ValidateInput(const int, const char*); // 문자열의 길이를 검증함.
    void ValidateInput(const int, const int);   // 정수의 범위를 검증함.
    void ValidateInput(const int);
    
public:
    /* Constructor */
    IOBuffer(int);                              // 버퍼의 최대 크기룰 기준으로 버퍼 생성
    IOBuffer();
    
    /* Virtual functions */
    virtual int Pack(const char*) = 0;          // 문자열을 pack함
    virtual int Pack(const int&) = 0;           // 수를 pack함
    
    virtual int Unpack(char*, int) = 0;         // 문자열을 unpack함
    virtual int Unpack(int&) = 0;				// 수를 unpack함
    
    virtual void Write(ostream&) = 0;           // 파일이든 표준출력이든, ostream에 바이트를 씀. 다형성 지원
    virtual void Read(istream&) = 0;            // 파일이든 표준입력이든, istream에 바이트를 씀. 다형성 지원
    
    virtual void Clear();
    
    virtual void WriteHeader(ostream&);
    virtual void ReadHeader(istream&);
    
    /* Getter */
    char* GetBuffer() const;                // 버퍼 포인터를 상수로 리턴.
    int GetMaxSize() const;                 // 버x퍼의 최대 크기를 리턴.
    int GetOffset() const;                  // 오프셋을 리턴.
    
    ClassType GetClassType() const;         // class가 뭔지를 알려줌.
    
    /* Destructor */
    ~IOBuffer();
};


#endif /* Buffer_h */
