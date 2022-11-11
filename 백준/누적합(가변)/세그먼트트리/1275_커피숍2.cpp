// 구간에서의 특정 부분 갱신을 빠르게 연산

#include <iostream>
#include <algorithm>
#include <vector>
#define MAXLEN 100005
using namespace std;

typedef long long int ll;

class SegmentTree {
private:
    int n;
    vector<ll> tree;
public:
    SegmentTree(int n) : n(n) {
        tree = vector<ll> (n*4+6, 0);
    }
    void init(int idx, ll value, int node, int nodeLeft, int nodeRight) {
        if(idx < nodeLeft || nodeRight < idx) return;
        if(nodeLeft == nodeRight) {
            tree[node] = value;
            return;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        init(idx, value, node*2, nodeLeft, mid);
        init(idx, value, node*2+1, mid+1, nodeRight);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    void acc_range(int idxLeft, int idxRight, ll value, int node, int nodeLeft, int nodeRight) {
        if(idxRight < nodeLeft || nodeRight < idxLeft) return;
        if(idxLeft <= nodeLeft && nodeRight <= idxRight) {
            tree[node] += value;
            return;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        acc_range(idxLeft, idxRight, value, node*2, nodeLeft, mid);
        acc_range(idxLeft, idxRight, value, node*2+1, mid+1, nodeRight);
    }
    void change_point(int idx, ll value, int node, int nodeLeft, int nodeRight) {
        if(idx < nodeLeft || nodeRight < idx) return;
        if(nodeLeft == nodeRight) {
            tree[node] = value;
            return;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        change_point(idx, value, node*2, nodeLeft, mid);
        change_point(idx, value, node*2+1, mid+1, nodeRight);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    ll get_sum(int idxLeft, int idxRight, int node, int nodeLeft, int nodeRight) {
        if(idxRight < nodeLeft || nodeRight < idxLeft) return 0;
        if(idxLeft <= nodeLeft && nodeRight <= idxRight) return tree[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        return get_sum(idxLeft, idxRight, 2*node, nodeLeft, mid) + get_sum(idxLeft, idxRight, 2*node+1, mid+1, nodeRight);
    }
};

int N, Q;
ll arr[MAXLEN];

int main(void) {
    
    cin >> N >> Q;
    
    SegmentTree ST = SegmentTree(N);
    
    for(int i=0; i<N; ++i) {
        cin >> arr[i];
        ST.init(i, arr[i], 1, 0, N-1);
    }
    
    for(int i=0; i<Q; ++i) {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if(x > y) swap(x,y);
        printf("%lld\n", ST.get_sum(x-1, y-1, 1, 0, N-1));
        ST.change_point(a-1, b, 1, 0, N-1);
    }
    
}
