#include <iostream>
#include <queue>
using namespace std;

struct coordinate{
    int x;
    int y;
};

struct node{
    coordinate cur;
    char
}

coordinate defaultA, defaultB;
char grid[22][22];
int N, M, cnt;
int dx[8]={1, 1, 0, 1, -1, 0, -1, -1};
int dy[8]={1, 0, 1, -1, 1, -1, 0, -1};

void BFS(){
    coordinate curA=defaultA, curB=defaultB;
    queue<coordinate> tmpQue;
    tmpQue.push(curA);
    
}

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        scanf("%s", &grid[i]);
        for(int j=0; j<M; ++j){
            if(grid[i][j]=='A') defaultA={i, j};
            if(grid[i][j]=='B') defaultB={i, j};
        }
    }
    
    BFS();
    
    if(cnt==0) printf("-1\n");
    else printf("%d\n", cnt);
    
    return 0;
}
