#include "Student.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

/* Setter */
int Student::SetStudentID   (const char* _StudentID) {
    /* Is input valid? */
    ValidateInput(StudentFieldSize, _StudentID);
    
    strcpy(this->StudentID, _StudentID);
    return 1;
}
int Student::SetName        (const char* _Name) {
    /* Is input Valid? */
    ValidateInput(StudentFieldSize, _Name);
    
    strcpy(this->Name, _Name);
    return 1;
}
int Student::SetAddress     (const char* _Address) {
    /* Is input Valid? */
    ValidateInput(StudentFieldSize, _Address);
    
    strcpy(this->Address, _Address);
    return 1;
}
int Student::SetAdmissionYear(const int _AdmissionYear) {
    ValidateInput(100, _AdmissionYear);
    
    this->AdmissionYear = _AdmissionYear;
    return 1;
}
int Student::SetCredit      (const int _Credit) {
    ValidateInput(200, _Credit);
    
    this->Credit = _Credit;
    return 1;
}
int Student::SetClassType            (ClassType _classType) {
    this->classType = _classType;
    return 1;
}
/* Constructors */
Student::Student(const char* _StudentID, const char* _Name, const char* _Address, const int _AdmissionYear, const int _Credit) {
    SetStudentID    (_StudentID);
    SetName         (_Name);
    SetAddress      (_Address);
    SetAdmissionYear(_AdmissionYear);
    SetCredit       (_Credit);
    SetClassType    (STUDENT);
}
Student::Student(const Student& _Student) {
    SetStudentID    (_Student.StudentID);
    SetName         (_Student.Name);
    SetAddress      (_Student.Address);
    SetAdmissionYear(_Student.AdmissionYear);
    SetCredit       (_Student.Credit);
    SetClassType    (STUDENT);
}
Student::Student() { SetClassType (STUDENT); }

/* Operator overloading */
Student& Student::operator = (const Student& _Student) {
    SetStudentID    (_Student.StudentID);
    SetName         (_Student.Name);
    SetAddress      (_Student.Address);
    SetAdmissionYear(_Student.AdmissionYear);
    SetCredit       (_Student.Credit);
    return *this;
}
bool    Student::operator == (const Student& _Student) {
    /* Same student if StudentID and Name is same */
    return (!strcmp(this->StudentID, _Student.StudentID)
            && !strcmp(this->Name, _Student.Name));
}
bool    Student::operator != (const Student& _Student) {
    return !(*this == _Student);
}


/* I/O stream */
ostream& operator << (ostream& os, const Student& _Student) {
    os << "<Student Information>" << endl;
    
    os << "Name: "          << _Student.GetName()        << endl;
    os << "Student ID: "    << _Student.GetStudentID()   << endl;
    os << "Address: "       << _Student.GetAddress()     << endl;
    os << "Admission Year: "<< _Student.GetAdmissionYear() << endl;
    os << "Credit: "        << _Student.GetCredit()      << endl;
    
    return os;
}
/* 이 클래스는 Buffer 저장형식에 따라 달라지므로 보류 */
/* ofstream&   operator << (ofstream& ofs, const Student& _Student); */

istream& operator >> (istream& is, Student& _Student) {
    cout << "Enter Name(MaxSize=" << StudentFieldSize << ")";
    is >> _Student.Name;
    
    cout << "Enter Student ID(MaxSize=" << StudentFieldSize << ")";
    is >> _Student.StudentID;
    
    cout << "Enter Address(MaxSize=" << StudentFieldSize << ")";
    is >> _Student.Address;
    
    cout << "Enter Admission Year(MaxValue=" << 99 << ")";
    is >> _Student.AdmissionYear;
    
    cout << "Enter Credit(MaxValue=" << 200 << ")";
    is >> _Student.Credit;
    
    return is;
}
/* 이 클래스는 Buffer저장형식에 따라 달라지므로 보류 */
/* ifstream&   operator >> (ifstream& ifs, Student& _Student); */


/* Methods */
void Student::PrintInfo() { cout << *this << endl; }

/* Check if input is valid */
void Student::ValidateInput(const int MaxSize, const char* String) {
    /* strlen error occured */
    assert((strlen(String) > 0) && "strlen(String) is Negative or Zero");
    
    /* MaxSize range error */
    assert((MaxSize > 0 ) && "MaxSize is Negative or Zero");
    
    /* Overflow occured */
    assert(MaxSize >= strlen(String) && "strlen(String) is greater than MaxSize");
}
void Student::ValidateInput(const int MaxValue, const int Value) {
    /* Check if Value is negative */
    assert((Value >= 0) && "Value is Negative");
    
    /* MaxSize range error */
    assert((MaxValue > 0 ) && "MaxSize is Negative or Zero");
    
    /* Check if Value is smaller than MaxValue */
    assert((MaxValue >= Value) && "MaxValue is smaller than Value");
}

/* Pack and Unpack */
int Student::Pack    (IOBuffer& _IOBuffer) {
    int result = 1;
    result &= _IOBuffer.Pack(this->StudentID);
    result &= _IOBuffer.Pack(this->Name);
    result &= _IOBuffer.Pack(this->Address);
    result &= _IOBuffer.Pack(this->AdmissionYear);
    result &= _IOBuffer.Pack(this->Credit);
    
    return result;
}
int Student::Unpack  (IOBuffer& _IOBuffer) {
    int result = 1;
    result &= _IOBuffer.Unpack(this->StudentID, StudentFieldSize);
    result &= _IOBuffer.Unpack(this->Name, StudentFieldSize);
    result &= _IOBuffer.Unpack(this->Address, StudentFieldSize);
    result &= _IOBuffer.Unpack(this->AdmissionYear);
    result &= _IOBuffer.Unpack(this->Credit);
    
    return result;
}

/* Getter */
const char* Student::GetStudentID()  const { return this->StudentID; }
const char* Student::GetName()       const { return this->Name; }
const char* Student::GetAddress()    const { return this->Address; }
const int Student::GetAdmissionYear()  const { return this->AdmissionYear; }
const int Student::GetCredit()         const { return this->Credit; }

/* Class type */
ClassType Student::GetClassType() { return this->classType; }

/* Destructor */
Student::~Student() {}