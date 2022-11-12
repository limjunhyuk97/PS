#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, M, L;

int main(void) {
    
    scanf("%d %d %d", &N, &M, &L);
    deque<int> R(N, 0);
    for(int i=0; i<N; ++i) {
        scanf("%d", &R[i]);
    }
    sort(R.begin(), R.end());
    R.push_front(0); R.push_back(L);
    
    int left=1, right=L;
    
    N += 2;
    while(left <= right) {
        int mid = (left + right) >> 1;
        
        bool flag = true;
        
        int walls = M;
        for(int i=0; i<N-1; ++i) {
            int needed = (int)((R[i+1] - R[i]) / mid) - 1;
            if((R[i+1] - R[i]) % mid > 0) needed += 1;
            if(walls >= needed) walls -= needed;
            else {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    
    return 0;
}
