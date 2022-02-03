#include <iostream>
#include <string>
using namespace std;

string answer;

int main(void){
    
    cin >> answer;
    
    int len = (int)answer.size(), s=-1, e=-1;
    for(int i=0; i<len; ++i){
        if(answer[i]=='.'){
            if(s != -1){
                e+= 1;
                if((e-s)%4 != 2 && (e-s)%4 != 0){
                    printf("-1\n");
                    return 0;
                }
                else{
                    for(int i=s; i<e; i+=4){
                        if(i+4<=e){
                            for(int j=i; j<i+4; ++j) answer[j]='A';
                        }
                        else{
                            for(int j=i; j<i+2; ++j) answer[j]='B';
                        }
                    }
                }
            }
            s = -1; e = -1;
        }
        else{
            if(s == -1) {
                s = i;
                e = s;
            }
            else e = i;
        }
    }
    if(s != -1){
        e+= 1;
        if((e-s)%4 != 2 && (e-s)%4 != 0){
            printf("-1\n");
            return 0;
        }
        else{
            for(int i=s; i<e; i+=4){
                if(i+4<=e){
                    for(int j=i; j<i+4; ++j) answer[j]='A';
                }
                else{
                    for(int j=i; j<i+2; ++j) answer[j]='B';
                }
            }
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
