// 세그먼트 트리
#include <iostream>
#include <vector>
#define MAX_BUFFER 1000005
using namespace std;

typedef long long int ll;

ll arr[MAX_BUFFER];
ll SegTree[MAX_BUFFER * 4];
int N, M, K, cnt;
int a;
ll b, c;

vector<ll> results;

ll init_SegTree(int s, int e, int idx) {
    if(s == e) return SegTree[idx] = arr[s];
    int mid = (s+e)>>1;
    return SegTree[idx] = init_SegTree(s, mid, 2*idx) + init_SegTree(mid+1, e, 2*idx+1);
}

// s ~ l ~ r ~ e : idx
ll sum_SegTree(int s, int e, int l, int r, int idx) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return SegTree[idx];
    int mid = (s+e) >> 1;
    return sum_SegTree(s, mid, l, r, idx*2) + sum_SegTree(mid+1, e, l, r, idx*2+1);
}

// s ~ (target) ~ e : idx
void update_SegTree(int s, int e, ll diff, int target, int idx) {
    if (target < s || target > e) return;
    SegTree[idx] += diff;
    if (s == e) return;
    int mid = (s+e)>>1;
    update_SegTree(s, mid, diff, target, idx*2);
    update_SegTree(mid+1, e, diff, target, idx*2+1);
}

int main(void){
    
    scanf("%d %d %d", &N, &M, &K);
    cnt = M + K;
    
    for(int i=0; i<N; ++i) {
        scanf("%lld", &arr[i]);
    }
    
    // initialize Tree
    init_SegTree(0, N-1, 1);
    
    while(cnt--) {
        scanf("%d %lld %lld", &a, &b, &c);
        // b번째 수를 c로 바꿔라
        if(a == 1) {
            ll diff = c - arr[b-1];
            arr[b-1] = c;
            update_SegTree(0, N-1, diff, b-1, 1);
        }
        // b부터 c까지의 합을 구해라
        else {
            results.push_back(sum_SegTree(0, N-1, b-1, c-1, 1));
        }
    }
    
    for (auto i : results)
        printf("%lld\n", i);
    
    return 0;
}
