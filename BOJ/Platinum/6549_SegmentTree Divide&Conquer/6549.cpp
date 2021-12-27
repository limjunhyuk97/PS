#include <iostream>
#include <algorithm>
#define MAX_N 100000
using namespace std;

typedef long long int ll;

int N;
int Data[MAX_N + 1];
int segment[MAX_N * 4];

// 구간 내 최소 값의 위치에 대한 segment tree 생성
void makeSet(int start, int end, int node){
    if(start == end) segment[node] = start;
    else{
        int mid = (start + end) >> 1;
        makeSet(start, mid, node * 2 );
        makeSet(mid+1, end, node * 2 + 1);
        if(Data[segment[node * 2]] <= Data[segment[node*2 + 1]])
            segment[node] = segment[node * 2];
        else
            segment[node] = segment[node * 2 + 1];
    }
}

// left ~ right : 내가 알고 싶은 구간
// start ~ end : 내가 지금 보고 있는 구간
// 내가 알고 싶은 구간에서 최소 값의 위치 찾기 : 내가 보고 있는 구간을 옮겨가면서 확인한다
int query(int start, int end, int node, int left, int right){
    
    // 내가 지금 보고 있는 구간이, 내가 알고 싶은 구간과 하나도 일치하지 않는다면
    if(right < start || end < left) return -1;
    
    // 내가 지금 보고 있는 구간이, 내가 알고 싶은 구간 내에 속해 있다면
    if(left <= start && end <= right) return segment[node];
    
    // 내가 지금 보고 있는 구간과, 내가 알고 싶은 구간이 걸쳐 있다면
    int mid = (start + end) >> 1;
    int leftMin = query(start, mid, node * 2, left, right);
    int rightMin = query(mid+1, end, node * 2 + 1, left, right);
    
    if(leftMin == -1) return rightMin;
    if(rightMin == -1) return leftMin;
    
    return (Data[leftMin] >= Data[rightMin] ? rightMin : leftMin) ;
 
}

// 어떤 구간에서 만들어질 수 있는 직사각형의 최대 높이는, 가장 낮은 직사각형 높이에 의해서 결정된다.
// 가장 낮은 높이를 갖는 직사각형의 넓이부터 가장 높은 높이를 갖는 직사각형의 높이까지 측정한다.
ll maxArea(int start, int end){
    
    int smallest = query(0, N - 1, 1, start, end);
    ll area = (ll)Data[smallest] * (end - start + 1);
    
    if(start < smallest)
        area = max(area, maxArea(start, smallest - 1));
    if(end > smallest)
        area = max(area, maxArea(smallest + 1, end));
    
    return area;
}


int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        
        cin >> N;
        if(N == 0) break;
        
        for(int i=0; i<N; ++i)
            cin >> Data[i];
        
        makeSet(0, N - 1, 1);
        cout << maxArea(0, N - 1) << "\n";
        
    }
    
    return 0;
}
