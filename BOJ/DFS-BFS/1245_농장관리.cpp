// 슈바 문제 잘못봄;;

// set을 사용하여 원래 추가한 녀석을 다시 추가하지 않는다.
// deque을 사용하여 BFS를 구현함

#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> loc;

int N, M, peak;
int numGrid[110][80];
bool boolGrid[110][80];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void peakcheck(int n, int m){
    set<loc> peakCandidate;
    deque<loc> tmpDeque;
    tmpDeque.push_back({n, m});
    while(!tmpDeque.empty()){
        loc tmp = tmpDeque.front(); tmpDeque.pop_front();
        peakCandidate.insert({tmp.first, tmp.second});
        boolGrid[tmp.first][tmp.second] = true;
        for(int i=0; i<8; ++i){
            int nextX=tmp.first+dx[i], nextY=tmp.second+dy[i];
            if(0>nextX || N<=nextX || 0>nextY || M<=nextY) continue;
            if(peakCandidate.find({nextX, nextY})!=peakCandidate.end()) continue;
            if(numGrid[nextX][nextY] == numGrid[tmp.first][tmp.second]){
                tmpDeque.push_back({nextX, nextY});
                boolGrid[nextX][nextY] = true;
            }
        }
    }
    int peakWeight = numGrid[(*peakCandidate.begin()).first][(*peakCandidate.begin()).second];
    bool result = true;
    for(auto iter=peakCandidate.begin(); iter != peakCandidate.end(); ++iter){
        for(int i=0; i<8; ++i){
            int perimeterX = (*iter).first+dx[i], perimeterY = (*iter).second+dy[i];
            if(0>perimeterX || N<=perimeterX || 0>perimeterY || M<=perimeterY || peakCandidate.find({perimeterX, perimeterY})!=peakCandidate.end()) continue;
            if(peakWeight>numGrid[perimeterX][perimeterY]) boolGrid[perimeterX][perimeterY] = true;
            else result = false;
        }
    }
    if(result && peakWeight!=0) peak += 1;
}

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf("%d", &numGrid[i][j]);
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(!boolGrid[i][j]) peakcheck(i, j);
        }
    }
    
    printf("%d\n", peak);
    
    return 0;
}
