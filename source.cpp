#include <iostream>
#include <vector>
using namespace std;

//bool isPrime(int num) {
//    for(int div=2; div*div<=num; ++div) {
//        if(num % div == 0) return false;
//    }
//    return true;
//}

#define endpoint 1299710
bool notprime[endpoint];
vector<int> primes;
void eratosthenes() {
    notprime[1] = true;
    for (int i=2; i<endpoint; ++i) {
        // 소수면 false, 아니면 true
        if(notprime[i]) continue;
        else {
            primes.push_back(i);
            for(int j=i*2; j<endpoint; j+= i)
                notprime[j] = true;
        }
    }
}


int main(void) {
    
    int N; scanf("%d", &N);
    
    eratosthenes();
    
    int cur;
    for(int i=0; i<N; ++i) {
        scanf("%d", &cur);
        if(!notprime[cur]) printf("0\n");
        else {
            int prev = cur, next = cur;
            while(notprime[prev]) prev -= 1;
            while(notprime[next]) next += 1;
            printf("%d\n", next - prev);
        }
    }
    
    return 0;
}
