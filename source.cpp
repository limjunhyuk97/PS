#include <iostream>
#include <algorithm>
using namespace std;

int N;
int grid[1025][1025];

// 왼쪽 위 (x1, y1) ~ 오른쪽 아래 (x2, y2)
int pooling(int x1, int y1, int x2, int y2) {
    if(x1==x2 && y1 == y2) return grid[x1][y1];
    
    int len = x2 - x1 + 1;
    int h = len / 2;
    int d = h - 1;
    
    int s1 = pooling(x1, y1, x1 + d, y1 + d);
    int s2 = pooling(x1, y1 + h, x1 +d, y1 + h + d);
    int s3 = pooling(x1 + h, y1, x1 + h + d, y1 + d);
    int s4 = pooling(x1 + h, y1 + h, x1 + h + d, y1 + h + d);
    
    int cand[4] = {s1, s2, s3, s4};
    
    sort(&cand[0], &cand[4]);
    
    return cand[2];
}

int main(void) {
    
    scanf("%d", &N);
    
    // 데이터 입력 받기
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
           scanf("%d", &grid[i][j]);
        }
    }
    
    printf("%d\n", pooling(0, 0, N-1, N-1));
    
    return 0;
    
}
