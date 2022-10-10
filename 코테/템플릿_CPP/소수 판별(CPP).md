# 소수 판별 (CPP)

## 소수 판별 - (n)^(1/2) 까지

```cpp
#include <iostream>
using namespace std;

bool isPrime(int num) {
    for(int div=2; div*div<=num; ++div) {
        if(num % div == 0) return false;
    }
    return true;
}
```

## 소수 판별 - 에라토스테네스의 체 

```cpp
#include <iostream>
#include <vector>
#define endpoint 1299710
using namespace std;

bool notprime[endpoint];
vector<int> primes;

void eratosthenes() {
    notprime[1] = true;
    for (int i=2; i<endpoint; ++i) {
        // 소수 아니면 continue
        if(notprime[i]) continue;
        // 소수를 찾았으면 endpoint 미만의 배수들을 다 소수 아님 처리 
        else {
            primes.push_back(i);
            for(int j=i*2; j<endpoint; j+= i)
                notprime[j] = true;
        }
    }
}
```
