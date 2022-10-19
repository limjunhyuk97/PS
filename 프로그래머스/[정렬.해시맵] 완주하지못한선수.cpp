// [A1] sorting 사용
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i=0; i<completion.size(); ++i) {
        if(participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    
    if(answer == "") answer = participant.back();
    
    return answer;
}


// [A2] map 사용
#include <string>
#include <map>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> p;
    for(auto iter : participant) {
        if(p.find(iter) != p.end()) p[iter] += 1;
        else p[iter] = 1;
    }
    
    for(auto iter : completion) {
        p[iter] -= 1;
    }
    
    for(auto iter : p) {
        if(iter.second == 1) {
            answer = iter.first;
            break;
        }
    }
    
    return answer;
}


/*

[Q] 어떻게 completion에 없는 participant를 골라내 줄 것인가?

[A1] sorting 사용 = O(NlogN) 내로 연산 끝낼 수 있다.
그냥 string을 정렬한 뒤에
차이가 나는 부분에서 출력해주면 됨.

[A2] map 사용 = O(NlogN) 내로 연산 끝낼 수 있다.
map에 더 많은 요소 포함하는 배열 내 데이터들 저장한다. 이때 {요소, 요소의 수} 형태로 저장. 이러면 2번 이상 등장하면 요소의 수 >=2
더 적은 요소를 포함하는 배열을 순회하면서 map에 접근하여 {요소, 요소의 수}에서 (요소의 수-1)을 수행한다.
{요소, 요소의 수}에서 요소의 수가 1인 놈 출력하면 된다.
*/
