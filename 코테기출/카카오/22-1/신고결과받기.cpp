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
    vector<int> answer(id_list.size(), 0);
    
    map <string, map<string, int> > reporterAsValue;  // {신고당함, {신고함, 횟수}}
    
    for(int i=0; i<report.size(); ++i) {
        vector<string> result = parsedString(report[i], " ");
        reporterAsValue[result[1]].insert({result[0], 1});
    }
    
    for(auto iter : reporterAsValue) {
        if(iter.second.size() >= k)
            for(auto inner : iter.second)
                answer[find(id_list.begin(), id_list.end(), inner.first) - id_list.begin()] += 1;
    }
    
    return answer;
}
