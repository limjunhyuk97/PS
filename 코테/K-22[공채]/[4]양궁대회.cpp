#include <string>
#include <vector>
using namespace std;

int shotResult[11];
int shotCount[11];
int maxGap = 0;

void setShots(int left) {
    for(int i=0; i<11; ++i) shotResult[i] = 0;
    for(int i=0; i<11; ++i) {
        shotResult[i] = shotCount[i];
    }
    if(left != 0) shotResult[10] += left;
}

bool checkShots() {
    for(int i=10; i>=0; --i) {
        if(shotCount[i] == shotResult[i]) continue;
        if(shotCount[i] > shotResult[i]) return true;
        else return false;
    }
}

int getGap(vector<int> & info, int &A) {
    int sum=0;
    for(int i=0; i<info.size(); ++i) {
        if(info[i] < shotCount[i]){
            if(info[i] == 0) sum += 10 - i;
            else sum += 2*(10-i);
        }
    }
    return sum - A;
}

void DFS(int cur, vector<int> &info, int left, int &A) {
    // 마지막까지 순회하여 다 봤다면
    if(cur == 10){
        int gap = getGap(info, A);
        if(gap > maxGap || (gap ==maxGap && checkShots())) {
            maxGap = gap;
            setShots(left);
        }
        return;
    }
    // 남은 화살수가 0이라면
    if(left == 0) {
        int gap = getGap(info, A);
        if(gap > maxGap || (gap ==maxGap && checkShots())) {
            maxGap = gap;
            setShots(left);
        }
        return;
    }
    
    // 선택
    if(left >= info[cur]+1) {
        shotCount[cur] = info[cur]+1;
        DFS(cur+1, info, left - info[cur]-1, A);
        shotCount[cur] = 0;
    }
    // 안선택
    DFS(cur+1, info, left, A);
    return;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(1, -1);
    int A = 0;
    for(int i=0; i<info.size(); ++i)
        if(info[i] > 0) A += 10-i;
    
    DFS(0, info, n, A);
    if(maxGap > 0) {
        answer.resize(11);
        for(int i=0; i<11; ++i) {
            answer[i] = shotResult[i];
        }
    }
    
    return answer;
}
