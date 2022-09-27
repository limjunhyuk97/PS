// 너무 좋은 문제..! : DFS와 DP로 경로탐색 최적화

// 그냥 BFS -> 오답
// 들어가는 inflow 0인 놈들만 차례대로 뽑아내기 -> priority_queue의 pop 갱신이 되지 않아서 불가능했었음 -> 오답
// 그렇다면 DFS...? -> DFS + DP를 이용하면 "경로떡밥회수"가 가능하다 !!!
//  - 경로에 대한 고려를 (시작지점 ~ 특정지점)까지 도달가능한 경로 수에 대한 고려가 아니라
//  - (특정지점 ~ 종말지점)로 도달가능한 경로 수에 대한 고려로 진행
//  - 즉, "DFS + DP(top-down)" 으로 떡밥 회수를 진행한다.
//      - DFS만 이용 : 전체 가능한 경로를 일일이 다 세는 것. 즉, 경로 기준 횟수 연산.
//      - DFS + DP(top-down) : 경로 기준 횟수 연산 -> 칸 기준 횟수 연산

#include <iostream>
using namespace std;

int grid[505][505], DP[505][505];
int dx[4]={0, 0, 1, -1};
int dy[4]={-1, 1, 0, 0};
int N, M;

int DFS(int m, int n){
    if(m==M-1 && n==N-1) return 1;
    if(DP[m][n]!=-1) return DP[m][n];
    DP[m][n]=0;
    for(int i=0; i<4; ++i){
        int nx=m+dx[i], ny=n+dy[i];
        if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
        if(grid[m][n]>grid[nx][ny]) DP[m][n] += DFS(nx, ny);
    }
    return DP[m][n];
}

int main(void){
    
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &grid[i][j]);
            DP[i][j]=-1;
        }
    }
    
    printf("%d\n", DFS(0, 0));
    
    return 0;
}

