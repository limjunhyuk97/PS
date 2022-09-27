// 가로 세로 반대로 봄;;

#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> loc;

int N, M, wForce, bForce;
char charField[110][110];
bool boolField[110][110];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void BFS(int n, int m, char team){
    deque<loc> tmpDeque;
    set<loc> mass;
    tmpDeque.push_back({n, m});
    while(!tmpDeque.empty()){
        loc curPos = tmpDeque.front();
        tmpDeque.pop_front();
        mass.insert(curPos);
        boolField[curPos.first][curPos.second] = true;
        for(int i=0; i<4; ++i){
            int nextX=curPos.first+dx[i], nextY=curPos.second+dy[i];
            if(nextX<0 || nextX>=M || nextY<0 || nextY>=N) continue;
            if(mass.find({nextX, nextY})!=mass.end()) continue;
            if(charField[nextX][nextY]==charField[curPos.first][curPos.second]) tmpDeque.push_back({nextX, nextY});
        }
    }
    int massSize = (int)mass.size();
    if(team=='W') wForce += massSize * massSize;
    else if(team=='B') bForce += massSize * massSize;
}

int main(void){

    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i){
        string str; cin >> str;
        for(int j=0; j<N; ++j){
            charField[i][j] = str[j];
        }
    }

    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            if(!boolField[i][j]) BFS(i, j, charField[i][j]);
        }
    }

    printf("%d %d\n", wForce, bForce);

    return 0;
}
