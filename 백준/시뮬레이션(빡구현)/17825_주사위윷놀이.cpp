#include <iostream>
#include <queue>
using namespace std;

struct node {
    int val;
    int rni;
    int bni;
    char c;
};

struct status {
    int horses[4];
    int val;
};

int total_sum = 0;

node nodes[33];
status cur;
int toss[10];

// 움직임이 불가능하면 안움직이고 -1 반환
// 움직임이 가능하면 움직이고 현재 위치의 가중치 값 반환
int restricted (int idx, int horses[], int turn) {
    // 이동하려는데 이미 종착지면 못간다.
    if(nodes[horses[idx]].c == 'e') return -1;
    // b 이라면 현재
    else if(nodes[horses[idx]].c == 'b') {
        // 이동 목적지 찾기
        int dest = horses[idx];
        for(int i=0; i<turn; ++i) {
            if(i == 0) dest = nodes[dest].bni;
            else dest = nodes[dest].rni;
        }
        // 다른 놈이 있다면 못간다.
        for(int i=0; i<4; ++i) {
            if(i == idx) continue;
            if(nodes[horses[i]].c == 'e') continue;
            if(horses[i] == dest) return -1;
        }
        // 이동한 놈의 현재 위치 변경
        horses[idx] = dest;
        return nodes[dest].val;
    }
    // s나 r이라면 현재
    else {
        // 이동 목적지 찾기
        int dest = horses[idx];
        for(int i=0; i<turn; ++i) {
            dest = nodes[dest].rni;
        }
        // 다른 놈이 있다면 못간다.
        for(int i=0; i<4; ++i) {
            if(i == idx) continue;
            if(nodes[horses[i]].c == 'e') continue;
            if(horses[i] == dest) return -1;
        }
        // 이동한 놈의 현재 위치 변경
        horses[idx] = dest;
        return nodes[dest].val;
    }
}

void bfs(status cur) {
    queue<status> que;
    que.push(cur);
    
    int tick = 1;
    while(!que.empty()) {
        int size = (int)que.size();
        for(int i=0; i<size; ++i) {
            status cur = que.front(); que.pop();
            // 네마리 각각의 이동 고려
            for(int j=0; j<4; ++j) {
                // 말 이동 한놈씩 고려
                // 말 복제
                int rep_horses[4];
                for(int i=0; i<4; ++i) {
                    rep_horses[i] = cur.horses[i];
                }
                // 복제 이동
                int adder = restricted(j, rep_horses, toss[tick-1]);
                if(adder >= 0) {
                    // 말 위치 갱신
                    status ncur;
                    for(int k=0; k<4; ++k) {
                        ncur.horses[k] = rep_horses[k];
                    }
                    // status 값 갱신
                    ncur.val = cur.val + adder;
                    // 전체 status도 갱신
                    total_sum = ncur.val > total_sum ? ncur.val : total_sum;
                    que.push(ncur);
                }
            }
        }
        // tick이 10을 넘으면 종료
        tick += 1;
        if(tick > 10) break;
    }
}

int main(void){
    // 주사위 토스 초기화
    for(int i=0; i<10; ++i) {
        scanf("%d", &toss[i]);
    }
    
    // 말판 초기화 (val, rni, bni, c)
    nodes[0] = {0, 1, -1, 's'};
    nodes[1] = {2, 2, -1, 'r'};
    nodes[2] = {4, 3, -1, 'r'};
    nodes[3] = {6, 4, -1, 'r'};
    nodes[4] = {8, 5, -1, 'r'};
    nodes[5] = {10, 13, 6, 'b'};
    nodes[6] = {13, 7, -1, 'r'};
    nodes[7] = {16, 8, -1, 'r'};
    nodes[8] = {19, 9, -1, 'r'};
    nodes[9] = {25, 10, -1, 'r'};
    nodes[10] = {30, 11, -1, 'r'};
    nodes[11] = {35, 12, -1, 'r'};
    nodes[12] = {40, 32, -1, 'r'};
    nodes[13] = {12, 14, -1, 'r'};
    nodes[14] = {14, 15, -1, 'r'};
    nodes[15] = {16, 16, -1, 'r'};
    nodes[16] = {18, 17, -1, 'r'};
    nodes[17] = {20, 18, 27, 'b'};
    nodes[18] = {22, 19, -1, 'r'};
    nodes[19] = {24, 20, -1, 'r'};
    nodes[20] = {26, 21, -1, 'r'};
    nodes[21] = {28, 22, -1, 'r'};
    nodes[22] = {30, 23, 29, 'b'};
    nodes[23] = {32, 24, -1, 'r'};
    nodes[24] = {34, 25, -1, 'r'};
    nodes[25] = {36, 26, -1, 'r'};
    nodes[26] = {38, 12, -1, 'r'};
    nodes[27] = {22, 28, -1, 'r'};
    nodes[28] = {24, 9, -1, 'r'};
    nodes[29] = {28, 30, -1, 'r'};
    nodes[30] = {27, 31, -1, 'r'};
    nodes[31] = {26, 9, -1, 'r'};
    nodes[32] = {0, 32, -1, 'e'};
    
    // status 초기화
    for(int i=0; i<4; ++i) {
        cur.horses[i] = 0;
        cur.val = 0;
    }
    
    bfs(cur);
    
    printf("%d\n", total_sum);
}
