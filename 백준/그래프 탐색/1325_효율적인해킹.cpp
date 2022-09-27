// A가 B를 신뢰한다. A<-B. B를 해킹하면 A 도 해킹할 수 있다.
// 3<-1 3<-2 4<-3 5<-3

// 정점을 찾는다.
// 정점에서 끝까지 DFS를 진행한다.
// 이미 찾는 것이 진행된 녀석들에 대해서는 더이상 연산하지 않는다.

#include <iostream>
#include <vector>
using namespace std;

int N, M, maxDive, depth[100005];
vector<int> graph[100005], result;
bool checked[100005];

void DFS(int n) {
    checked[n] = true;
    for(int i=0; i<graph[n].size(); ++i){
        if(graph[n][i]) depth[n] += depth[graph[n][i]];
        else DFS(graph[n][i]);
    }
    if(maxDive < depth[n])
}

int main(void){

    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i){
        int before, after; scanf("%d %d", &after, &before);
        graph[before].push_back(after);
    }
    
    for(int i=1; i<=N; ++i) depth[i] = 1;
    
    for(int i=1; i<=N; ++i){
        if(!checked[i]) DFS(i);
    }
    
    return 0;
}
