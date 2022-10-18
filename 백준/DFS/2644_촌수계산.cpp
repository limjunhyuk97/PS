// 양방향 연결 그래프와 DFS
// 그래프에서 n - m 사이의 거리를 구하기 위해서 "양방향 연결 그래프 + DFS"를 사용할 수 있다.

#include <iostream>
#include <vector>
#define MAX_LEN 103
using namespace std;

int n, a, b, relations;
vector<int> graph[MAX_LEN];
bool visited[MAX_LEN];

void DFS(int cur, int dist, int *ret) {
    if(visited[cur]) return;
    visited[cur] = true;
    
    if(cur == b) {
        *ret = dist;
        return;
    }
    
    for(int i=0; i<graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if(!visited[next]) DFS(next, dist + 1, ret);
    }
}

int main(void) {
    
    int dist = -1;
    
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &relations);
    
    for(int i=0; i<relations; ++i) {
        int p, c; scanf("%d %d", &p, &c);
        graph[p].push_back(c);
        graph[c].push_back(p);
    }
    
    DFS(a, 0, &dist);
    
    printf("%d\n", dist);
    
    return 0;
}
