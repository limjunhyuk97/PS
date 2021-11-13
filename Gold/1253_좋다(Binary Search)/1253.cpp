// 투 포인터를 사용한 선형시간 내 탐색
// 양쪽에서 줄여나가거나, 앞에서부터 찾아서 들어가거나
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int N, arr[2005], cnt;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", arr + i);
    
    sort(arr, arr + N);
    
    for(int i=0; i<N; ++i){
        vector<int> vec;
        for(int j=0; j<N; ++j){
            if(j == i) continue;
            vec.push_back(arr[j]);
        }
        int l = 0, r = N-2;
        while(l < r){
            if(vec[l] + vec[r] == arr[i]){
                cnt += 1;
                break;
            }
            else if(vec[l] + vec[r] < arr[i]) l += 1;
            else r -= 1;
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
