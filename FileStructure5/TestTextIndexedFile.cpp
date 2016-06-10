#include "TextIndexedFile.h"
#include "Student.h"
#include "DelimFieldBuffer.h"

using namespace std;

void stop();

extern Student std1;
extern Student std2;
extern Student std3;
extern Student std4;
extern Student std5;
extern Student std6;
extern Student std7;
extern Student std8;
extern Student std9;
extern Student std10;
extern Student std11;
extern Student std12;
extern Student std13;
extern Student std14;
extern Student std15;
extern Student std16;
extern Student std17;
extern Student std18;
extern Student std19;
extern Student std20;
extern Student std21;
extern Student std22;
extern Student std23;
extern Student std24;
extern Student std25;
extern Student std26;
extern Student std27;
extern Student std28;
extern Student std29;
extern Student std30;
extern Student std31;
extern Student std32;
extern Student std33;
extern Student std34;
extern Student std35;
extern Student std36;
extern Student std37;
extern Student std38;
extern Student std39;
extern Student std40;

extern Student lstd1;
extern Student lstd2;
extern Student lstd3;
extern Student lstd4;
extern Student lstd5;
extern Student lstd6;
extern Student lstd7;
extern Student lstd8;
extern Student lstd9;
extern Student lstd10;
extern Student lstd11;
extern Student lstd12;
extern Student lstd13;
extern Student lstd14;
extern Student lstd15;
extern Student lstd16;
extern Student lstd17;
extern Student lstd18;
extern Student lstd19;
extern Student lstd20;
extern Student lstd21;
extern Student lstd22;
extern Student lstd23;
extern Student lstd24;
extern Student lstd25;
extern Student lstd26;
extern Student lstd27;
extern Student lstd28;
extern Student lstd29;
extern Student lstd30;
extern Student lstd31;
extern Student lstd32;
extern Student lstd33;
extern Student lstd34;
extern Student lstd35;
extern Student lstd36;
extern Student lstd37;
extern Student lstd38;
extern Student lstd39;
extern Student lstd40;

extern char* fileName1;
extern char* fileName2;

extern TextIndexedFile<Student> textIndexedFile1;
extern TextIndexedFile<Student> textIndexedFile2;
extern TextIndexedFile<Student> textIndexedFile3;
extern TextIndexedFile<Student> textIndexedFile4;
extern TextIndexedFile<Student> textIndexedFile5;
extern TextIndexedFile<Student> textIndexedFile6;

void TestSaveTextIndexedFile1() {
    textIndexedFile1.Create(fileName1);
    
    textIndexedFile1.Index.Print(cout);
    
   
    
    
    textIndexedFile1.Append(std9);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    textIndexedFile1.Append(std8);
    textIndexedFile1.Index.Print(cout);
    stop();

    
    
    
    textIndexedFile1.Append(std28);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std29);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    
    
    textIndexedFile1.Append(std10);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std11);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    textIndexedFile1.Append(std21);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    
    
    textIndexedFile1.Append(std27);
    textIndexedFile1.Index.Print(cout);
    stop();

    
    
    textIndexedFile1.Append(std12);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    textIndexedFile1.Append(std22);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std23);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std24);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std25);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std26);
    textIndexedFile1.Index.Print(cout);
    stop();

    
    
    textIndexedFile1.Append(std13);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std14);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std15);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std16);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    textIndexedFile1.Append(std17);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    textIndexedFile1.Append(std18);
    textIndexedFile1.Index.Print(cout);
    stop();
    
    
    
    // 17까지
    
    textIndexedFile1.Close();
}
void TestSaveTextIndexedFile2() {
    
    textIndexedFile2.Create(fileName2);
    
    textIndexedFile2.Index.Print(cout);
    
    // 18부터
    
    
    textIndexedFile2.Append(std19);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    
    textIndexedFile2.Append(std20);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    textIndexedFile2.Append(std30);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std31);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std32);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std33);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std34);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std35);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std36);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std37);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std38);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std39);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std40);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    textIndexedFile2.Append(std1);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std2);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std3);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std4);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std5);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std6);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    
    textIndexedFile2.Append(std7);
    textIndexedFile2.Index.Print(cout);
    stop();
    
    textIndexedFile2.Close();
}
void TestLoadTextIndexedFile1() {

    textIndexedFile3.Open(fileName1);
    
    
    textIndexedFile3.Read(lstd1);
    cout << lstd1 << endl;
    stop();
    
    
    textIndexedFile3.Read(lstd2);
    cout << lstd2 << endl;
    stop();
    
    
    textIndexedFile3.Read(lstd3);
    cout << lstd3 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd4);
    cout << lstd4 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd5);
    cout << lstd5 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd6);
    cout << lstd6 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd7);
    cout << lstd7 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd8);
    cout << lstd8 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd9);
    cout << lstd9 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd10);
    cout << lstd10 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd11);
    cout << lstd11 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd12);
    cout << lstd12 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd13);
    cout << lstd13 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd14);
    cout << lstd14 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd15);
    cout << lstd15 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd16);
    cout << lstd16 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd17);
    cout << lstd17 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd18);
    cout << lstd18 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd19);
    cout << lstd19 << endl;
    stop();
    
    
    
    textIndexedFile3.Read(lstd20);
    cout << lstd20 << endl;
    stop();
    
    // 20까지
    
}
void TestLoadTextIndexedFile2() {
    
    textIndexedFile4.Open(fileName2);
    
    // 21부터
    
    textIndexedFile4.Read(lstd21);
    cout << lstd21 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd22);
    cout << lstd22 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd23);
    cout << lstd23 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd24);
    cout << lstd24 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd25);
    cout << lstd25 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd26);
    cout << lstd26 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd27);
    cout << lstd27 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd28);
    cout << lstd28 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd29);
    cout << lstd29 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd30);
    cout << lstd30 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd31);
    cout << lstd31 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd32);
    cout << lstd32 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd33);
    cout << lstd33 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd34);
    cout << lstd34 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd35);
    cout << lstd35 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd36);
    cout << lstd36 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd37);
    cout << lstd37 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd38);
    cout << lstd38 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd39);
    cout << lstd39 << endl;
    stop();
    
    
    
    textIndexedFile4.Read(lstd40);
    cout << lstd40 << endl;
    stop();
    
    
}

void TestSearchTextIndexedFile() {
    Student s1;
    textIndexedFile5.Open(fileName1);
    textIndexedFile6.Open(fileName2);
    
    string searchString;
    cout << "검색 키를 입력하세요: " << endl;
    cin >> searchString;
    
    
    if(textIndexedFile5.Read(searchString, s1) == -1 ) {
        if(textIndexedFile6.Read(searchString, s1) == -1) {
            cout << "not exist" << endl;
        }
        else {
            cout << s1 << endl;
        }
        
    }
    else {
        cout << s1 << endl;
    }
    
    
}
