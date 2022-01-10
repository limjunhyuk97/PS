#include <string>
#include <iostream>
using namespace std;

int main(void){
    
    string str = "hello";
    
    cout << *(str.end()-1);
    
    return 0;
}
