// BFS와 DP로 조합 최적화하기

// 1. N에서 빼가면서 DFS를 수행하였다. 모든 가능한 경우의 수를 다 고려하려 시도함 -> 실패
// 2. 1에서, 단계마다 가능함 금민수 조합을 만들어가면서 진행했더니 너무 느렸음 -> 금민수 조합을 미리 만들어두고 N에서 제하면서 DFS 수행 -> 실패
// 3.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#define INF 2000000000
using namespace std;

typedef pair< vector<int>, int> node;

int N, DP[1000005];
string SN;
vector<int> minsu[8], ans;

// n자리 금민수 생성
void generateNumber(int n){
    string common="";
    for(int i=0; i<n-1; ++i) common += "0";
    int add7=stoi("7"+common), add4=stoi("4"+common);
    for(int i=0; i<(int)minsu[n-1].size(); ++i) minsu[n].push_back(add7+minsu[n-1][i]);
    for(int i=0; i<(int)minsu[n-1].size(); ++i) minsu[n].push_back(add4+minsu[n-1][i]);
}

// 자릿수 찾기
int getNumberLength(int n){
    int cnt=1;
    while(n/10!=0){
        n /= 10;
        cnt += 1;
    }
    return cnt;
}

// DP[0]에서의 비교
void refreshAnswer(vector<int>& possible){
//    if(!ans.empty()){
//        for(int i=0; i<(int)ans.size(); ++i)
//            printf("%d ", ans[i]);
//        printf("\n");
//    }
    sort(possible.begin(), possible.end());
//    for(int i=0; i<(int)possible.size(); ++i)
//        printf("%d ", possible[i]);
//    printf("\n\n");
    if(ans.empty()) ans=possible;
    else{
        if(ans.size() > possible.size()) ans=possible;
        else{
            for(int i=0; i<ans.size(); ++i){
                if(ans[i]==possible[i]) continue;
                else if(ans[i]>possible[i]){
                    ans=possible;
                    break;
                }
                else break;
            }
        }
    }
}

// DP 갱신 함수
void refreshDP(queue<node>&tmpQue, node& cur, int numLen){
    for(int i=0; i<(int)minsu[numLen].size(); ++i){
        cur.first.push_back(minsu[numLen][i]);
        if(cur.second==minsu[numLen][i] && DP[cur.second-minsu[numLen][i]]==DP[cur.second]+1){
            refreshAnswer(cur.first); continue;
        }
        if(cur.second>=minsu[numLen][i] && DP[cur.second-minsu[numLen][i]] > DP[cur.second]+1){
            tmpQue.push( {cur.first, cur.second-minsu[numLen][i]} );
            DP[cur.second-minsu[numLen][i]]=DP[cur.second]+1;
        }
        cur.first.pop_back();
    }
}

// DP + BFS (BFS with Pruning)
void BFS(){
    queue<node> tmpQue;
    int numLen=(int)SN.size();
    // 동일 자릿수에 대해 연산 가능한 경우
    if(N >= minsu[numLen].back()){
        for(int i=0; i<(int)minsu[numLen].size(); ++i){
            if(N-minsu[numLen][i]>=0){
                vector<int> tmp; tmp.push_back(minsu[numLen][i]);
                tmpQue.push( {tmp, N-minsu[numLen][i]} );
                DP[N-minsu[numLen][i]] = 1;
            }
        }
    }
    else{
        for(int i=0; i<(int)minsu[numLen-1].size(); ++i){
            vector<int> tmp; tmp.push_back(minsu[numLen-1][i]);
            tmpQue.push( {tmp, N-minsu[numLen-1][i]} );
            DP[N-minsu[numLen-1][i]] = 1;
        }
    }
    if(DP[0]==1) {
        ans.push_back(N);
        return;
    }
    while(!tmpQue.empty()){
        node cur=tmpQue.front(); tmpQue.pop();
        numLen=getNumberLength(cur.second);
        // DP[0]에 대한 결과일 경우..?
        if(cur.second==0) refreshAnswer(cur.first);
        // 동일 자릿수에 대해 연산 가능한 경우
        if(cur.second>=minsu[numLen].back()) refreshDP(tmpQue, cur, numLen);
        else refreshDP(tmpQue, cur, numLen-1);
    }
}

int main(void){
    
    cin >> SN;
    N = stoi(SN);
    
    // 금민수 생성
    minsu[1].push_back(7); minsu[1].push_back(4);
    for(int i=2; i<8; ++i) generateNumber(i);
    
    // DP 배열 -1 로 초기화
    for(int i=0; i<1000005; ++i) DP[i]=INF;
    
    // DP + BFS를 진행한다.
    BFS();
    
    // 0번째 DP 출력
    if(DP[0]==INF) printf("-1\n");
    else{
        for(int i=0; i<(int)ans.size(); ++i)
            printf("%d ", ans[i]);
        printf("\n");
    }
    
    return 0;
}
