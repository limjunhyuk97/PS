// 육각수의 갯수를 미리 구해놓는다.
// N을 최소한의 수로 끼워 맞추는 방법 - Knapsack

// 1
// cnt=1 6 = 1 + 6 - 1
// cnt=2 15 = 6 + 12 - 3
// cnt=3 28 = 15 + 18 - 5

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define INF 10000
using namespace std;

int N, yukkaknum=1, DP[1000005];
vector<int> yukkak;
queue<int> care;

int main(void){
    
    scanf("%d", &N);
    
    // DP 초기화
    fill(DP, DP+1000005, INF);
    
    // 육각수 생성
    int cnt = 1;
    yukkak.push_back(1);
    care.push(1);
    DP[1] = 1;
    while(true) {
        yukkaknum += cnt * 6 - (2*cnt - 1);
        cnt += 1;
        if(yukkaknum > 1000000) break;
        else {
            yukkak.push_back(yukkaknum);
            care.push(yukkaknum);
            DP[yukkaknum] = 1;
        }
    }
    
    // 값을 하나씩 추가함
    cnt = 1;
    while(!care.empty()) {
        int size = (int)care.size();
        cnt += 1;
        for(int i=0; i<size; ++i) {
            int cur = (int)care.front(); care.pop();
            for(int j=0; yukkak[j] + cur < 1000001 && j < yukkak.size(); ++j) {
                int next = cur + yukkak[j];
                if(DP[next] != INF) continue;
                DP[next] = cnt;
                care.push(next);
            }
        }
    }
    
    printf("%d\n", DP[N]);
    
    return 0;
}

