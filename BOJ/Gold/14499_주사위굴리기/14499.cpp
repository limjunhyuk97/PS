#include <iostream>
using namespace std;

int N, M, x, y, K;
int grid[25][25], command[1005];
int dice[6];

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void roleTheDice(int direction) {
    
    int tmp;
    
    switch (direction) {
        case 1:
            tmp = dice[1]; dice[1] = dice[3];
            dice[3] = dice[0];
            dice[0] = dice[5];
            dice[5] = tmp;
            break;
        case 2:
            tmp = dice[3]; dice[3] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[0];
            dice[0] = tmp;
            break;
        case 3:
            tmp = dice[0]; dice[0] = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[4];
            dice[4] = tmp;
            break;
        case 4:
            tmp = dice[2]; dice[2] = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[1];
            dice[1] = tmp;
            break;
        default :
            break;
    }
    
    return ;
}

int main(void){
    
    // get input
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    for(int i=0; i<K; ++i) {
        scanf("%d", &command[i]);
    }
    
    for(int i=0; i<K; ++i) {
        int nx = x + dx[command[i]];
        int ny = y + dy[command[i]];
        
        // x, y 갱신 = 즉 이동이 일어남
        if(nx <0 || nx >= N || ny<0 || ny >=M) continue;
        else {
            x = nx;
            y = ny;
        }
        
        // 주사위 돌리기
        roleTheDice(command[i]);
        
        // 지도에 0값 O
        if(grid[x][y] == 0) {
            grid[x][y] = dice[1];
        }
        // 지도에 0값 X
        else {
            dice[1] = grid[x][y];
            grid[x][y] = 0;
        }
        
        printf("%d\n", dice[0]);
    }
    
    
    return 0;
}
