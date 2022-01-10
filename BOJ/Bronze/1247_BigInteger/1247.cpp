#include <iostream>
#include <deque>
#define MAXNUM 9223372036854775807
#define MINNUM -9223372036854775807
using namespace std;

typedef long long int ll;
deque<ll> arr;
int N, p, m;

int main(void){
    
    for(int i = 0; i<3; ++i){
        
        cin >> N;
        p = 0; m = 0;
        arr.clear();
        arr.push_back(0); arr.push_back(0); arr.push_back(0);
    
        for(int j=0; j<N; ++j){
            ll input;
            cin >> input;
            if(input > 0){
                if(p==0) ++p;
                if(MAXNUM - arr.back() >= input) arr.back() += input;
                else {
                    ll tmp = input - (MAXNUM - arr.back());
                    arr.back() = MAXNUM;
                    arr.push_back(tmp);
                    ++p;
                }
            }
            else if(input < 0){
                if(m == 0) ++m;
                if(MINNUM - arr.front() > input){
                    ll tmp = input - (MINNUM - arr.front());
                    arr.front() = MINNUM;
                    arr.push_front(tmp);
                    ++m;
                }
                else arr.front() += input;
            }
        }
        
        if(m > p) cout << "-\n";
        else if(m < p) cout << "+\n";
        else{
            if(arr.front() + arr.back() > 0) cout << "+\n";
            else if(arr.front() + arr.back() < 0) cout << "-\n";
            else cout << "0\n";
        }
    
    }
    
    return 0;
}
