#include <iostream>
#define INF 2000000000
using namespace std;

struct coordinate{
    int x;
    int y;
    bool operator==(const coordinate & other){
        return x==other.x && y==other.y;
    }
};

int N, M, len=INF;
int dx[8]={1, 0, 1, -1, 1, -1, 0, -1};
int dy[8]={1, 1, 0, 1, -1, 0, -1, -1};
char grid[25][25];
bool checkA[24][24], checkB[24][24];
coordinate A, B;

void DFS(coordinate a, coordinate b, int n){
    if(n > len) return;
    if(a==B && b==A){
        if(len>n) len=n;
        return;
    }
    for(int i=0; i<8; ++i){
        coordinate nextA={a.x+dx[i], a.y+dy[i]};
        if(checkA[nextA.x][nextA.y] || nextA.x<0 || nextA.x>=N || nextA.y<0 || nextA.y>=M || grid[nextA.x][nextA.y]=='X' || checkA[nextA.x][nextA.y]) continue;
        if(a==B) {
            nextA = a;
            goto skipA;
        }
        checkA[nextA.x][nextA.y]=true;
        skipA:
        for(int j=0; j<8; ++j){
            coordinate nextB={b.x+dx[j], b.y+dy[j]};
            if(b==A){
                nextB=b;
                goto skipB;
            }
            if(checkB[nextB.x][nextB.y] || nextB.x<0 || nextB.x>=N || nextB.y<0 || nextB.y>=M || grid[nextB.x][nextB.y]=='X' || checkB[nextB.x][nextB.y]) continue;
            if( (b==nextA && nextB==a) || nextA==nextB) continue;
            skipB:
            checkB[nextB.x][nextB.y]=true;
            DFS(nextA, nextB, n+1);
            checkB[nextB.x][nextB.y]=false;
        }
        checkA[nextA.x][nextA.y]=false;
    }
}

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        scanf("%s", &grid[i]);
        for(int j=0; j<M; ++j){
            if(grid[i][j]=='A') A={i,j};
            if(grid[i][j]=='B') B={i,j};
        }
    }
    
    checkA[A.x][A.y]=true; checkB[B.x][B.y]=true;
    DFS(A, B, 0);
    
    if(len==INF) printf("-1\n");
    else printf("%d\n",len);
    
    return 0;
}
