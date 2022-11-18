#include <iostream>
#include <algorithm>
#include <queue>
#define MAXLEN 1000005
using namespace std;

int N;
int DP[MAXLEN];
int before[MAXLEN];

int main(void) {
    
    scanf("%d", &N);
    
    before[1] = 1;
    // bottom - up
    for(int i=2; i<=N; ++i) {
        DP[i] = DP[i-1] + 1;
        before[i] = i-1;
        if(i % 2 == 0 && (DP[i/2] + 1 < DP[i])) {
            DP[i] = DP[i/2] + 1;
            before[i] = i/2;
        }
        if(i % 3 == 0 && (DP[i/3] + 1 < DP[i])) {
            DP[i] = DP[i/3] + 1;
            before[i] = i/3;
        }
    }
    
    cout << DP[N] << endl;
    for(int i=N; before[i]!=i; i=before[i]) {
        cout << i << " ";
    }
    cout << 1 << " " << endl;

    return 0;
}
