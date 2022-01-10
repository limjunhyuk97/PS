// 예외 처리

#include <iostream>
#include <deque>
#include <string>
using namespace std;

string str;

int main(void){
    
    cin >> str;
    
    if(str[0] == '0' && str.size() == 1) cout << 0 << "\n";
    
    for(int i=0; i<str.size(); ++i){
        deque<int> tmp;
        int num = str[i] - 48;
        while(num){
            tmp.push_front(num % 2);
            num /= 2;
        }
        if(i !=0 && tmp.size() == 2) cout << "0";
        if(i !=0 && tmp.size() == 1) cout << "00";
        if(i !=0 && tmp.size() == 0) cout << "000";
        for(int j=0; j<tmp.size(); ++j)
            cout << tmp[j];
    }
    cout << endl;
    
    return 0;
}
