/*
 플로이드 워셜 : (i,j) <-> (x,y) 간의 최단거리를 구해야 하는 경우 사용한다.
    - 초기 엣지 weight 설정
    - "k를 경유하여 i에서 j로 가는 최단 거리 연산"을 전체 노드들에 대해서 반복하며 갱신한다.
*/
/*
 어떻게 접근해야 할까
    - (0,0) -> (x,y) 의 거리 + (x,y) -> (0,0) 의 거리를 알아야 한다.
    - 때문에 다익스트라나 플로이드 와셜을 사용할 수 있을 것이다.
 이 문제에 추가되는 조건
    - 엣지 weight 값을 메기는 조건이 부여되어 있다.
    - 노드가 (x,y)와 같이 두개의 숫자로 대표된다.
*/

#include <iostream>
#include <algorithm>
#include <string>
#define MAXLEN 25
#define INF 1000000000
using namespace std;

string Mountain[MAXLEN];
int N, M, T, D;

int maxHeight = -1;

int dist[MAXLEN][MAXLEN][MAXLEN][MAXLEN];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool OOB(int x, int y) {
    if(x<0 || x>=N || y<0 || y>=M) return true;
    else return false;
}

int getHeight(const char & c) {
    if('a' <= c && c <= 'z') return c - 'a' +26;
    else return c-'A';
}

int getGap(const char & a, const char & b) {
    return getHeight(a) - getHeight(b);
}

int getTime(const char &s, const char &e) {
    int gap = getGap(s, e);
    if(T>= gap && gap >= 0) return 1;
    else if(-T<= gap && gap < 0) return gap * gap;
    else return INF;
}

// (i,j) -> (x,y) 로 가는 최소 시간 계산
void floydWarshall() {
    // init (i,j) -> (k, l)
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            for(int k=0; k<MAXLEN; ++k) {
                for(int l=0; l<MAXLEN; ++l) {
                    if((i==k)&&(j==l)) dist[i][j][k][l] = 0;
                    else if(((k==i-1)&&(j==l)) || ((k==i+1)&&(j==l)) || ((k==i)&&(l==j+1)) || ((k==i)&&(l==j-1))) dist[i][j][k][l] = getTime(Mountain[i][j], Mountain[k][l]);
                    else dist[i][j][k][l] = INF;
                }
            }
        }
    }
    // operation
    for(int a=0; a<MAXLEN; ++a) {
        for(int b=0; b<MAXLEN; ++b) {
            for(int i=0; i<MAXLEN; ++i) {
                for(int j=0; j<MAXLEN; ++j) {
                    for(int x=0; x<MAXLEN; ++x) {
                        for(int y=0; y<MAXLEN; ++y) {
                            dist[i][j][x][y] = min(dist[i][j][a][b] + dist[a][b][x][y], dist[i][j][x][y]);
                        }
                    }
                }
            }
        }
    }
}

int main(void) {
    
    cin >> N >> M >> T >> D;
    for(int i=0; i<N; ++i) {
        cin >> Mountain[i];
    }
    
    maxHeight = getHeight(Mountain[0][0]);
    floydWarshall();
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(dist[0][0][i][j] + dist[i][j][0][0] <= D) {
                int curHeight = getHeight(Mountain[i][j]);
                maxHeight = maxHeight < curHeight ? curHeight : maxHeight;
            }
        }
    }
    
    cout << maxHeight << endl;
    
    return 0;
}
