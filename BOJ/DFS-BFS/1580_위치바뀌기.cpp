#include <iostream>
using namespace std;

int N, M;
int dx[8]={1, 0, 1, -1, 1, -1, 0, -1};
int dy[8]={1, 1, 0, 1, -1, 0, -1, -1};
char grid[20][20];

void

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf("%c", &grid[i][j]);
        }
    }
    
    
    
    return 0;
}
