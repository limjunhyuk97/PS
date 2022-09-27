#include <iostream>
#include <utility>
#include <set>
using namespace std;

typedef long long int ll;
typedef pair<int, int> coo;

int N, M, K;
ll DP[111][111];
set<coo> cuts[111][111];

int dx[2] = {-1, 0};
int dy[2] = {0, -1};

int main(void){
    
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    for(int i=0; i<K; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1+y1 > x2+y2) cuts[x1][y1].insert(make_pair(x2, y2));
        else cuts[x2][y2].insert(make_pair(x1, y1));
    }
    
    DP[0][0] = 1;
    for(int y=0; y<=M; ++y) {
        for(int x=0; x<=N; ++x) {
            ll weight = 0;
            for(int i=0; i<2; ++i) {
                int sourceX = x + dx[i], sourceY = y + dy[i];
                if(sourceX < 0 || sourceY < 0) continue;
                if(cuts[x][y].find({sourceX, sourceY}) == cuts[x][y].end())
                    weight += DP[sourceX][sourceY];
            }
            DP[x][y] += weight;
        }
    }
    
    printf("%lld\n", DP[N][M]);
    
    return 0;
}
