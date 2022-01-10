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
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

ll arr[10];
string N;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    // N이 한자리인 경우는 따로 빼서 생각하자.
    if(N.size() == 1)
        for(int i=1; i<=N[0] - '0'; ++i)
            arr[i]++;
    
    // i는 자릿수. j는 해당 자리의 0~9 사이의 대상이 되는 수
    else
        for(int i=0; i<N.size(); ++i){
            for(int j=0; j<= 9; ++j){
                // 첫번째 자리에서는 0을 고려하지 않는다.
                if(i == 0 && j == 0) continue;
                // 현재 자리의 수보다   작은 수에 대해
                if(j < N[i] - '0'){
                    if(i == 0) arr[j] += (ll)pow((double)10,(double)N.size() - 1);
                    else
                        if(j != 0) arr[j] += (stol(N.substr(0, i)) + 1) * (ll)pow((double)10, (double)(N.size() - (i+1)));
                        else arr[j] += stol(N.substr(0, i)) * (ll)pow((double)10, (double)(N.size() - (i+1)));
                }
                // 현재 자리의 수와   같은 수에 대해
                else if(j == N[i] - '0'){
                    if(i == 0) arr[j] += stol(N.substr(1)) + 1;
                    else if(i == N.size() - 1){
                        if(j != 0) arr[j] += stol(N.substr(0, i)) + 1;
                        else arr[j] += stol(N.substr(0, i));
                    }
                    else{
                        if(j != 0) arr[j] += (stol(N.substr(i+1)) + 1) + (stol(N.substr(0, i)) * (ll)pow((double)10, (double)(N.size()) - (i+1)));
                        else arr[j] += (stol(N.substr(i+1)) + 1) + ((stol(N.substr(0, i)) - 1) * (ll)pow((double)10, (double)(N.size()) - (i+1)));
                    }
                }
                // 현재 자리의 수보다  큰 수에 대해
                else{
                    if(i == 0) continue;
                    else if(i == N.size() - 1) arr[j] += stol(N.substr(0, i));
                    else arr[j] += stol(N.substr(0, i)) * (ll)pow((double)10, (double)(N.size()) - (i+1));
                }
            }
        }
    
    for(int i=0; i<10; ++i)
        cout << arr[i] << " ";
    cout << '\n';
    
    return 0;
}

