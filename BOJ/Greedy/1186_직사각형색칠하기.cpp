#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> loc;
typedef pair<loc, loc> rect;

int N, K;
rect rects[55];

int main(void){
    
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; ++i){
        scanf("%d %d %d %d", &(rects[i].first.first), &(rects[i].first.second), &(rects[i].second.first), &(rects[i].second.second));
    }
    
    
    
    
    return 0;
}
