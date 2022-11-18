#include <iostream>
#include <algorithm>
using namespace std;

int N;
int DP[305];
int arr[305];

int main(void) {
    
    cin >> N;
    for(int i=1; i<=N; ++i) cin >> arr[i];
    
    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];
    for(int i=3; i<=N; ++i) {
        DP[i] = max(DP[i-3] + arr[i-1], DP[i-2]) + arr[i];
    }
    
    cout << DP[N] << endl;
    
    return 0;
}
