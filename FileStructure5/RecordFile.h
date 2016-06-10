#ifndef RecordFile_h
#define RecordFile_h

#include "IOBuffer.h"
#include "BufferFile.h"
#include "classType.h"
#include "Student.h"

#include <iostream>

using namespace std;

template <class Record>
class RecordFile : public BufferFile {
public:
    RecordFile(IOBuffer&);
    
    int Read(Record&, int Address = -1);
    int Write(Record&, int Address = -1);
    int Append(Record&);
    int Close();
    
    ~RecordFile();
};

template <class Record>
RecordFile<Record>::RecordFile(IOBuffer& _buffer) : BufferFile(_buffer) {
    SetClassType(RECORDFILE);
}
template <class Record>
int RecordFile<Record>::Read(Record& record, int Address) {
    BufferFile::Read(Address);
    
    return record.Unpack(Buffer);
}

template <class Record>
int RecordFile<Record>::Write(Record& record, int Address) {
    record.Pack(Buffer);
    
    return BufferFile::Write(Address);
}

template <class Record>
int RecordFile<Record>::Append(Record& record) {
    int ref;
    ref = record.Pack(Buffer);
    
    return ref;
}

template <class Record>
int RecordFile<Record>::Close() {
    BufferFile::Append();
    BufferFile::Close();
    return 1;
}

template <class Record>
RecordFile<Record>::~RecordFile() { }



#endif /* RecordFile_h */
