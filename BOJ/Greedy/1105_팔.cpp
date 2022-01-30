#include <iostream>
#include <string>
using namespace std;

int L[15], R[15], idx, lenL, lenR;
string strL, strR;

int main(void){
    
    cin >> strL >> strR;
    lenL = (int)strL.size();
    lenR = (int)strR.size();
    
    for(int i=lenL; i>=0; --i) {
        L[idx++] = strL[i] - '0';
    }
    idx = 0;
    for(int i=(int)strR.size()-1; i>=0; --i) {
        R[idx++] = strR[i] - '0';
    }
    
    for(int i=0; i<lenR; ++i){
        u
    }
    
    return 0;
}
