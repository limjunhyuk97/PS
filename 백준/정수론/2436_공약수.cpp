// ab에서 a+b가 최소가 되도록 ab를 쪼개는 법..!
//  - n^2 == ab라면 2*n이 최소
//  - 그러므로 1 ~ n^2(<=a*b) 로 올라가며 접근

#include <iostream>
#include <algorithm>
#define INF 100000009
using namespace std;

int gcd(int m, int n) {
    if(m < n) swap(m, n);
    if(n == 0) return m;
    return gcd(n, m % n);
}

int main(void) {
    
    int G, L; scanf("%d %d", &G, &L);
    
    int ab = L/G;
    int minSum = INF, a = 1, b = 1;
    
    for(int i=1; i*i <= ab; ++i) {
        if(ab % i == 0) {
            if((minSum > i + ab/i) && gcd(i, ab/i) == 1) {
                minSum = i + ab/i;
                a = i;
                b = ab / i;
            }
        }
    }
    
    printf("%d %d\n", a*G, b*G);
    
    return 0;
}
