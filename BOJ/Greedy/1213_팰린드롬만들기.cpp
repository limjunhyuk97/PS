#include <iostream>
#include <cstring>
#define errmsg "I'm Sorry Hansoo\n"
using namespace std;

int alphabet[30], len, odd_pos = -1;
char str[55];

int main(void){
    
    scanf("%s", str);
   
    len = (int)strlen(str);
    for(int i=0; i<len; ++i) alphabet[str[i]-'A'] += 1;
    
    int odd_num=0;
    for(int i=0; i<30; ++i){
        if(alphabet[i] % 2 == 1) {
            odd_num += 1;
            odd_pos = i;
        }
        if(odd_num > 1){
            printf("%s",errmsg);
            return 0;
        }
    }
    
    for(int i=0; i<30; ++i){
        if(alphabet[i]>0){
            int cnt=alphabet[i]/2;
            for(int j=0; j<cnt; ++j){
                printf("%c", i+'A');
            }
            alphabet[i] -= cnt;
        }
    }
    
    if(odd_pos != -1) {
        printf("%c", odd_pos+'A');
        alphabet[odd_pos] -= 1;
    }
    
    for(int i=29; i>=0; --i){
        for(int j=0; j<alphabet[i]; ++j){
            printf("%c", i+'A');
        }
    }
    
    printf("\n");
    
    return 0;
}
