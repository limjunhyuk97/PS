// 구간의 합을 어떻게 빠르게 구할 것인가?
// 한쪽을 정렬하고 다른쪽을 세는 작업

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAXLEN 4000005
using namespace std;

typedef long long int ll;
typedef pair<int, int> p;

class SegmentTree {
private:
    int n;
    vector<ll> tree;
public:
    SegmentTree(int n) : n(n) {
        tree = vector<ll> (4*n+5, 0);
    }
    void init(int idx, ll value, int node, int nodeLeft, int nodeRight) {
        if(idx < nodeLeft || nodeRight < idx) return;
        if(nodeLeft == nodeRight) {
            tree[node] = value;
            return;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        init(idx, value, 2*node, nodeLeft, mid);
        init(idx, value, 2*node+1, mid+1, nodeRight);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    // 특정 지점에 value씩 증가시킴
    void acc_point(int idx, ll value, int node, int nodeLeft, int nodeRight) {
        if(idx < nodeLeft || nodeRight < idx) return;
        if(nodeLeft == nodeRight) {
            tree[node] += value;
            return;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        acc_point(idx, value, 2*node, nodeLeft, mid);
        acc_point(idx, value, 2*node+1, mid+1, nodeRight);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    ll get_sum(int idxLeft, int idxRight, int node, int nodeLeft, int nodeRight) {
        if(idxRight < nodeLeft || idxLeft > nodeRight) return 0;
        if(idxLeft <= nodeLeft && nodeRight <= idxRight) return tree[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        return get_sum(idxLeft, idxRight, 2*node, nodeLeft, mid) + get_sum(idxLeft, idxRight, 2*node+1, mid+1, nodeRight);
    }
};

int N, M;
p edges[MAXLEN];

int main(void) {
    
    scanf("%d %d", &N, &M);
    SegmentTree ST = SegmentTree(N);
    
    for(int i=0; i<M; ++i) {
        scanf("%d %d", &edges[i].first, &edges[i].second);
    }
    
    sort(&edges[0], &edges[M]);
    
    ll answer = 0;
    int curLeft = edges[0].first;
    map<int, int> tmp;
    
    for(int i=0; i<M; ++i) {
        // 왼쪽 수가 달라졌다면 : tmp 갱신
        if(curLeft != edges[i].first) {
            for(auto iter : tmp) {
                ST.acc_point(iter.first, iter.second, 1, 1, N);
            }
            tmp.clear();
        }
        // 왼쪽 수가 같다면 : tmp에 오른쪽 수 갯수 넣고 answer 구하기
        if(tmp.find(edges[i].second) != tmp.end()) {
            tmp[edges[i].second] += 1;
        }
        else tmp.insert({edges[i].second, 1});
        answer += ST.get_sum(edges[i].second+1, N, 1, 1, N);
    }
    
    printf("%lld\n", answer);
    
    return 0;
}
