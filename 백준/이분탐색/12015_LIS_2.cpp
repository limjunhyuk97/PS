// LIS (이분 탐색)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> LIS;

int main(void) {
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        int cur; scanf("%d", &cur);
        
        if(LIS.empty()) LIS.push_back(cur);
        else {
            if(LIS.back() < cur) LIS.push_back(cur);
            else {
                int pos = (int)(lower_bound(LIS.begin(), LIS.end(), cur) - LIS.begin());
                LIS[pos] = cur;
            }
        }
    }
    
    printf("%d\n", (int)LIS.size());

    return 0;
}
