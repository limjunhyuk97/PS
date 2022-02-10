// BFS 풀이 가능
// Floyd-Warshall 풀이 가능

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 2000000000
using namespace std;

typedef pair<int, int> node;

int N, M, CB[105], ansIdx, ansCB=(int)INF;
vector<int> graph[105];

int BFS(int start){
    int cb[105], sum=0;
    for(int i=0; i<105; ++i) cb[i] = (int)INF;
    queue<node> tmpQue;
    tmpQue.push({start, 0});
    while(!tmpQue.empty()){
        node cur = tmpQue.front(); tmpQue.pop();
        if(cur.second > cb[cur.first]) continue;
        cb[cur.first] = cur.second;
        for(int i=0; i<graph[cur.first].size(); ++i){
            if(cb[graph[cur.first][i]] > cur.second + 1){
                tmpQue.push({graph[cur.first][i], cur.second + 1});
            }
        }
    }
    for(int i=1; i<=N; ++i)
        sum += cb[i];
    return sum;
}

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i){
        int n, m; scanf("%d %d", &n, &m);
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
    
    for(int i=1; i<=N; ++i)
        CB[i] = BFS(i);
    
    for(int i=N; i>=1; --i){
        if(ansCB>=CB[i]){
            ansCB=CB[i];
            ansIdx=i;
        }
    }
    
    printf("%d\n", ansIdx);
    
    return 0;
}
