// 6
#include <iostream>
#include <string>
using namespace std;

string num1, num2;

string REV(string str){
    for(int i=0; i<str.size()/2; ++i){
        int tmp = str[i];
        str[i] = str[str.size() - i -  1];
        str[str.size()-i-1] = tmp;
    }
    return str;
}

string ADD(string str1, string str2){
    string str = to_string(stoi(str1) + stoi(str2));
    return str;
}

int main(void){
    
    cin >> num1 >> num2;
    
    cout << stoi( REV( ADD( REV(num1), REV(num2) ) ) );
    
    return 0;
}
