#include <iostream>
#include <utility>
#include <cmath>
#include <set>
using namespace std;

typedef pair<int, int> coordinate;

int N, ways;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
double prob[4], simple;
set<coordinate> trace;

void DFS(int x, int y, int n, double cur){
    if(n==N){
        simple += cur;
        return;
    }
    for(int i=0; i<4; ++i){
        if(prob[i]==0) continue;
        int tmpX=x+dx[i], tmpY=y+dy[i];
        if(trace.find({tmpX, tmpY}) != trace.end()) continue;
        trace.insert({tmpX, tmpY});
        DFS(tmpX, tmpY, n+1, cur * prob[i]);
        trace.erase({tmpX, tmpY});
    }
}

int main(void){
    
    int e, w, s, n;
    scanf("%d %d %d %d %d", &N, &e, &w, &s, &n);
    prob[0] = e/100.0; prob[1] = w/100.0; prob[2] = s/100.0; prob[3] = n/100.0;
    for(int i=0; i<4; ++i){
        if(prob[i] != 0){
            ways += 1;
        }
    }
    
    trace.insert({0, 0});
    DFS(0, 0, 0, 1);
    printf("%.15lf\n", simple/(double)1);
    
    return 0;
}
