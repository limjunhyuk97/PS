// 처음에 계획을 잘못짰음..
// 그냥 적의 위치까지 그래프에 넣고 -> 그래프의 노드를 연결하는 작업을 수행한 뒤 -> BFS를 수행해서 거리를 계산하면 되는 거였음

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

typedef pair<int, int> coordinate;

int N, R, D;
coordinate enemy_tower[55];
vector<int> graph[55];
double damage;

double get_distance(const coordinate &c1, const coordinate &c2){
    return sqrt(double((c1.first-c2.first)*(c1.first-c2.first)+(c1.second-c2.second)*(c1.second-c2.second)));
}

bool check_distance(double distance){
    return distance <= (double)R;
}

void connect_nodes(int n){
    for(int i=0; i<=N; ++i){
        if(i == n) continue;
        if(check_distance(get_distance(enemy_tower[n], enemy_tower[i]))) graph[n].push_back(i);
    }
}

double BFS(){
    int distance[55], cnt = -1;
    bool checked[55];
    fill(&distance[0], &distance[55], 0);
    fill(&checked[0], &checked[55], false);
    queue<int> tmpQue; tmpQue.push(0); checked[0]=true;
    while(!tmpQue.empty()){
        int len = (int)tmpQue.size(); cnt += 1;
        for(int i=0; i<len; ++i){
            int cur=tmpQue.front(); tmpQue.pop();
            for(int j=0; j<graph[cur].size(); ++j){
                if(!checked[graph[cur][j]]){
                    distance[graph[cur][j]] = cnt;
                    tmpQue.push(graph[cur][j]);
                    checked[graph[cur][j]]=true;
                }
            }
        }
    }
    double sum = 0;
    sum += (double)(graph[0].size() * D);
    for(int i=1; i<=N; ++i){
        if(distance[i]!=0){
            sum += D / pow((double)2, (double)distance[i]);
        }
    }
    return sum;
}

int main(void){
    
    scanf("%d %d %d %d %d", &N, &R, &D, &enemy_tower[0].first, &enemy_tower[0].second);
    for(int i=1; i<=N; ++i){
        scanf("%d %d", &enemy_tower[i].first, &enemy_tower[i].second);
    }
    
    // 선 연결 - 그래프 생성
    for(int i=0; i<=N; ++i){
        connect_nodes(i);
    }
    
    // 출력
    printf("%.3f\n", BFS());
    
    return 0;
}
