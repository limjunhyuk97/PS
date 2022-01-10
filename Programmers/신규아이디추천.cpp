#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // step 1 + step2 + step3
    for(int i=0; i<new_id.size(); ++i){
        if('A'<=new_id[i] && new_id[i]<='Z') {
            answer += new_id[i] + 32;
            continue;
        }
        if('a' <= new_id[i] && new_id[i] <= 'z'){
            answer += new_id[i];
            continue;
        }
        if('0' <= new_id[i] && new_id[i] <= '9'){
            answer += new_id[i];
            continue;
        }
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            if(i != 0 && *(answer.end()-1) == '.' && new_id[i] == '.') continue;
            answer += new_id[i];
            continue;
        }
    }
    
    // step 4
    if(answer[0] == '.') answer = answer.substr(1);
    if(*(answer.end()-1) == '.') answer = answer.substr(0, answer.size() - 1);
    
    // step 5
    if(answer=="") answer += 'a';
    
    // step 6
    if(answer.size() >= 16){
        answer = answer.substr(0, 15);
        if(*(answer.end()-1) == '.') answer = answer.substr(0, 14);
    }
    
    // step 7
    if(answer.size() <= 2){
        while(answer.size() < 3){
            answer += *(answer.end() - 1);
        }
    }
        
    return answer;
}
