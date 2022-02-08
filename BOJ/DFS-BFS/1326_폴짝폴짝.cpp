// 배수만큼 떨어져있는 곳이란.. 씨바! : 앞으로만이 아니라, 뒤로도 배수만큼 떨어져 있을 수 있다는 것을 의미..
// 1 ~ N 사이를 모두 이동할 수 있게 설정해주어야 함 : 1 -> N -> b 같은 움직임도 허용될 수 있기 때문에..!

#include <iostream>
#include <queue>
#include <utility>
#define DEF 1000000
using namespace std;

typedef pair<int,int> turn;

int N, a, b, bridge[10005], trace[10005];

int BFS(){
    queue<turn> tmpQue;
    tmpQue.push({a, 0});
    for(int i=0; i<10005; ++i) trace[i] = DEF;
    while(!tmpQue.empty()){
        turn cur = tmpQue.front(); tmpQue.pop();
        if(trace[cur.first] > cur.second) trace[cur.first] = cur.second;
        else continue;
        int cnt = 1;
        while(cur.first + bridge[cur.first] * cnt <= N){
            if(trace[cur.first + bridge[cur.first] * cnt] > cur.second + 1)
                tmpQue.push({cur.first + bridge[cur.first] * cnt, cur.second + 1});
            cnt += 1;
        }
        cnt = 1;
        while(cur.first - bridge[cur.first] * cnt > 0){
            if(trace[cur.first - bridge[cur.first] * cnt] > cur.second + 1)
                tmpQue.push({cur.first - bridge[cur.first] * cnt, cur.second + 1});
            cnt += 1;
        }
    }
    if(trace[b] == DEF) return -1;
    else return trace[b];
}

int main(void){
    
    scanf("%d", &N);
    for(int i=1; i<=N; ++i)
        scanf("%d", &bridge[i]);
    scanf("%d %d", &a, &b);
    
    printf("%d\n", BFS());
    
    return 0;
}
