// 수식으로 해쳐본다. -> 조건을 따라간다.
// 문제를 해결하기 위한 조건들을 묶는다. -> 조건을 재조직한다.

#include <iostream>
#include <vector>
using namespace std;

int N, K;
int arr[32][2005];
bool primes[2505];

void find_prime() {
    for(int i=0; i<2505; ++i)
        primes[i] = true;
    
    primes[2] = true; primes[3]=true;
    
    for(int i=2; i<2500; ++i) {
        if(!primes[i]) continue;
        int cnt=1;
        while(i*cnt<2500){
            cnt += 1;
            primes[i*cnt] = false;
        }
    }
}

int main(void) {
    
    scanf("%d %d", &K, &N);
    
    find_prime();
    
    int idx = 2, prime_num = 2;
    for(int i=0; i<K; ++i) {
        for(;idx<2505; ++idx) {
            if(primes[idx] && idx >=N) {
                prime_num = idx;
                idx += 1;
                break;
            }
        }
        for(int j=1; j<=N; ++j) {
            printf("%d ", prime_num * j);
        }
        printf("\n");
    }
    
    return 0;
}
