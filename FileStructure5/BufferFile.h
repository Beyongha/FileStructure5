#ifndef BufferFile_h
#define BufferFile_h

#include "Buffer.h"
#include "classType.h"
#include "Student.h"

#include <iostream>
#include <fstream>


class BufferFile {
protected:
    ClassType classType;
    
    IOBuffer& Buffer;
    fstream File;
    char* FileName;
    // header
    
    
    void SetName(const char*);
    void SetClassType(ClassType);
public:
    BufferFile(IOBuffer&);
    
    int Open(const char*);
    int Create(const char*);
    int Close();
    int rewind();
    int Read(int Address = -1);
    int Write(int Address = -1);
    int Append(/* record? -> NO */);

    /* Getter */
    const IOBuffer& GetBuffer() const;
    const char* GetFileName() const;
    const ClassType GetClassType() const;
    
    /* Validator */
    int IsFileOpened(fstream&);
    
    /* Destructor */
    ~BufferFile();
};

#endif /* BufferFile_h */
