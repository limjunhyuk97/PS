#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int > node;

int K;
char wheels[5][10];
bool visited[4];

// 바퀴 돌리기
void turn(int wheel, int dir) {
    // 시계방향
    if(dir == 1) {
        char tmp = wheels[wheel][7];
        for(int i=6; i>=0; --i) wheels[wheel][i+1] = wheels[wheel][i];
        wheels[wheel][0] = tmp;
    }
    // 반시계방향
    else if(dir == -1) {
        char tmp = wheels[wheel][0];
        for(int i=1; i<8; ++i) wheels[wheel][i-1] = wheels[wheel][i];
        wheels[wheel][7] = tmp;
    }
    else return;
}

int get_turn(int cur, int next) {
    if(cur+1 == next) {
        if(wheels[cur][2] == wheels[next][6]) return 0;
        else return -1;
    }
    else if(cur-1 == next) {
        if(wheels[cur][6] == wheels[next][2]) return 0;
        else return -1;
    }
    return 1;
}


int main(void) {
    
    for(int i=0; i<4; ++i) {
        for(int j=0; j<8; ++j) {
            scanf("%c", &wheels[i][j]);
        }
        char tmp; scanf("%c", &tmp);
    }
    
    scanf("%d", &K);
    
    for(int i=0; i<K; ++i) {
        int wheel, direction; scanf("%d %d", &wheel, &direction);
        wheel -= 1;
        
        fill(&visited[0], &visited[4], false);
        
        queue<node> que;
        que.push({wheel, direction});
        
        while(!que.empty()) {
            node cur = que.front(); que.pop();
            int cw = cur.first;
            int cd = cur.second;
            
            visited[cw] = true;
            
            if(cw-1>=0 && !visited[cw-1]) {
                que.push({cw-1, get_turn(cw, cw-1)*cd});
            }
            if(cw+1<4 && !visited[cw+1]) {
                que.push({cw+1, get_turn(cw, cw+1)*cd});
            }
            
            turn(cw, cd);
        }
    }
    
    int score = 0;
    for(int i=0; i<4; ++i) {
        score += wheels[i][0] == '0' ? 0 : (int)pow((double)2, (double)i);
    }
    
    printf("%d\n", score);
    
    return 0;
}
