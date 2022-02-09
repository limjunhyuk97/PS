// set을 이용해서 지금 보고있는 string이 이전에 본적이 있는 string인지 아닌지를 판별할 수 있다.

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <utility>
using namespace std;

typedef pair<string, int> node;

int N, K, ans=-1;
string str;

// n 자리부터 뒤집기를 시작한다.
string reverseString(int n, string cur){
    int gap=(int)(K/2);
    for(int i=0; i<gap; ++i) swap(cur[n+i], cur[n+K-1-i]);
    return cur;
}

bool checkString(string cur){
    for(int i=0; i<N; ++i){
        if(cur[i]-'0' != i+1)
            return false;
    }
    return true;
}

void BFS(){
    queue<node> tmpQue;
    set<string> checked;
    tmpQue.push({str, 0});
    while(!tmpQue.empty()){
        node cur = tmpQue.front(); tmpQue.pop();
        if(checkString(cur.first)){
            if(ans == -1) ans = cur.second;
            else ans = (ans > cur.second ? cur.second : ans);
        }
        if(checked.find(cur.first)==checked.end()) checked.insert(cur.first);
        else continue;
        for(int i=0; i<=N-K; ++i){
            tmpQue.push({reverseString(i, cur.first), cur.second+1});
        }
    }
}

int main(void){
    
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; ++i){
        int tmp; scanf("%d", &tmp);
        str += (char)(tmp+'0');
    }
    
    BFS();
    printf("%d\n", ans);
    
    return 0;
}
