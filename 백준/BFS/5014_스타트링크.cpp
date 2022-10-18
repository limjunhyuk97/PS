// 1차원 배열에서의 BFS와 같다.

#include <iostream>
#include <algorithm>
#include <queue>
#define IMPOSSIBLE_MSG "use the stairs"
#define MAX_LEN 1000003
using namespace std;

int F, S, G, U, D;
int ans = -1;

void bfs() {
    
    bool visited[MAX_LEN];
    fill(&visited[0], &visited[MAX_LEN], false);
    
    queue<int> q;
    q.push(S);
    visited[S] = true;
    
    int dist = 0;
    while(!q.empty() && ans == -1) {
        int size = (int)q.size();
        for(int i=0; i<size; ++i) {
            int cur = q.front(); q.pop();
            if(cur == G) {
                ans = dist;
                break;
            }
            int prev = cur - D;
            int next = cur + U;
            // queue에 들어가는 순간 방문했다고 친다.
            if(prev > 0 && !visited[prev]) {
                q.push(prev);
                visited[prev] = true;
            }
            if(next <= F && !visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
        dist += 1;
    }
}

int main(void) {
    
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    
    bfs();
    
    if(ans == -1) printf("%s\n", IMPOSSIBLE_MSG);
    else printf("%d\n", ans);
    
    return 0;
}
