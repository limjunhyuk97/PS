#include <iostream>
#include <queue>
#define MAXLEN 200005
#define INF 2000000000
using namespace std;

struct node {
    int dist;
    int idx;
    bool operator<(const node & other) const {
        return dist > other.dist;
    }
};

int N, K;
int dist[MAXLEN];

int main(void) {
    
    scanf("%d %d", &N, &K);
    
    fill(&dist[0], &dist[MAXLEN], INF);
    
    priority_queue<node> pq;
    pq.push({0, N});
    dist[N] = 0;
    
    while(!pq.empty()) {
        node cur = pq.top(); pq.pop();
        
        if(cur.idx == K) break;
        
        if(cur.dist > dist[cur.idx]) continue;
        
        if(cur.idx * 2 <= 100000 && dist[cur.idx*2] > cur.dist) {
            dist[cur.idx*2] = cur.dist;
            pq.push({cur.dist, cur.idx * 2});
        }
        
        if(cur.idx + 1 <= 100000 && dist[cur.idx+1] > cur.dist + 1) {
            dist[cur.idx+1] = cur.dist + 1;
            pq.push({cur.dist + 1, cur.idx + 1});
        }
        
        if(cur.idx - 1 >= 0 && dist[cur.idx-1] > cur.dist + 1) {
            dist[cur.idx-1] = cur.dist + 1;
            pq.push({cur.dist + 1, cur.idx - 1});
        }
    }
    
    printf("%d\n", dist[K]);
    
    return 0;
}
