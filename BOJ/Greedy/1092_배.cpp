// 크기순으로 정렬한 다음에 하나씩 짐을 빼가면 된다.
// 뺴가는 것을 구현하는 과정에서 multiset을 사용한다.
// - multiset에서 erase 썼을 때 중복되는 원소가 있으면 두개 다 날라가므로, 포인터로 지정해서 지워줘야 한다.
// - 한번 회차가 돌아올 때 남김없이 지우기 위한 구현 과정에서 문제가 있었음.

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M, cnt;
vector<int> crane;
multiset<int, greater<int> > box;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        int tmp; scanf("%d", &tmp);
        crane.push_back(tmp);
    }
    
    scanf("%d", &M);
    for(int i=0; i<M; ++i){
        int tmp; scanf("%d", &tmp);
        box.insert(tmp);
    }
    
    sort(crane.begin(), crane.end(), greater<int>());
    
    if(crane[0] < *box.begin()){
        printf("-1\n");
        return 0;
    }
    
    while(!box.empty()){
        vector<int> target_arr; int sidx = 0;
        for(auto iter=box.begin(); iter != box.end(); ++iter){
            for(int idx = sidx; idx<N; ++idx){
                if(crane[idx] >= *iter){
                    target_arr.push_back(*iter);
                    ++sidx;
                    break;
                }
            }
        }
        cnt += 1;
        for(auto el : target_arr){
            auto target = box.find(el);
            box.erase(target);
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
