#ifndef TextIndexedFile_h
#define TextIndexedFile_h

#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "TextIndex.h"
#include "TextIndexBuffer.h"
#include "RecordFile.h"
#include "BufferFile.h"
#include "IOBuffer.h"

using namespace std;

template <class Record>
class TextIndexedFile {
public:
    TextIndex Index;
    TextIndexBuffer IndexBuffer;
    BufferFile IndexFile;
    RecordFile<Record> DataFile;
    char* FileName;
    int SetFileName(char* fileName, char*& dataFileName, char*& indexFileName);
    
public:
    TextIndexedFile(IOBuffer& buffer, int keySize, int maxKeys = 100);
    
    /* Methods */
    int Read(Record& record);
    int Read(string key, Record& record);
    int Append(Record& record);
    int Update(string oldKey, const Record& record);
    int Create(char* name, int mode=ios::in|ios::out);
    int Open(char* name, int mode=ios::in|ios::out);
    int Close();
    
    /* Destructor */
    ~TextIndexedFile();
};

template <class Record>
TextIndexedFile<Record>::TextIndexedFile(IOBuffer& buffer, int keySize, int maxKeys)
    : DataFile(buffer), Index(maxKeys), IndexFile(IndexBuffer), IndexBuffer(keySize, maxKeys)
{
    FileName = 0;
}


template <class Record>
int TextIndexedFile<Record>::Read(Record& record) {
    return DataFile.Read(record, -1);
}

template <class Record>
int TextIndexedFile<Record>::Read(string key, Record& record) {
    int ref;
    ref = Index.Search(key);
    
    if( ref < 0) return -1;
    
    return DataFile.Read(record, ref);
}

template <class Record>
int TextIndexedFile<Record>::Append(Record& record) {
    string* key = new string(record.Key());
    int ref = Index.Search(key->c_str());
    if( ref != -1) return -1;       /* 이미 있음 */
    
    ref = DataFile.Append(record);
    Index.Insert(*key, ref);
    return ref;
}

template <class Record>
int TextIndexedFile<Record>::Update(string oldKey, const Record& record) {
    // 나중에
    return 1;
}
template <class Record>
int TextIndexedFile<Record>::SetFileName(char* fileName, char*& dataFileName, char*& indexFileName) {
    if( FileName != 0 ) return 0;
    
    FileName = strdup(fileName);
    
    ostringstream dataName, indexName;
    dataName << FileName << "dat.txt" << ends;
    indexName << FileName << "ind.txt" << ends;
    
    dataFileName = strdup(dataName.str().c_str() );
    indexFileName = strdup(indexName.str().c_str());
    
    return 1;
}
template <class Record>
int TextIndexedFile<Record>::Create(char* fileName, int mode) {
    int result;
    char* dataFileName, * indexFileName;
    result = SetFileName(fileName, dataFileName, indexFileName);
    if( result == -1 ) return 0;
    
    result = DataFile.Create(dataFileName);
    if( !result ) {
        FileName = 0;
        return 0;
    }
    
    result = IndexFile.Create(indexFileName);
    if( !result ) {
        DataFile.Close();
        FileName = 0;
        return 0;
    }
    return 1;
}
template <class Record>
int TextIndexedFile<Record>::Open(char* fileName, int mode) {
    int result;
    char* dataFileName, *indexFileName;
    result = SetFileName(fileName, dataFileName, indexFileName);
    if( !result ) return 0;
    
    result = DataFile.Open(dataFileName);
    if( !result ) {
        FileName = 0;
        return 0;
    }
    
    result = IndexFile.Open(indexFileName);
    if( !result ) {
        DataFile.Close();
        FileName = 0;
        return 0;
    }
    
    result = IndexFile.Read();
    if( result != -1) {
        result = IndexBuffer.Unpack(Index);
        if( result != -1) return 1;
    }
    DataFile.Close();
    IndexFile.Close();
    FileName = 0;
    return 0;
}
template <class Record>
int TextIndexedFile<Record>::Close() {
    int result;
    if( !FileName) return 0;
    
    DataFile.Close();
    //IndexFile.Rewind(); /* ?? */
    IndexBuffer.Pack(Index);
    result = IndexFile.Write();
    cout << "result of index write: " << result << endl;
    IndexFile.Close();
    FileName = 0;
    return 1;
}
template <class Record>
TextIndexedFile<Record>::~TextIndexedFile() {
    //IndexFile.Rewind();
    //IndexFile.GetBuffer().WriteHeader(IndexFile.GetFile());
    
    Close();
}


#endif /* TextIndexedFile_h */
