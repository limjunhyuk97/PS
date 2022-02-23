// BFS와 DP로 조합 최적화하기

// 1. 금민수 조합을 미리 생성해두기
// 2. 로직에서의 문제
//  - 어떤 수에 도달했을 때 수 조합이 더 적은 경우가 아니라면 갱신을 하지 않는다는 것인데, 동일 갯수의 수 조합일 때 앞서는 경우에 갱신이 일어나지 않아 문제 발생
//  - 수정한 내용 : BFS를 돌때 마다 trace를 배열에 기록하고, 특정 수에 이미 trace가 기록되어 있다면 다른 node에서 갱신을 하려는 시도는 수의 갯수가 많은 경우이므로 무시 가능

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N;
int path[1000005];
vector<int> minsu;

void generateMinsu(){
    vector<string> tmp[7];
    tmp[1].push_back("4"); tmp[1].push_back("7"); minsu.push_back(4); minsu.push_back(7);
    for(int i=2; i<7; ++i){
        for(int j=0; j<tmp[i-1].size(); ++j){
            tmp[i].push_back("4"+tmp[i-1][j]);
            tmp[i].push_back("7"+tmp[i-1][j]);
        }
        for(int j=0; j<tmp[i].size(); ++j) minsu.push_back(stoi(tmp[i][j]));
    }
    sort(minsu.begin(), minsu.end(), less<int>());
}

void printPath(int n){
    if(n == 0) return;
    printPath(path[n]);
    printf("%d ", n-path[n]);
}

int main(void){
    
    scanf("%d", &N);
    
    generateMinsu();
    
    fill(&path[0], &path[1000005], -1);
    
    // 왜 더해서 올라가는 것은 되는데 빼서 내려오는 것은 또 안되는거지..?
    // 아하... : 아래에서 더해서 올라가야 사전순으로 앞서는 것을 보장할 수 있다.. 아ㅏㅎ..
    // 사전순 앞서는 것 = 아래서 더해서 올라가기.
    // BFS의 단계 = 수의 갯수가 적은 것.
    queue<int> tmpQue; tmpQue.push(0);
    while(!tmpQue.empty()){
        int cur = tmpQue.front(); tmpQue.pop();
        for(int i=0; i<minsu.size(); ++i){
            int next = cur + minsu[i];
            if(next > N) continue;
            if(path[next] == -1){
                path[next] = cur;
                tmpQue.push(next);
            }
        }
    }
    
    if(path[N] == -1){
        printf("-1\n");
        return 0;
    }

    printPath(N);
    printf("\n");
    
    return 0;
}
