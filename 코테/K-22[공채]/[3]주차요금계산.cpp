#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<string, string> inout;

vector<string> parse(const string &target, const char &del) {
    istringstream iss(target);
    vector<string> chunks;
    string chunk;
    while(getline(iss, chunk, del)) {
        chunks.push_back(chunk);
    }
    return chunks;
}

int toMinute(const string &str) {
    vector<string> timeSplit = parse(str, ':');
    return 60 * stoi(timeSplit[0]) + stoi(timeSplit[1]);
}

int getMinInterval(const string &start, const string &end) {
    int ST = toMinute(start), FT = toMinute(end);
    return FT - ST;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<inout> > cars;
    
    // 파싱 후 입력
    for(auto record : records) {
        vector<string> parsed = parse(record, ' ');
        if(parsed[2] == "IN") {
            if(cars.find(parsed[1]) == cars.end()) cars.insert({parsed[1], vector<inout>(1, {parsed[0], ""})});
            else cars[parsed[1]].push_back({parsed[0], ""});
        }
        else {
            cars[parsed[1]].back().second = parsed[0];
        }
    }
    
    // 비어 있는 시간 채우기
    for(auto iter = cars.begin(); iter != cars.end(); ++iter) {
        if(iter->second.back().second == "")
            iter->second.back().second = "23:59";
    }

    // 연산
    for(auto car : cars) {
        int time = 0;
        for(auto interval : car.second) {
            time += getMinInterval(interval.first, interval.second);
        }
        if(time <= fees[0]) answer.push_back(fees[1]);
        else answer.push_back(fees[1] + (int)ceil( (time - fees[0]) /(double)fees[2]) * fees[3]);
    }
    
    
    return answer;
}
