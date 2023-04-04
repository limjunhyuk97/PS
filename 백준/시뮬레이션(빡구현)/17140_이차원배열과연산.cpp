#include <iostream>
#include <queue>
#define MAXLEN 110
using namespace std;

struct node {
    int num;
    int cnt;
    bool operator<(const node & other) const {
        if(cnt != other.cnt) return cnt > other.cnt;
        else return num > other.num;
    }
};

int r, c, k;
int grid[MAXLEN][MAXLEN];

int rows = 3, cols = 3;

// 행 정렬
void R() {
    int count[MAXLEN];
    // 각 행마다 연산
    for(int i=1; i<=rows; ++i) {
        priority_queue<node> pq;
        fill(&count[0], &count[MAXLEN], 0);
        // 열들에 들어있는 수 세기
        for(int j=1; j<=cols; ++j) {
            count[grid[i][j]] += 1;
        }
        // 열들에 들어있는 수 바탕으로 pq에 push
        for(int j=1; j<MAXLEN; ++j) {
            if(count[j] == 0) continue;
            else pq.push({j, count[j]});
        }
        // 열 길이 갱신
        cols = cols < (int)pq.size()*2 ? (int)pq.size()*2 : cols;
        cols = cols > 100 ? 100 : cols;
        // grid 배열 갱신
        for(int j=1; j<= 100; ++j) {
            if(!pq.empty()) {
                node cur = pq.top(); pq.pop();
                grid[i][j++] = cur.num;
                grid[i][j] = cur.cnt;
            }else {
                grid[i][j] = 0;
            }
        }
    }
}

// 열 정렬
void C() {
    int count[MAXLEN];
    // 각 열마다 연산
    for(int i=1; i<=cols; ++i) {
        priority_queue<node> pq;
        fill(&count[0], &count[MAXLEN], 0);
        // 행들에 들어있는 수 세기
        for(int j=1; j<=rows; ++j) {
            count[grid[j][i]] += 1;
        }
        // 행들에 들어있는 수 바탕으로 pq에 push
        for(int j=1; j<MAXLEN; ++j) {
            if(count[j] == 0) continue;
            else pq.push({j, count[j]});
        }
        // 행 길이 갱신
        rows = rows < (int)pq.size()*2 ? (int)pq.size()*2 : rows;
        rows = rows > 100 ? 100 : rows;
        // grid 배열 갱신
        for(int j=1; j<= 100; ++j) {
            if(!pq.empty()) {
                node cur = pq.top(); pq.pop();
                grid[j++][i] = cur.num;
                grid[j][i] = cur.cnt;
            }else {
                grid[j][i] = 0;
            }
        }
    }
}

int main(void) {
    
    scanf("%d %d %d", &r, &c, &k);
    
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=3; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    int cnt = 0;
    while(true) {
        // grid[r][c] == k 면 break 걸어라!
        if(grid[r][c] == k) break;
        
        // 시간 증가
        cnt += 1;
        
        // 100 초 넘으면
        if(cnt > 100) break;
        
        // 행의 수 < 열의 수 : C 아니면 R
        if(rows < cols) C();
        else R();
    }
    
    printf("%d\n", cnt > 100 ? -1 : cnt);
    
    return 0;
}
