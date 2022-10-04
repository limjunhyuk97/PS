#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<string> parsedString(const string & target, const string &del) {
    vector<string> result;
    int curpos = 0;
    int pos = 0;
    while((pos = target.find(del, curpos)) != string::npos) {
        int len = pos - curpos;
        result.push_back(target.substr(curpos, len));
        curpos = pos + del.size();
    }
    result.push_back(target.substr(curpos));
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    // vector 초기화는 변수명(갯수, 0) 으로 한다.
    vector<int> answer(id_list.size(), 0);
    
    map <string, map<string, int> > reporterAsValue;  // {신고당함, {신고함, 횟수}}
    
    // 문자열 파싱 후 넣기
    for(int i=0; i<report.size(); ++i) {
        vector<string> result = parsedString(report[i], " ");
        reporterAsValue[result[1]].insert({result[0], 1});
    }
    
    // 만약 신고당한 놈이 k 이상 신고 당했다면 : 신고한 놈들에게 알려줘야 하는 정보값 +1을 시킨다.
    for(auto iter : reporterAsValue) {
        if(iter.second.size() >= k)
            for(auto inner : iter.second)
                answer[find(id_list.begin(), id_list.end(), inner.first) - id_list.begin()] += 1;
    }
    
    return answer;
}

// 1. 문서화하여 정리하기 (노션)
//  - 어떤 자료구조를 사용하기를 기대하는가? : 해쉬맵-map
//  - 어떤 알고리즘을 사용하는가? : 구현
// 2. 관련 CPP STL 복습하고 정리해두기
//  - unique 라는 STL 함수 (vector에서 중복된 원소들 제거. 대신 정렬이 선행되어야 함. erase와 같이 바로 사용할 수 있음)
//  - find 라는 STL 함수 (값을 통해 인덱스를 찾을 수 있게 해준다.)
//  - map, 파싱에 대해서는 정리 완료
