#include <iostream>
#include <cmath>
#define INF 20000000
using namespace std;

struct co{
    int x;
    int y;
    int operator- (const co &other) const {
        return abs(x - other.x) + abs(y - other.y);
    }
};

int N, M, cuts, min_dist = INF;
int house_cnt = 0, chicken_cnt = 0;
int dist[105][15];

co houses[105];
co chickens[15];

bool checked[15];

void get_min_dist(int n, int m) {
    int total_dist = 0;
    for(int i=0; i<n; ++i) {
        int row_min = INF;
        for(int j=0; j<m; ++j) {
            if(checked[j]) continue;
            row_min = row_min > dist[i][j] ? dist[i][j] : row_min;
        }
        total_dist += row_min;
    }
    min_dist = min_dist > total_dist ? total_dist : min_dist;
}

void dfs(int cnt, int last) {
    if(cnt == 0) {
        get_min_dist(house_cnt, chicken_cnt);
    }
    
    for(int i=last; i<chicken_cnt; ++i) {
        checked[i] = true;
        dfs(cnt - 1, i+1);
        checked[i] = false;
    }
}

int main(void) {
    
    // dist 초기화
    for(int i=0; i<105; ++i) {
        for(int j=0; j<15; ++j) {
            dist[i][j] = INF;
        }
    }
    
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            int tmp; scanf("%d", &tmp);
            if(tmp == 1) houses[house_cnt++] = {i, j};
            if(tmp == 2) chickens[chicken_cnt++] = {i, j};
        }
    }
    
    for(int i=0; i<house_cnt; ++i) {
        for(int j=0; j<chicken_cnt; ++j) {
            dist[i][j] = houses[i] - chickens[j];
        }
    }
    
    cuts = chicken_cnt - M;
    dfs(cuts, 0);
    
    printf("%d\n", min_dist);
    
    return 0;
}
