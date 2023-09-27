#include <iostream>
#include <vector>
#include <set>
using namespace std;

set <string> availables;
set <string> visited;

bool isAvailable(const string target, int aCount) {
    
    int tmpACount = aCount;
    
    if(target.size() == 1) {
        if(target == "a") return true;
        else return false;
    }
    
    // 이미 방문된 적이 있음
    if(visited.find(target) != visited.end()) {
        // availables에 존재한다면 만들어질 수 있는 것임. 이때 True 반환
        return availables.find(target) != availables.end();
    }
    
    vector<pair<string, int> > candidates;
    
    // 앞 뒤에 a가 붙는 경우
    if(target[0] == 'a') candidates.push_back({ target.substr(1), aCount - 1});
    if(target[target.size()-1] == 'a') candidates.push_back({ target.substr(0, target.size()-1), aCount - 1});
    
    // b를 a의 갯수만큼 붙히는 경우 (1)
    int bIdx = 0;
    int bCount = 0;

    while(bIdx < target.size() && bCount < aCount) {
        if(target[bIdx] == 'b') ++bCount;
        else break;
        ++bIdx;
    }
    
    if(bCount == aCount) candidates.push_back({ target.substr(bIdx), aCount });
    
    // b를 a의 갯수만큼 붙히는 경우 (2)
    bIdx = (int)target.size() - 1;
    bCount = 0;
    
    while(bIdx >= 0 && bCount < aCount) {
        if(target[bIdx] == 'b') ++bCount;
        else break;
        --bIdx;
    }
    
    if(bCount == aCount) candidates.push_back({ target.substr(0, target.size() - bCount), aCount });
    
    for(auto candidate : candidates) {
        if(isAvailable(candidate.first, candidate.second)) {
            visited.insert(target);
            availables.insert(target);
            return true;
        }
    }
    
    visited.insert(target);
    return false;
}

int main(void) {
    vector<string> strings;
    strings.push_back("abab");
    strings.push_back("bbaa");
    strings.push_back("bababa");
    strings.push_back("bbbabababbbaa");
    
    for(auto str : strings) {
        int aCount = 0;
        for(int i=0; i<str.size(); ++i) {
            if(str[i] == 'a') aCount += 1;
        }
        cout << isAvailable(str, aCount) << endl;
    }
}
