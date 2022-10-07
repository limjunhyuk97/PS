#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <map>

using namespace std;

typedef pair<int, int> coord;

int distance(const coord &thumb, const coord &target) {
    return abs(thumb.first - target.first) + abs(thumb.second - target.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // 숫자들에 대한 위치 정보 저장
    map<int, coord> num_loc;
    num_loc.insert({1, {1, 1}});
    num_loc.insert({2, {1, 2}});
    num_loc.insert({3, {1, 3}});
    num_loc.insert({4, {2, 1}});
    num_loc.insert({5, {2, 2}});
    num_loc.insert({6, {2, 3}});
    num_loc.insert({7, {3, 1}});
    num_loc.insert({8, {3, 2}});
    num_loc.insert({9, {3, 3}});
    num_loc.insert({0, {4, 2}});
    
    // 왼손, 오른손으로부터의 거리
    coord left_thumb = make_pair(4, 1);
    coord right_thumb = make_pair(4, 3);
    
    for(auto cur_num : numbers) {
        if(cur_num == 1 || cur_num == 4 || cur_num == 7) {
            left_thumb = num_loc[cur_num];
            answer += "L";
        }
        else if(cur_num == 3 || cur_num == 6 || cur_num == 9) {
            right_thumb = num_loc[cur_num];
            answer += "R";
        }
        else {
            int left_thumb_distance = distance(left_thumb, num_loc[cur_num]);
            int right_thumb_distance = distance(right_thumb, num_loc[cur_num]);
            if(left_thumb_distance == right_thumb_distance) {
                answer += (hand == "left" ? "L" : "R");
                if(hand == "left") left_thumb = num_loc[cur_num];
                else right_thumb = num_loc[cur_num];
            }
            else if(left_thumb_distance > right_thumb_distance) {
                answer += "R";
                right_thumb = num_loc[cur_num];
            }
            else {
                answer += "L";
                left_thumb = num_loc[cur_num];
            }
        }
    }
    
    return answer;
}
