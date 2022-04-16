#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <queue>
using namespace std;

typedef pair<string, int> node;

int N, colors[6];
queue<node> que;
set<string> dupcheck;

void s2n (string str, int *arr) {
    for(int i=0; i<str.size(); ++i) {
        if(str[i] == 'x') arr[i] = 10;
        else arr[i] = str[i] + 48;
    }
    return;
}

string n2s (int *arr) {
    string tmp = "";
    for(int i=0; i<N; ++i) {
        if(arr[i] == 0) tmp += '0';
        if(arr[i] == 10) tmp += 'x';
        else tmp += (arr[i]-48);
    }
    return tmp;
}

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &colors[i]);
    }
    
    // queue에 초기값 넣기
    for(int i=0; i<N; ++i) {
        colors[i] -= 1;
        que.push(make_pair(n2s(colors), i));
        colors[i] += 1;
    }
    
    while(!que.empty()) {
        
        node cur = que.front(); que.pop();
        
        if(dupcheck.find(cur.first) != dupcheck.end()) continue;
        else dupcheck.insert(cur.first);
        
        int arr[6];
        s2n(cur.first, arr);
        
        for(int i=0; i<N; ++i) {
            if(cur.second != i) {
                
            }
        }
        
    }
    
    return 0;
}
