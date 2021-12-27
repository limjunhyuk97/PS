#include <iostream>
#include <string>
using namespace std;

int num1[85];
int num2[85];

int main(void){
    
    string str1, str2;
    cin >> str1 >> str2;
    
    int cnt = 0;
    for(int i = (int)str1.size() - 1; i >= 0 ; --i)
        num1[cnt++] = str1[i] - 48;
    
    cnt = 0;
    for(int i = (int)str2.size() - 1; i >= 0 ; --i)
        num2[cnt++] = str2[i] - 48;
        
    int bigger = (int)( str1.size() > str2.size() ? str1.size() : str2.size() ) ;
    for(int i = 0; i < bigger ; ++i){
        num1[i] += num2[i];
        if(num1[i] >= 2) {
            num1[i] -= 2;
            num1[i + 1] += 1;
        }
    }
    
    bool start = false;
    if(num1[bigger] == 1){
        start = true;
        cout << 1;
    }
    
    for(int i = bigger - 1; i >= 0; --i){
        if(!start){
            if(num1[i] == 1){
                start = true;
                cout << num1[i];
            }
            else continue;
        }
        else
            cout << num1[i];
    }
    
    if(!start)
        cout << 0;
    
    cout<< "\n";

    return 0;
}
