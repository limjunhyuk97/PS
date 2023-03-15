#include <iostream>
#include <bitset>
using namespace std;

// a-z(:97-122) A-Z(:65-90)
char case_convert(char target) {
    return target ^ 32;
}

int main(void) {

    int a = 1, b = 1 , c= 17, d = 3, e = -8, f = -8;
    
    cout << bitset<10>(a ^ b ^ c).to_ulong() << endl;
    cout << bitset<10>(d ^ e ^ f).to_ulong() << endl;
    
}

// (1, 3)
// (1, -8) (17, -8)

// 32 :    0100000
// 65(A) : 1000001
// 97(a) : 1100010
