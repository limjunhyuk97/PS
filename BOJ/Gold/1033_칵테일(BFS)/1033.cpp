#include <iostream>
#include <sstream>
#include <string>
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
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

vector<int> graph[12];
int N, combination[12][4];
int portion[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int GCD(int n, int m) {
    return m !=0 ? GCD(m, n % m) : n;
}

int LCM(int n, int m){
    return n / GCD(n, m) * m;
}

// 지점 n과 연결된 노드들에 대해서 weight만큼 곱해준다.
void BFS(int n, int ignore, int weight){
    
    queue<int> nodes;
    bool portion_bool[12];
    for(int i=0; i<12; ++i)
        portion_bool[i] = false;
    
    portion_bool[n] = true; portion_bool[ignore] = true;
    for(int i=0; i<graph[n].size(); ++i)
        if(!portion_bool[graph[n][i]]){
            nodes.push(graph[n][i]);
            portion_bool[graph[n][i]] = true;
        }
        
    while(!nodes.empty()){
        int cur = nodes.front();
        nodes.pop();
        
        portion[cur] *= weight;
        for(int i=0; i<graph[cur].size(); ++i){
            if(!portion_bool[graph[cur][i]]){
                nodes.push(graph[cur][i]);
                portion_bool[graph[cur][i]] = true;
            }
        }
    }
    
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N - 1; ++i){
        for(int j=0; j<4; ++j){
            cin >> combination[i][j];
        }
        // 그래프 상으로 연결 완료
        if(combination[i][2] !=0 && combination[i][3] != 0){
            graph[combination[i][0]].push_back(combination[i][1]);
            graph[combination[i][1]].push_back(combination[i][0]);
        }
    }
    
    for(int i=0; i<N - 1; ++i){
        // 비율에 0이 있다면 관련없는 것이므로 무시
        if(combination[i][2] != 0 && combination[i][3] != 0){
            
            int a = combination[i][0], b = combination[i][1], p = combination[i][2], q = combination[i][3];
            // 새로 설정해줘야하는 비례관계가 기존과 일치한다면?
            if(portion[b] * p == portion[a] * q)
                continue;
            
            // lcm : 기존의 값들의 최소공배수
            int lcm = LCM(portion[a], portion[b]);
            BFS(a, b, lcm * p / portion[a]);
            portion[a] = lcm * p;
            
            BFS(b, a, lcm * q / portion[b]);
            portion[b] = lcm * q;
        }
    }
    
    int gcd = GCD(portion[0], portion[1]);
    for(int i=2; i<N; ++i){
        gcd = GCD(gcd, portion[i]);
    }
    
    for(int i=0; i<N; ++i)
        cout << portion[i] / gcd << " ";
    cout << endl;
    
    return 0;
}
