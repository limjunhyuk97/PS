// 백트래킹
// - DFS 시간단축 : 어디까지 고려했는지에 대한 인덱스 정보가 있어야 한다.
// - 세로선 떨어지는 위치 확인에 대한 시간단축 : 0, +1, -1로 정보 표현가능하다. 굳이 map 안써도 됨
// - promising과 solution 연산 : 'promising은 더 짧은 시간 안에 탐색이 가능한가 여부', 'solution은 세로축에서 자기 위치로 다시 떨어질 수 있는지 여부'

#include <iostream>
#include <map>
#define MAX_N 15
#define MAX_H 35
using namespace std;

int N, M, H;
int nl = 4;

int checked[MAX_H][MAX_N];

bool solution() {
    // 세로선 떨어졌을 때 위치 확인
    for(int i=1; i<=N; ++i) {
        int dest = i;
        for(int j=1; j<=H; ++j) {
            if(checked[j][dest] != 0) {
                if(checked[j][dest] == dest + 1) dest += 1;
                else dest -= 1;
            }
        }
        if(dest != i) return false;
    }
    
    return true;
}

void dfs(int cnt, int row) {
    // promising
    if(cnt >= nl) return;

    if(solution()) {
        nl = cnt;
        return;
    }
    
    for(int i=row; i<=H; ++i) {
        for(int j=1; j<N; ++j) {
            if(checked[i][j] != 0 || checked[i][j+1] != 0) continue;
            checked[i][j] = j+1; checked[i][j+1] = j;
            dfs(cnt + 1, i);
            checked[i][j] = 0; checked[i][j+1] = 0;
        }
    }
    
    return;
}

int main(void) {
    
    scanf("%d %d %d", &N, &M, &H);
    
    for(int i=0; i<M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        checked[a][b] = b+1;
        checked[a][b+1] = b;
    }
    
    dfs(0 , 1);
    
    printf("%d\n", nl == 4 ? -1 : nl);
    
    return 0;
}
