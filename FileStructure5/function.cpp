#include <cstdio>
#include <iostream>


using namespace std;

// util function
//수를 문자열로 바꿔줌
char* intToString(int number) {
    const int VolumeOfNumber = 11;
    char* returnString = new char[VolumeOfNumber];
    memset(returnString, '\0', VolumeOfNumber);
    
    sprintf(returnString, "%d", number);
    
    return returnString;
}
// 잠시 멈춤
void stop() {
    const int MaxBufferSize = 1024;
    char buffer[MaxBufferSize];
    cout << "계속하려면 아무 키나 누르십시오." << endl;
    cin >> buffer;
}