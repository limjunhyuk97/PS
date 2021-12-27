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
int n, m;
int parent[500005];

int Find(int i){
    if(parent[i] < 0) return i;
    
    int p = parent[i];
    for(; parent[p] >=0; p=parent[p]);
    
    parent[i] = p;
    
    return p;
}

bool Join(int i, int j){
    int iroot = Find(i);
    int jroot = Find(j);
    
    if(iroot == jroot){
        if(iroot == -1 && jroot == -1)
            return false;
        else
            return true;
    }
    else{
        int tmp = parent[iroot] + parent[jroot];
        // jroot에 수가 더 많음
        if(parent[iroot] > parent[jroot]){
            parent[iroot] = jroot;
            parent[jroot] = tmp;
            return false;
        }
        else{
            parent[jroot] = iroot;
            parent[iroot] = tmp;
            return false;
        }
    }
}

int cnt, v1, v2;
bool flag;

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<500005; ++i)
        parent[i] = -1;

    cin >> n >> m;
    
    for(int i=0; i<m; ++i){
        cin >> v1 >> v2;
        if(!flag){
            ++cnt;
            if(Join(v1, v2)) flag = true;
        }
    }
    
    if(!flag) cout << 0 << endl;
    else cout << cnt << endl;

    return 0;
}

