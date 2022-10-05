#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
typedef pair<int, int> coord;

bool promising(const vector<coord> &cur) {
    if(!cur.size()) return true;
    for(int i=0; i<cur.size(); ++i) {
        for(int j=i+1; j<cur.size(); ++j) {
            if(cur[i].first == cur[j].first || cur[i].second == cur[j].second) return false;
            if(abs(cur[i].first - cur[j].first) == abs(cur[i].second - cur[j].second)) return false;
        }
    }
    return true;
}

void DFS(vector<coord> &nodes, int *answer, int &len) {
    if(promising(nodes)) {
        if(nodes.size() == len) {
            *answer += 1;
            return;
        }
        int last = nodes.empty() ? -1 : nodes.back().first;
        for(int i=0; i<len; ++i){
            nodes.push_back({last+1, i});
            DFS(nodes, answer, len);
            nodes.pop_back();
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    vector<coord> queens;
    DFS(queens, &answer, n);
    
    return answer;
}
