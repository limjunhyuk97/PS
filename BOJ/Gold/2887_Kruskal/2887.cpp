#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
struct Dist{

    int first;
    int end;
    ll weight;
    
    bool operator<(const Dist & other) const{
        return weight > other.weight;
    }
    
};

struct pairAscending{
    bool operator()(const pair<int, ll> &p1,const pair<int, ll> &p2){
        return p1.second < p2.second;
    }
}ascending;

int N;
int parent[100005];
ll x, y, z;

// xArr, yArr, zArr : x, y, z 값들에 대한 배열
// xDist, yDist, zDist : x, y, z 내부 차이들에 대한 priority queue
vector<pair<int, ll> > xArr, yArr, zArr;
priority_queue<Dist> allDist;

int Find(int a){
    int root = a;
    for(; parent[root] >=0; root = parent[root]);
    
    while(root != a){
        int tmp = parent[a];
        parent[a] = root;
        a = tmp;
    }
    return root;
}

void Union(int a, int b){
    int aroot = Find(a);
    int broot = Find(b);
    int tmp = parent[aroot] + parent[broot];
    
    if(aroot != broot){
        if(parent[aroot] < parent[broot]){
            parent[aroot] = broot;
            parent[broot] = tmp;
        }
        else{
            parent[broot] = aroot;
            parent[aroot] = tmp;
        }
    }
    
}

ll Kruskal(){
    
    ll ret = 0;
    
    while(!allDist.empty()){
        Dist cur = allDist.top(); allDist.pop();
       
        int firstV = cur.first;
        int secondV = cur.end;
        
        if(Find(firstV) != Find(secondV)){
            Union(firstV, secondV);
            ret += cur.weight;
        }
    }
    
    return ret;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        cin >> x >> y >> z;
        xArr.push_back({i, x});
        yArr.push_back({i, y});
        zArr.push_back({i, z});
    }
    
    for(int i=0; i<100005; ++i)
        parent[i] = -1;
    
    sort(xArr.begin(), xArr.end(), ascending);
    sort(yArr.begin(), yArr.end(), ascending);
    sort(zArr.begin(), zArr.end(), ascending);
    
    for(int i=0; i< N-1; ++i){
        allDist.push({ xArr[i].first, xArr[i+1].first, abs(xArr[i].second - xArr[i + 1].second) });
        allDist.push({ yArr[i].first, yArr[i+1].first, abs(yArr[i].second - yArr[i + 1].second) });
        allDist.push({ zArr[i].first, zArr[i+1].first, abs(zArr[i].second - zArr[i + 1].second) });
    }
                   
    cout << Kruskal() << "\n";
    
    return 0;
}
