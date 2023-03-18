#include <iostream>
#include <deque>
#include <set>
#define MAX_BOARD 105
using namespace std;

// set이나 deque 같은 STL 컨테이너에 특정 struct 타입 넣으려면, 대소 비교 위한 operator() 재정의 요구된다.
struct co {
    int x;
    int y;
    bool operator<(const co &other) const {
        if(x == other.x) return y < other.y;
        else return x < other.x;
    }
};

int N, K, L;

// !!!turn이 10000번까지 있을 수 있다는 점 놓침!!!
bool apples[105][105];
char turns[10005];
int heading = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

set<co> track_set;
deque<co> track_deq;

// 격자를 벗어나는 경우
bool OOB(co head) {
    if(head.x<1 || head.x>N || head.y<1 || head.y>N) return true;
    else return false;
}

// 자기 몸에 닿은 경우
bool BOOM(co head) {
    if(track_set.find(head) != track_set.end()) return true;
    else return false;
}

// 다음 방향 정하기
int get_direction(int heading, int tick) {
    if(turns[tick] == 'L') return heading > 0 ? heading - 1 : 3;
    else if(turns[tick] == 'D') return heading < 3 ? heading + 1 : 0;
    return heading;
}

// 다음 위치 계산
co get_next(co cur, int heading) {
    return {cur.x + dx[heading], cur.y + dy[heading]};
}

int main(void) {
    
    // 보드 크기
    scanf("%d", &N);
    
    // 사과 위치
    scanf("%d", &K);
    for(int i=0; i<K; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        apples[x][y] = true;
    }
    
    // 위치 변경 시점
    scanf("%d", &L);
    for(int i=0; i<L; ++i) {
        int tick; scanf("%d", &tick);
        scanf(" %c", &turns[tick]);
    }
    
    // track_set, track_deq 초기화
    track_set.insert({1, 1});
    track_deq.push_front({1, 1});
    
    // 초기 위치
    co cur = {1, 1};
    
    // 시간 틱
    int tick = 1;
    
    // 다음 헤드
    co head = get_next(cur, heading);
    
    while(!OOB(head) && !BOOM(head)) {
        // 현재 위치 조정
        cur = head;
        
        // 일단 길이를 늘린다.
        track_set.insert(cur);
        track_deq.push_front(cur);
        
        // 사과 없으면 맨 뒤에 놈 제거한다.
        if(!apples[cur.x][cur.y]) {
            co back = track_deq.back(); track_deq.pop_back();
            track_set.erase(back);
        }
        // !!!사과 있으면 먹는 것 놓침!!!
        else apples[cur.x][cur.y] = false;
        
        // 방향을 설정한다.
        heading = get_direction(heading, tick);
        tick += 1;
        
        // head 설정
        head = get_next(cur, heading);
    }
    
    printf("%d\n", tick);
    
    return 0;
}
