#include <string>
#include <vector>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// num의 10진법 수를 k진법으로 변환한다.
string changeNumSys(int num, int k) {
    string converted;  // 변환된 수를 저장한다.
    while(num) {
        converted = to_string(num % k) + converted;  // k로 나눈 나머지를 계속 앞에다 추가한다.
        num /= k;
    }
    return converted;
}

// 소수 판별 함수
int isPrime(const string &str) {
    long long int dec = stol(str);
    if(dec == 1) return 0;
    for(long long int i =2 ; i* i<dec+1; ++i) {
        if(dec % i == 0) return 0;
    }
    return 1;
}

// 문자열 파싱 (중간에 들어있는 '0' 제외하고 문자열 뜯어냄)
vector<string> parse(const string &target, const string &del) {
    vector<string> result;
    int cur_pos = 0;
    int pos = 0;
    while((pos = (int)target.find(del, cur_pos)) != (int)string::npos) {
        int len = pos - cur_pos;
        result.push_back(target.substr(cur_pos, len));
        cur_pos = pos;
        for(; cur_pos<target.size(); ++cur_pos) {
            if(target[cur_pos] != '0') break;
        }
    }
    if(cur_pos < target.size()) result.push_back(target.substr(cur_pos));
    return result;
}

int solution(int n, int k) {
    int answer = 0;
    
    string str = changeNum(n, k);
    vector<string> parsed;
    
    parsed = parse(str, "0");
    
    for (auto iter : parsed) {
        answer += isPrime(iter);
    }
    return answer;
}
