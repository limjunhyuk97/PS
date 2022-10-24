#include <iostream>
#include <queue>
#include <cmath>
#define MAX_LEN 1005
#define INF 2000000000
using namespace std;

int N, W;
double M;

pair<int, int> factory[MAX_LEN];
double dist[MAX_LEN];
double factory_distance[MAX_LEN][MAX_LEN];

void dijkstra(int cur) {
    priority_queue<pair<double, int> > pq;
    pq.push({0, cur});
    
    while(!pq.empty()) {
        double curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(curDist > dist[cur]) continue;
        
        for(int i=1; i<=N; ++i) {
            // 새로 만들 수 있는 경로가 있는 경우에만 고려하자
            if(factory_distance[cur][i] == INF) continue;
            if(curDist + factory_distance[cur][i] < dist[i]) {
                dist[i] = curDist + factory_distance[cur][i];
                pq.push({-dist[i], i});
            }
        }
    }
}

double get_factory_distance(int f1, int f2) {
    return sqrt((double)(factory[f1].first - factory[f2].first)*(factory[f1].first - factory[f2].first) + (double)(factory[f1].second - factory[f2].second)*(factory[f1].second - factory[f2].second));
}

int main(void) {
    cin >> N >> W;
    cin >> M;
    
    // 공장 입력
    for(int i=1; i<=N; ++i) {
        int x, y; cin >> x >> y;
        factory[i] = {x, y};
    }
    
    // 공장간 거리 초기화
    for(int i=0; i<MAX_LEN; ++i) {
        dist[i] = INF;
        for(int j=0; j<MAX_LEN; ++j) {
            factory_distance[i][j] = INF;
        }
    }
    
    // 이미 있는 전선에 대해서는 경로 0 처리
    for(int i=0; i<W; ++i) {
        int f1, f2; cin >> f1 >> f2;
        factory_distance[f1][f2] = 0;
        factory_distance[f2][f1] = 0;
    }
    
    // 공장간 거리 전수조사 + M 초과이면 INF
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(i==j) continue;
            double distance = get_factory_distance(i, j);
            if(M >= distance && factory_distance[i][j] != 0) {
                factory_distance[i][j] = distance;
                factory_distance[j][i] = distance;
            }
        }
    }
    
    // 최단 경로 구하기
    dijkstra(1);
    
    cout << (int)(dist[N]*1000) << endl;
}
