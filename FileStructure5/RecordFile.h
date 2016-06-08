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
    
    ~RecordFile();
};

template <class Record>
RecordFile<Record>::RecordFile(IOBuffer& _buffer) : BufferFile(_buffer) {
    SetClassType(RECORDFILE);
}
template <class Record>
int RecordFile<Record>::Read(Record& record, int Address) {
    int result;
    result = BufferFile::Read(Address);
    
    return record.Unpack(Buffer);
}

template <class Record>
int RecordFile<Record>::Write(Record& record, int Address) {
    record.Pack(Buffer);
    
    return BufferFile::Write(Address);
}

template <class Record>
int RecordFile<Record>::Append(Record& record) {
    record.Pack(Buffer);
    return BufferFile::Append();
}
template <class Record>
RecordFile<Record>::~RecordFile() { }



#endif /* RecordFile_h */
