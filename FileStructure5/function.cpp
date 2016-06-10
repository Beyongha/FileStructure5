#include <cstdio>
#include <iostream>
#include <cassert>

using namespace std;

// util function
/* 수를 문자열로 바꿔줌 */
char* intToString(int number) {
    const int VolumeOfNumber = 11;
    char* returnString = new char[VolumeOfNumber];
    memset(returnString, '\0', VolumeOfNumber);
    
    sprintf(returnString, "%d", number);
    
    return returnString;
}
/* 잠시 멈춤 */
void stop() {
    const int MaxBufferSize = 1024;
    char buffer[MaxBufferSize];
    cout << "계속하려면 아무 키나 입력하고 엔터키를 누르십시오.(ex, a(enter)" << endl;
    cin >> buffer;
    
    if( strlen(buffer) > MaxBufferSize){
        cout << "Buffer Overflow Attack Occured" << endl;
    }
    buffer[MaxBufferSize-1] = '\0';
}
