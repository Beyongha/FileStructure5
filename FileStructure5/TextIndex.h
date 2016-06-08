#ifndef TextIndex_h
#define TextIndex_h

#include "classType.h"

#include <iostream>
#include <string>

using namespace std;

class TextIndex {
protected:
    ClassType classType;
    int MaxKeys;
    int NumKeys;
    string* Keys;
    int* Addresses;
    int Unique;
    
    /* Private methods */
    int Find(const string& key) const;
    int Init(int maxKeys, int unique);
    
    /* Setter */
    void SetMaxKeys(int);
    void SetNumKeys(int);
    void SetKeys(int);
    void SetAddresses(int);
    void SetUnique(int);
    void SetClassType(ClassType);
    
    friend class TextIndexBuffer;
    
public:
    TextIndex(int MaxKeys = 100, int unique = 1);
    
    
    /* Validator */
    void ValidateInput(const int MaxSize, const char* String);
    void ValidateInput(const int MaxValue, const int Value);
    void ValidateInput(const int Value);
    
    /* Methods */
    int Insert(const string key, int Address);
    int Remove(const string key);
    int Search(const string key);
    void Print(ostream&) const;
    
    /* Getter */
    int GetMaxKeys() const;
    int GetNumKeys() const;
    int GetUnique() const;
    ClassType GetClassType() const;
    
    /* Destructor */
    ~TextIndex();
};

#endif /* TextIndex_h */
