#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAXLEN 105
#define INF 2000000000
using namespace std;

string target;
int N;
vector<string> words = vector<string>(MAXLEN);

int DP[MAXLEN];

int isWordAvailable(const string &word, const string &chunk) {
    
    // 길이 비교
    if(word.size() != chunk.size()) return -1;
    
    // 알파벳 갯수 일치 비교
    int alphas[30];
    fill(&alphas[0], &alphas[30], 0);
    
    for(int i=0; i<word.size(); ++i){
        alphas[word[i]-'a'] += 1;
    }
    
    for(int i=0; i<chunk.size(); ++i) {
        if(alphas[chunk[i]-'a'] == 0) return -1;
        alphas[chunk[i]-'a'] -= 1;
    }
    
    // 몇개를 최소로 바꿔야 하는지 찾기
    int changes = 0;
    for(int i=0; i<word.size(); ++i) {
        if(word[i] != chunk[i]) changes += 1;
    }
    return changes;
}

int main(void) {
    
    // 입력값 받기
    cin >> target;
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> words[i];
    }
    
    // DP 초기화
    fill(&DP[0], &DP[MAXLEN], INF);
    DP[0] = 0;
    
    // DP값 갱신하며 구하기
    for(int i=0; i<target.size(); ++i) {
        for(auto word : words) {
            if(i-1+word.size() >= target.size()) continue;
            int changes = isWordAvailable(word, target.substr(i, word.size()));
            if(changes >=0) {
                DP[i+word.size()] = min(DP[i] + changes, DP[i+word.size()]);
            }
        }
    }
    
    cout << (DP[target.size()] == INF ? -1 : DP[target.size()]) << endl;
    
    return 0;
}
