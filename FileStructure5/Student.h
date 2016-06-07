//
//  Student.h
//  FileStructure5
//
//  Created by JIN Beyongha on 2016. 6. 6..
//  Copyright © 2016년 JIN Beyongha. All rights reserved.
//

#ifndef Student_h
#define Student_h


#include "classType.h"
#include "Buffer.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>



const int StudentFieldSize = 30;

enum StudentClassEntry { STUDENTID = 0, STUDENTNAME, ADDRESS, DATE, CREDIT, NUMOFSTUDENTMEMBER };

class Student {
protected:
    ClassType classType;
    
    /* 멤버 변수들 */
    char StudentID[StudentFieldSize];            /* 학번 */
    char Name[StudentFieldSize];				  /* 이름 */
    char Address[StudentFieldSize];              /* 주소 */
    int AdmissionYear;                    /* 압학년도 */
    int Credit;                           /* 이수학점 */
    
    /* Setter */
    int SetStudentID(const char*);
    int SetName(const char*);
    int SetAddress(const char*);
    int SetAdmissionYear(const int);
    int SetCredit(const int);
    int SetClassType(ClassType _classType);
public:
    /* Constructors */
    Student(const char*, const char*, const char*, const int, const int);
    Student(const Student&);
    Student();
    
    
    /* Operator overloading */
    Student& operator = (const Student& _Student);
    bool operator == (const Student& _Student);
    bool operator != (const Student& _Student);
    
    
    /* I/O stream */
    friend ostream& operator << (ostream&, const Student&);
    /* friend ofstream& operator << (ofstream& ofs, const Student& _Student); */
    
    friend istream& operator >> (istream&, Student&);
    /* friend ifstream& operator >> (ifstream& ifs, Student& _Student); */
    
    
    /* Methods */
    void PrintInfo();
    void ValidateInput(int, const char*);
    void ValidateInput(const int, const int);
    
    
    /* Pack and Unpack */
    int Pack(IOBuffer& _IOBuffer);
    int Unpack(IOBuffer& _IOBuffer);
    
    
    
    /* Getter */
    const char* GetStudentID() const;
    const char* GetName() const;
    const char* GetAddress() const;
    const int GetAdmissionYear() const;
    const int GetCredit() const;
    
    /* Class Type */
    ClassType GetClassType();
    
    /* Destructor */
    ~Student();
};




#endif /* Student_h */
