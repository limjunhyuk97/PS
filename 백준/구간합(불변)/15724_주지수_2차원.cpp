// 미리 누적합 DP
#include <iostream>
#define MAXLEN 1111
using namespace std;

int N, M, K;
int grid[MAXLEN][MAXLEN];

int main(void) {
    
    scanf("%d %d", &N, &M);

    // 배열 정보 받기
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    // 초기 누적합 연산
    // - ACC : 누적 저장 배열, A : 기존 배열 일 때 (기존 배열을 변경시켜도 상관 없다면 ACC 따로 선언하지 않아도 됨)
    // - 숫자가 들어있는 공간이 인덱스 1에서 부터 시작한다 했을 떄
    // - ACC[i][j] = ACC[i-1][j] + ACC[i][j-1] - ACC[i-1][j-1] + A[i][j];
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }
    
    // 불변 누적합의 구간합 꺼내기
    // - ACC : 누적 저장 배열 일 때
    // - (x1,y1) ~ (x2,y2) : ACC[x2][y2] - ACC[x2][y1-1] - ACC[x1-1][y2] + ACC[x1-1][y1-1]
    scanf("%d", &K);
    for(int i=0; i<K; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", grid[x2][y2]-grid[x2][y1-1]-grid[x1-1][y2]+grid[x1-1][y1-1]);
    }
    
    return 0;
}
