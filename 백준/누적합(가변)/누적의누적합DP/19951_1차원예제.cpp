// 누적의누적합 DP
#include <iostream>
using namespace std;

int N, M;
int H[100005];
int acc[100005];

int main(void) {
    scanf("%d %d", &N, &M);
    
    for(int i=1; i<=N; ++i) {
        cin >> H[i];
    }
    
    for(int i=0; i<M; ++i) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        acc[a] += k;
        acc[b+1] -= k;
    }
    
    for(int i=1; i<=N; ++i) {
        acc[i] += acc[i-1];
        H[i] += acc[i];
        cout << H[i] << " ";
    }
    cout << endl;
    
    return 0;
}


