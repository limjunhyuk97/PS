// 4

// priority_queue 기본 자료형 비교자로는 greater<>, less<> : function template가 필요한 것
// sort 기본 자료형 비교자로는 greater<>(), less<>() : template function이 필요한 것

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, T;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while(T--){
        
        cin >> N >> M;
        priority_queue<int, vector<int>, greater<>> SJ, SB;
        
        for(int i=0; i<N; ++i){
            int tmp; cin >> tmp;
            SJ.push(tmp);
        }
        for(int i=0; i<M; ++i){
            int tmp; cin >> tmp;
            SB.push(tmp);
        }
        
        for(int i=0; i<N+M-1; ++i){
            if(SJ.empty()){
                SB.pop(); continue;
            }
            else if(SB.empty()){
                SJ.pop(); continue;
            }
            
            if(SJ.top() == SB.top()){
                SB.pop();
            }
            else if(SJ.top() > SB.top()){
                SB.pop();
            }
            else{
                SJ.pop();
            }
        }
        
        if(SJ.empty()) cout << "B\n";
        else cout << "S\n";
        
    }
    
    return 0;
}
