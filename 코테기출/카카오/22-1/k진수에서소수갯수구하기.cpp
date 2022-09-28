#include <string>
#include <vector>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string changeNum(int num, int k){
    string converted = "";
    
    for(int i = num; i > 0; ){
        converted = to_string(i % k) + converted;
        i /= k;
    }
    return converted;
}

int isPrime(const string &str) {
    long long int dec = stol(str);
    if(dec == 1) return 0;
    for(long long int i =2 ; i* i<dec+1; ++i) {
        if(dec % i == 0) return 0;
    }
    return 1;
}

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
