// 우선순위 큐, 정렬, 그리디 세가지 잘 써먹으면 됨

#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pivot;

struct Lecture{
    int number;
    int start;
    int end;
    
    bool operator<(const Lecture& other) const {
        if(start != other.start) return start < other.start;
        else return end < other.end;
    }
};

int N, n, s, e;
Lecture lectures[100005];

int cnt = 1;
int result[100005];

struct ascending {
    bool operator()(const pivot &p1, const pivot &p2) const{
        return p1.first > p2.first;
    }
};

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d %d %d", &n, &s, &e);
        lectures[i] = { n ,s ,e };
    }
    
    sort(&lectures[0], &lectures[N]);
    
    priority_queue<pivot, vector<pivot>, ascending> pivots;
    
    pivots.push(make_pair(lectures[0].end, cnt));
    result[lectures[0].number] = cnt;


    for(int i=1; i<N; ++i) {
        pivot tmp = pivots.top();
        // 갱신 불가능
        if(tmp.first > lectures[i].start) {
            result[lectures[i].number] = ++cnt;
            pivots.push(make_pair(lectures[i].end, cnt));
        }
        // 갱신 가능
        else {
            pivots.pop();
            result[lectures[i].number] = tmp.second;
            tmp.first = lectures[i].end;
            pivots.push(tmp);
        }
    }
    
    printf("%d\n", cnt);
    for(int i=1; i<N+1; ++i) printf("%d\n", result[i]);
    
    return 0;
}

