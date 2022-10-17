// 부모-> 자식 그래프 생성 (vector)
// 자식-> 부모 관계 생성 (array)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_LEN 103
using namespace std;

int n, a, b, relation, final_dist;
vector<int> child[MAX_LEN];
int parent[MAX_LEN];
bool visited[MAX_LEN];

void BFS(int cur, int *dist) {
    if(visited[cur]) return;
    visited[cur] = true;
    
    queue<int> q;
    q.push(cur);
    
    int cnt = 0;
    while(!q.empty()) {
        int size = (int)q.size();
        for(int i=0; i<size; ++i) {
            int cur = q.front();
            q.pop();
            
            visited[cur] = true;
            if(cur == b) {
                *dist = cnt;
                return;
            }
            
            for(int i=0; i<child[cur].size(); ++i) {
                if(visited[child[cur][i]]) continue;
                q.push(child[cur][i]);
            }
        }
        cnt += 1;
    }
    *dist = -1;
}

int main(void) {
    
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &relation);
    
    fill(&parent[0], &parent[MAX_LEN], -1);
    for(int i=0; i<relation; ++i) {
        int p, c;
        scanf("%d %d", &p, &c);
        parent[c] = p;
        child[p].push_back(c);
    }
    
    for(int cur=a, upper=0; ; cur = parent[cur], upper++) {
        if(cur == -1) break;
        int dist = 0;
        BFS(cur, &dist);
        if(dist != -1) {
            final_dist = upper + dist;
            break;
        }
    }
    
    printf("%d\n", final_dist == 0 ? -1 : final_dist);
    
    return 0;
}
