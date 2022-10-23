// 강의실 배정(BOJ)과 매우 유사
// (1) 각 시간격의 시작 시간 기준 정렬
// (2) 각 시간격의 종료 시간 기준 정렬
// (3) 종료 시간 기준에서 하나씩 추출 -> 1초의 시간격으로 바라볼때 시작 시간 기준으로 얼마나 포함할 수 있는지 세기

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 문자열 파싱
vector<string> parsed(const string &target, const string &del) {
    vector<string> result;
    int cur = 0 , next = 0;
    while((next = (int)target.find(del, cur)) != (int)string::npos) {
        int len = next - cur;
        result.push_back(target.substr(cur, len));
        cur = next + (int)del.size();
    }
    result.push_back(target.substr(cur));
    return result;
}

// [Q형식]hh:mm:ss:sss -> 밀리초
int stringToTotal(const string &str) {
    vector<string> parsed_str = parsed(str, ":");
    return stoi(parsed_str[0])*60*60*1000 + stoi(parsed_str[1])*60*1000 + stoi(parsed_str[2])*1000 + stoi(parsed_str[3]);
}

// 밀리초 -> [Q형식]hh:mm:ss:sss
string totalToString(int total) {
    int h = total / (60*60*1000);
    string sh = to_string(h);
    total %= 60*60*1000;
    int m = total / (60*1000);
    string sm = to_string(m);
    total %= 60*1000;
    int s = total / 1000;
    string ss = to_string(s);
    total %= 1000;
    int ms = total;
    string sms = to_string(ms);
    return sh+":"+sm+":"+ss+":"+sms;
}

string StoQ(const string &S, const string &T) {
    // STime : [시, 분, 초, 밀리초]
    vector<string> STime = parsed(S, ":");
    
    // TTime : [초] 또는 [초, 밀리초]
    vector<string> TTime = parsed(T, ".");
    
    // totalSTime : 밀리초 변환 , totalTTime : 밀리초 변환 -> totalQTime : 시작 시간의 총 밀리초
    int totalSTime = stoi(STime[0])*60*60*1000 + stoi(STime[1])*60*1000 + stoi(STime[2])*1000 + stoi(STime[3]);
    int totalTTime = TTime.size() > 1 ? stoi(TTime[0]) * 1000 + stoi(TTime[1]) : stoi(TTime[0]) * 1000;
    int totalQTime = totalSTime - totalTTime + 1;
    
    // totalQTime을 시간으로 변환 : 이때 시작 시간이 2016-09-14에서 된 것일 수도 있겠다.
    return totalQTime <= 0 ? "00:00:00:000" : totalToString(totalQTime);
}

pair<string, string> StoRecentPair(const string & S) {
    int totalS = stringToTotal(S);
    return {totalToString(totalS), totalToString(totalS + 999)};
}

// 2016-09-15 빼고 시간만 입력
// Q: 요청 시간, T: 응답 시간
struct Traffic {
    string Q;
    string S;
    string T;
};
// 출력 확인용
ostream& operator<<(ostream &ostm, const Traffic &t) {
    ostm << t.Q << " " << t.S << " " << t.T;
    return ostm;
}
// S 오름차순 정렬
bool SAscending(const Traffic & t1, const Traffic & t2) {
    int curTotal = stringToTotal(t1.S);
    int otherTotal = stringToTotal(t2.S);
    return curTotal < otherTotal;
}
// Q 오름차순 정렬
bool QAscending(const Traffic & t1, const Traffic & t2) {
    int curTotal = stringToTotal(t1.Q);
    int otherTotal = stringToTotal(t2.Q);
    return curTotal < otherTotal;
}

Traffic trafficSortedByS[2005];
Traffic trafficSortedByQ[2005];

int solution(vector<string> lines) {
    int answer = 0;
    
    int N = (int)lines.size();
    for(int i=0; i<N; ++i) {
        vector<string> SST = parsed(lines[i], " ");
        // S 쪼개기
        SST[1] = SST[1].replace(8, 1, ":");
        // T에서 s떼기
        SST[2] = SST[2].substr(0, SST[2].size()-1);
        trafficSortedByS[i] = {StoQ(SST[1], SST[2]), SST[1], SST[2]};
        trafficSortedByQ[i] = {StoQ(SST[1], SST[2]), SST[1], SST[2]};
    }
    
    sort(&trafficSortedByS[0], &trafficSortedByS[N], SAscending);
    sort(&trafficSortedByQ[0], &trafficSortedByQ[N], QAscending);
    
    int i=0, j=0, cnt = 0;
    for(i=0; i<N; i++) {
        pair<string, string> pairs = StoRecentPair(trafficSortedByS[i].S);
        for(j=i+1; j<N; ++j) {
            if(stringToTotal(trafficSortedByQ[j].Q) > stringToTotal(pairs.second)) {
                answer = answer > j-i ? answer : j-i;
                cout << cnt++ << " ";
                cout << trafficSortedByS[i].S << endl;
                cout << trafficSortedByQ[j].S << endl;
                break;
            }
        }
        if(j == N) {
            answer = answer > j-i ? answer : j-i;
        }
    }
    
    return answer;
}
int main(void) {
    
    vector<string> input;
    input.push_back("2016-09-15 01:00:04.002 2.0s");
    input.push_back("2016-09-15 01:00:07.000 2s");
    
    cout << solution(input) << endl;
}
