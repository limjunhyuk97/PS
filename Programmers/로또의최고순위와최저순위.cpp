#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    bool arr[52];
    int first = 0, second = 0;
    int ordinal[7] = {6, 6, 5, 4, 3, 2, 1};
    
    for(int i=0; i<52; ++i) arr[i] = false;
    for(int i=0; i<win_nums.size(); ++i){
        arr[win_nums[i]] = true;
    }
    for(int i=0; i<lottos.size(); ++i){
        if(lottos[i] == 0){
            first += 1;
            continue;
        }
        if(arr[lottos[i]]){
            first += 1;
            second += 1;
            continue;
        }
    }
    
    answer.push_back(ordinal[first]);
    answer.push_back(ordinal[second]);
    
    return answer;
}
