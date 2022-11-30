
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define MAXLEN 20
using namespace std;

struct node{
    int state;
    int last_buyer;
};

int N;
int DP[1<<16][16];
int arr[MAXLEN][MAXLEN];
int buyers;

int owner_cnt(int num) {
    int cnt = 0;
    for(int i=0; i<N; ++i) {
        if(num & (1<<i)) cnt += 1;
    }
    return cnt;
}

int main(void) {
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        string str; cin >> str;
        for(int j=0; j<N; ++j) {
            arr[i+1][j+1] = str[j] - '0';
        }
    }
    
    // DP 초기화
    for(int i=0; i< (1<<16); ++i) {
        for(int j=0; j<16; ++j) {
            DP[i][j] = 20;
        }
    }
    DP[1<<(N-1)][1] = 0;
    
    // pq에 넣고 돌리기 시작
    queue<node> pq;
    pq.push({1<<(N-1), 1});
    
    while(!pq.empty()) {
        node cur = pq.front();
        pq.pop();
        
        int status = cur.state;
        int last_buyer = cur.last_buyer;

        buyers = max(owner_cnt(status), buyers);
        
        for(int next_buyer=1; next_buyer<=N; ++next_buyer) {
            if(last_buyer == next_buyer) continue;
            int next_status = status | (1<<(N-next_buyer));
            if(DP[status][last_buyer] <= arr[last_buyer][next_buyer] && DP[next_status][next_buyer] >= arr[last_buyer][next_buyer]) {
                DP[next_status][next_buyer] = arr[last_buyer][next_buyer];
                pq.push({next_status, next_buyer});
            }
        }
        
    }
    
    cout << buyers << endl;
    
    return 0;
}
