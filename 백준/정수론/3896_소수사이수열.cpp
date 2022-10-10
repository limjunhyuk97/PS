// 소수 구하기

#include <iostream>
using namespace std;

bool isPrime(int num) {
    for(int div=2; div*div<=num; ++div) {
        if(num % div == 0) return false;
    }
    return true;
}


int main(void) {
    
    int N; scanf("%d", &N);
    
    int cur;
    for(int i=0; i<N; ++i) {
        scanf("%d", &cur);
        if(isPrime(cur) || cur == 1) printf("0\n");
        else {
            int prev = cur-1, next = cur+1;
            while(!isPrime(prev)) {
                prev -= 1;
            }
            while(!isPrime(next)) {
                next += 1;
            }
            printf("%d\n", next- prev);
        }
    }
    
    return 0;
}
