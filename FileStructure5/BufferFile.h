#ifndef BufferFile_h
#define BufferFile_h

#include "Buffer.h"
#include "classType.h"


#include <iostream>
#include <fstream>


class BufferFile {
protected:
    ClassType ClassType;
    
    IOBuffer& Buffer;
    fstream File;
    char* FileName;
    // header
    
    
    void SetName(const char* _name);
    void SetClassType(enum ClassType _classType);
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
    const enum ClassType GetClassType() const;
    
    /* Destructor */
    ~BufferFile();
};

#endif /* BufferFile_h */
