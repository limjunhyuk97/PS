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
              
int m, n;
int grid[305][305];
int cnt;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n;
    
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            cin >> grid[i][j];
        }
    }
    
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            for(int k=1; k<=10; ++k){
                if(i + k <= m){
                    int sum = 0;
                    for(int p=0; p<(int)(10/k); ++p){
                        if(j + p >= n) break;
                        for(int l = 0; l < k ; ++l){
                            sum += grid[i + l][j + p];
                        }
                        if(sum > 10){ break; }
                        else if(sum == 10) { cnt++; break;}
                    }
                }
            }
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}
