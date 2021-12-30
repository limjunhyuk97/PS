// 놓치고 있는 조건이 있었다. (아무도 3시 이후에 제출을 안한 경우..!)
// 배열 sorting: (arr, arr+n) (&arr[0], $arr[n]) : 0 부터 n-1 까지 sorting 하는 것..

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

struct sol_logs{
    string time;
    int id;
    int problem;
    int subcount;
    int minute;
    
    bool operator<(const sol_logs & other) const{
        return problem < other.problem;
    }
};

struct participants{
    int id;
    int solcount;
    int penalty;
    int before_rank;
};

int time_to_min(string const &time_val){
    int sum = 0;
    sum += ((time_val[0] - 48) * 10 + (time_val[1] - 48)) * 60;
    sum += (time_val[3] - 48) * 10 + (time_val[4] - 48);
    return sum;
}

int N, M, overwhelmed[55];
vector<sol_logs> logs;
deque<sol_logs> log_for_participants[55];
participants participant[55];

bool compare(const participants &p1, const participants &p2){
    if(p1.solcount != p2.solcount) return p1.solcount > p2.solcount;
    else return p1.penalty < p2.penalty;
}

bool compare2(const pair<int, int> p1, const pair<int, int> p2){
    return p1.second < p2.second;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<M; ++i){
        string t; int id, p, s;
        cin >> t >> id >> p >> s;
        logs.push_back({t, id, p, s, time_to_min(t)});
    }
    
    for(int i=0; i<=N; ++i){
        participant[i].id = i;
    }
    
    // 03:00 까지의 순위 결정
    int cnt = 0;
    for(int i=0; i<M; ++i){
        if(logs[i].minute > 180){
            cnt = i;
            break;
        }
        participant[logs[i].id].solcount += 1;
        participant[logs[i].id].penalty += logs[i].minute + (logs[i].subcount - 1) * 20;
    }
    
    sort(&participant[1], &participant[N + 1], compare);
    for(int i=1; i <= N; ++i) participant[i].before_rank = i;
    for(int i=cnt; i<M; ++i){
        log_for_participants[logs[i].id].push_back(logs[i]);
    }
    for(int i=1; i<= N; ++i){
        sort(log_for_participants[i].begin(), log_for_participants[i].end());
    }
    
    // 역전 계산
    cnt = N;
    while(cnt != 1){
        int cur_id = participant[cnt].id;
        if(log_for_participants[cur_id].empty()) cnt -= 1;
        else{
            sol_logs tmp = log_for_participants[cur_id].front();
            log_for_participants[cur_id].pop_front();
            
            participant[cnt].solcount += 1;
            participant[cnt].penalty += tmp.minute + (tmp.subcount - 1) * 20;
                 
            
            sort(&participant[1], &participant[N + 1], compare);
            
            for(int j=1; j<=N; ++j){
                if(participant[j].id == cur_id){
                    overwhelmed[cur_id] += (participant[j].before_rank - j);
                }
            }
            
            for(int j=1; j<=N; ++j){
                participant[j].before_rank = j;
            }
        }
    }
    
    int max_point = -1;
    vector<pair<int, int> > candidate;
    for(int i=1; i<=N; ++i){
        if(overwhelmed[i] > max_point)
            max_point = overwhelmed[i];
    }
    for(int i=1; i<=N; ++i){
        if(overwhelmed[i] == max_point)
            candidate.push_back({i, 0});
    }
    for(int i=0; i<candidate.size(); ++i){
        for(int j=1; j<=N; ++j){
            if(candidate[i].first == participant[j].id){
                candidate[i].second = participant[j].before_rank;
                break;
            }
        }
    }
    
    sort(candidate.begin(), candidate.end(), compare2);
    
    cout << candidate[0].first << endl;
    
    return 0;
}
