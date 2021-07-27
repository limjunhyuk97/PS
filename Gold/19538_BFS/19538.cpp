#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#define MAXVERTEX 200005
using namespace std;

int N, u, M;
bool check[MAXVERTEX];
int rumorCount[MAXVERTEX];
int phaseCount[MAXVERTEX];
vector<int> graph[MAXVERTEX];
queue<int> nextOne;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=1; i<=N; ++i){
        while(true){
            cin >> u;
            if(u) graph[i].push_back(u);
            else break;
        }
    }
    
    for(int i=0; i<MAXVERTEX; ++i)
        phaseCount[i] = -1;
    
    cin >> M;
    for(int i=0; i<M; ++i){
        cin >> u;
        check[u] = true;
        nextOne.push(u);
        phaseCount[u] = 0;
    }
    
    while(!nextOne.empty()){
        int cur = nextOne.front(); nextOne.pop();
        for(int i=0; i<graph[cur].size(); ++i){
            if(!check[graph[cur][i]]){
                ++rumorCount[graph[cur][i]];
                if( (graph[graph[cur][i]].size() %2 == 0 &&
                   rumorCount[graph[cur][i]] >= graph[graph[cur][i]].size() / 2 ) ||
                   (graph[graph[cur][i]].size() %2 == 1 &&
                    rumorCount[graph[cur][i]] > graph[graph[cur][i]].size() / 2) ){
                    check[graph[cur][i]] = true;
                    nextOne.push(graph[cur][i]);
                    phaseCount[graph[cur][i]] = phaseCount[cur] + 1;
                }
            }
        }
    }
    
    for(int i=1; i<=N; ++i){
        cout<<phaseCount[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}

