// 연속된 소수의 합으로 작성하는 프로그램
// 풀이과정
//  - 먼저 일련의 소수들을 구한다.
//  - 일련의 소수들을 투 포인터로 순회하면서 더해본다.

#include <iostream>
#include <vector>
#define BUFLEN 4000005
using namespace std;

bool is_prime[BUFLEN];
vector<int> primes;
int p0, p1, N, chunk, cnt;

int main(void) {
    
    scanf("%d", &N);
    
    // generating primes
    for(int i=0; i<BUFLEN; ++i) is_prime[i] = true;
    for(int i=2; i<BUFLEN; ++i)
        if(is_prime[i])
            for(int j=2; j*i<4000005; ++j)
                is_prime[j*i] = false;
    
    // get prime numbers
    for(int i=2; i<BUFLEN; ++i)
        if(is_prime[i])
            primes.push_back(i);
    
    chunk = primes[p0];
    while(primes[p0] <= N && p0<=p1 && p1 < primes.size()) {
        if(chunk < N) {
            p1 += 1;
            chunk += primes[p1];
        }
        else if (chunk > N){
            chunk -= primes[p0];
            p0 += 1;
        }
        else {
            chunk -= primes[p0];
            p0 += 1;
            cnt += 1;
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
