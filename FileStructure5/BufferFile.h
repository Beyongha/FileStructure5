#ifndef BufferFile_h
#define BufferFile_h

#include "Buffer.h"
#include "classType.h"


#include <iostream>
#include <fstream>


class BufferFile {
protected:
    ClassType classType;
    
    IOBuffer& Buffer;
    fstream File;
    char* FileName;
    // header
    
    
    void SetName(const char* _name);
    void SetClassType(ClassType _classType);
public:
    BufferFile(IOBuffer& _buffer);
    
    virtual int Open(char* _name);
    virtual int Create(char* _name);
    virtual int Close();
    virtual int rewind();
    virtual int Read();
    virtual int Write();
    virtual int Append(/* record */);

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
