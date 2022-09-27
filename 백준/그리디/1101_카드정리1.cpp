// 카드를 옮길 때 어떤 규칙성을 갖고 옮겨야 하는가?
// 2개 이상의 카드 종류로 이루어진 줄이 있다 -> 거기를 joker로 쓴다.
//    - joker로 쓰기로 한 줄 외에도 2개 이상의 수로 이루어진 줄이 있다 -> 옮겨야 한다.
//    - 다른 줄과 동일한 카드를 갖고 있는 1개 짜리 줄이 있다 -> 옮겨야 한다.
//    - 모든 줄이 다 다른 카드를 갖고 있다 -> 고려할 필요가 없다
// 2개 이상의 카드 종류로 이루어진 줄이 없다
//    - 다른 줄과 동일한 카드를 갖고 있는 1개짜리 줄이 있다
//        - 1개짜리 줄이 2개 이상의 카드 종류에 대해 존재한다 -> 그중 하나를 조커로 만든다. (N-1)
//        - 1개짜리 줄이 1개의 카드 종류에 대해서만 존재한다 -> 1 번 옮기면 됨
//    - 다른 줄과 동일한 카드를 갖고 있는 1개짜리 줄이 없다 -> 0

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M, dup_row, movement;
map<int, int> mono_row;

int main(void){

    scanf("%d %d", &N, &M);

    for(int i=0; i<N; ++i){
        int cnt = 0, rep = 0, tmp = 0;
        for(int j=0; j<M; ++j){
            scanf("%d", &tmp);
            if(tmp != 0){
                rep = j;
                ++cnt;
            }
        }
        if(cnt == 1) mono_row[rep] += 1;
        else if(cnt > 1) dup_row += 1;
    }
    
    if(dup_row!=0){
        movement += (dup_row - 1);
        for(auto iter = mono_row.begin(); iter != mono_row.end(); ++iter) movement += ((*iter).second - 1);
    }
    else{
        for(auto iter = mono_row.begin(); iter != mono_row.end(); ++iter) movement += ((*iter).second - 1);
        movement -= 1;
        // 카드가 아예 없는 경우;; -> movement 가 없어야 함
        if(movement == -1) movement = 0;
    }
    
    printf("%d\n", movement);
    
    return 0;
}
