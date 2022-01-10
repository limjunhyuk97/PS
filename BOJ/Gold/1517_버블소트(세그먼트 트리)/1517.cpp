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
struct nipair{
    int number;
    int index;
    bool operator<(const nipair &other) const{
        return number < other.number;
    }
};

int N;
int max_seg[2000000];
int min_seg[2000000];
ll sum;
vector<nipair> input;
vector<int> biggernum;

// segment tree 형성. input array의 left, right 범위 내의 가장 큰 index 값을 seg_tree에 저장
int make_max(int n, int left, int right){
    if(left == right){
        max_seg[n] = left;
        return left;
    }
    else{
        int mid = (left + right) >> 1;
        int lIdx = make_max(n * 2, left, mid);
        int rIdx = make_max(n*2+1, mid+1, right);
        if (input[lIdx].number > input[rIdx].number){
            max_seg[n] = lIdx;
            return lIdx;
        }
        else{
            max_seg[n] = rIdx;
            return rIdx;
        }
    }
}

int make_min(int n, int left, int right){
    if(left == right){
        min_seg[n] = left;
        return left;
    }
    else{
        int mid = (left + right) >> 1;
        int lIdx = make_min(n * 2, left, mid);
        int rIdx = make_min(n*2+1, mid+1, right);
        if (input[lIdx].number > input[rIdx].number){
            min_seg[n] = rIdx;
            return rIdx;
        }
        else{
            min_seg[n] = lIdx;
            return lIdx;
        }
    }
}

// start - end : 내가 찾고 싶은 범위
// left - right : 내가 들여다보고 있는 범위, 대표 인덱스 : n
int findbiggernum(int start, int end, int n, int left, int right, int target){
    if(right < start || end < left) return 0;
    else if(start <= left && right <= end){
        if(input[min_seg[n]].number > target) return right - left + 1;
        else{
            if(input[max_seg[n]].number < target) return 0;
            else{
                return findbiggernum(start, end, 2 * n, left, right + left >> 1, target) + findbiggernum(start, end, 2 * n + 1, (left + right >> 1) + 1, right, target);
            }
        }
    }
    else{
        return findbiggernum(start, end, 2 * n, left, right + left >> 1, target) + findbiggernum(start, end, 2 * n + 1, (left + right >> 1) + 1, right, target);
    }
}
 
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; ++i){
        int tmp; cin >> tmp;
        input.push_back({tmp, i});
    }
    
    make_max(1, 0, (int)input.size()-1);
    make_min(1, 0, (int)input.size()-1);
    
    for(int i=0; i< input.size(); ++i){
        biggernum.push_back(findbiggernum(0, i-1, 1, 0, input.size() - 1, input[i].number));
    }
    
    sort(input.begin(), input.end());
    
    for(int i=0; i<input.size(); ++i){
        sum += (ll)i - ((ll)input[i].index - (ll)biggernum[i]);
    }
    
    cout << sum << endl;
    
    return 0;
}
