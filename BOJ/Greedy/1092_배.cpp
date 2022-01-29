#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, cnt, check_cnt;
vector<int> Crane;
deque<int> Box;
bool checked[10005];

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        int tmp; scanf("%d", &tmp);
        Crane.push_back(tmp);
    }
    
    scanf("%d", &M);
    for(int i=0; i<M; ++i){
        int tmp; scanf("%d", &tmp);
        Box.push_back(tmp);
    }
    
    sort(Crane.begin(), Crane.end(), greater<int>());
    sort(Box.begin(), Box.end(), greater<int>());
    
    if(Box.front() > Crane.front()){
        printf("-1\n");
        return 0;
    }
    
    while(check_cnt != M){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(checked[j]) continue;
                if(Crane[i] >= Box[j]){
                    checked[j] = true;
                    ++check_cnt;
                    break;
                }
            }
        }
        ++cnt;
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
