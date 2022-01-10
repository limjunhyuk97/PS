#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "", tmp = "";
    vector<pair<int, int> >  zero_point;
    int p1 = -1, p2 = 0;
    
    // step 1 + step2
    for(int i=0; i<new_id.size(); ++i){
        if('A'<=new_id[i] && new_id[i]<='Z') {
            tmp += new_id[i] + 32;
            continue;
        }
        if('a' <= new_id[i] && new_id[i] <= 'z'){
            tmp += new_id[i];
            continue;
        }
        if('1' <= new_id[i] && new_id[i] <= '9'){
            tmp += new_id[i];
            continue;
        }
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            tmp += new_id[i];
            continue;
        }
    }
    
    // step 3 : two pointer로 해결
    for(; p2<tmp.size(); ++p2){
        if(tmp[p2] == '.'){
            if(p1 == -1) p1 = p2;
        }
        else{
            if(p1 != p2 && p1 != -1){
                zero_point.push_back({p1, p2-1});
            }
            p1 = -1;
        }
    }
    
    if(p1 != 0){
        
    }
    
    // step 4
    if(!answer.empty() && answer[0] == '.') answer = answer.substr(1);
    if(!answer.empty() && answer[answer.size()-1] == '.') answer = answer.substr(0, answer.size() - 1);
    
    // step 5
    if(answer.empty()) answer += 'a';
    
    // step 6
    if(answer.size() >= 16){
        answer = answer.substr(0, 15);
        if(*(answer.end()-1)) answer = answer.substr(0, 14);
    }
    
    // step 7
    if(answer.size() <= 2){
        while(answer.size() < 3){
            answer += *(answer.end() - 1);
        }
    }
        
    return answer;
}

int main(void){
    
    cout << solution("...!@BaT#*..y.abcdefghijklm");
    
    return 0;
}
