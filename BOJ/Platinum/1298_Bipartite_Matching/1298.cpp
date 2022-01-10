#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int N, M, A[105], B[105], cnt;
vector<int> graph[105];
bool visited[105];

bool DFS(int n){
    visited[n] = true;
    for(int idx : graph[n]){
        if(B[idx] == -1 || (!visited[B[idx]] && DFS(B[idx]))){
            A[n] = idx;
            B[idx] = n;
            return true;
        }
    }
    return false;
}

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i){
        int n, m;
        scanf("%d %d", &n, &m);
        graph[n].push_back(m);
    }
    
    fill(A, A+105, -1);
    fill(B, B+105, -1);
    
    for(int i=1; i<=N; ++i){
        fill(visited, visited + N, false);
        if(DFS(i)) cnt += 1;
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
