#include <iostream>
#include <queue>
using namespace std;

// 다시는 안가게 체크!
bool checked[100005];

int main(void) {
    
    int N, K;
    
    cin >> N >> K;
    
    queue<int> subin;
    subin.push(N); checked[N] = true;
    
    int cnt = 0;
    while(!subin.empty()) {
        int size = (int)subin.size();
        for(int i=0; i<size; ++i) {
            int pos = subin.front(); subin.pop();
            if(pos == K) {
                cout << cnt << endl;
                return 0;
            }
            if(pos+1 < 100005 && !checked[pos+1]){
                subin.push(pos + 1); checked[pos + 1] = true;
            }
            // 범위 고려.
            if(pos-1 < 100005 && -1 < pos-1 && !checked[pos-1]){
                subin.push(pos - 1); checked[pos - 1] = true;
            }
            if(2*pos < 100005 && !checked[2*pos]){
                subin.push(2*pos); checked[2*pos] = true;
            }
        }
        cnt += 1;
    }
    
    return 0;
}
