// 23296번 풀이중

#include <iostream>
#include <queue>
#include <vector>
#define MAX_LEN 100003
using namespace std;

int N;
int graph[MAX_LEN];
bool moved[MAX_LEN];
int in[MAX_LEN];

priority_queue<pair<int,int> > pq;
vector<int> ans;

void dfs() {
    int cur = 1;
    
    while(!pq.empty()) {
        while(!moved[cur]) {
            ans.push_back(graph[cur]);
            moved[cur] = true;
            cur = graph[cur];
            in[cur] -= 1;
        }
        while(!pq.empty()) {
            
        }
    }
}

int main(void) {
    
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        int destination; scanf("%d", &destination);
        graph[i] = destination;
        in[destination] += 1;
    }
    
    dfs();
    
    return 0;
}
