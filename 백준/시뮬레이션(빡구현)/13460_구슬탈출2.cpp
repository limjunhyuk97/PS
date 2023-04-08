#include <iostream>
#include <queue>
#include <string>
#define MAXLEN 15
using namespace std;

//cout << r.first << "," << r.second << "/" <<b.first << "," << b.second <<endl;
//5 7
//#######
//#R..#B#
//#.O...#
//#.....#
//#######

typedef pair<int, int> co;

struct node {
    co r;
    co b;
};

int N, M;
char grid[MAXLEN][MAXLEN];

co rpos, bpos;

// true : R만 , false : B만 또는, R-B둘다, 아무도 안빠짐
bool left(node cur, queue<node>& que) {
    co r = cur.r, b = cur.b;
    
    bool movement = false;
    // r 먼저 움직이는 경우
    if(r.second < b.second) {
        bool flag = false;
        // r 움직이기
        while(grid[r.first][r.second-1] != '#') {
            r.second -= 1;
            movement = true;
            // R 낙
            if(grid[r.first][r.second] == 'O') {
                flag = true;
                break;
            }
        }
    
        // b 움직이기
        while(grid[b.first][b.second-1] != '#' && (flag || (!flag && (b.first != r.first || b.second-1 != r.second)))) {
            b.second -= 1;
            movement = true;
            // R 낙 B 낙 , B 낙
            if(grid[b.first][b.second] == 'O') return false;
        }
        
        // R 낙
        if(flag) return true;
        // 아무도 안 낙
        else {
            if(movement) que.push({r, b});
            return false;
        }
    }
    // b 먼저 움직이는 경우
    else {
        // b 움직이기
        while(grid[b.first][b.second-1] != '#') {
            b.second -= 1;
            movement = true;
            // R 낙 B 낙 , B 낙
            if(grid[b.first][b.second] == 'O') return false;
        }
        // r 움직이기
        while(grid[r.first][r.second-1] != '#' && (r.first != b.first || r.second-1 != b.second)) {
            r.second -= 1;
            movement = true;
            // R 낙
            if(grid[r.first][r.second] == 'O') return true;
        }
        // 아무도 안 낙
        if(movement) que.push({r, b});
        return false;
    }
}

bool right(node cur, queue<node>& que) {
    co r = cur.r, b = cur.b;
    bool movement = false;
    // r 먼저 움직이는 경우
    if(r.second > b.second) {
        bool flag = false;
        // r 움직이기
        while(grid[r.first][r.second+1] != '#') {
            r.second += 1;
            movement = true;
            // R 낙
            if(grid[r.first][r.second] == 'O') {
                flag = true;
                break;
            }
        }
        // b 움직이기
        while(grid[b.first][b.second+1] != '#' && (flag || (!flag && (r.first != b.first || r.second != b.second+1)))) {
            b.second += 1;
            movement = true;
            // R 낙 B 낙 , B 낙
            if(grid[b.first][b.second] == 'O') return false;
        }
        // R 낙
        if(flag) return true;
        // 아무도 안 낙
        else {
            if(movement) que.push({r, b});
            return false;
        }
    }
    // b 먼저 움직이는 경우
    else {
        // b 움직이기
        while(grid[b.first][b.second+1] != '#') {
            b.second += 1;
            movement = true;
            // R 낙 B 낙 , B 낙
            if(grid[b.first][b.second] == 'O') return false;
        }
        // r 움직이기
        while(grid[r.first][r.second+1] != '#' && (r.first != b.first || r.second+1 != b.second)) {
            r.second += 1;
            movement = true;
            // R 낙
            if(grid[r.first][r.second] == 'O') return true;
        }
        // 아무도 안 낙
        if(movement) que.push({r, b});
        return false;
    }
}

bool up(node cur, queue<node> &que) {
    co r = cur.r, b = cur.b;
    bool movement = false;
    // r 먼저 움직이는 경우
    if(r.first < b.first) {
        bool flag = false;
        // r 움직이기
        while(grid[r.first-1][r.second] != '#') {
            r.first -= 1;
            movement = true;
            // R 낙
            if(grid[r.first][r.second] == 'O') {
                flag = true;
                break;
            }
        }
        // b 움직이기
        while(grid[b.first-1][b.second] != '#' && (flag || (!flag && (r.first != b.first-1 || r.second != b.second)))) {
            b.first -= 1;
            movement = true;
            // R 낙 B 낙 , B 낙
            if(grid[b.first][b.second] == 'O') return false;
        }
        // R 낙
        if(flag) return true;
        // 아무도 안 낙
        else {
            if(movement)que.push({r, b});
            return false;
        }
    }
    // b 먼저 움직이는 경우
    else {
        // b 움직이기
        while(grid[b.first-1][b.second] != '#') {
            b.first -= 1;
            movement = true;
            // R 낙 B 낙 , B 낙
            if(grid[b.first][b.second] == 'O') return false;
        }
        // r 움직이기
        while(grid[r.first-1][r.second] != '#' && (r.first-1 != b.first || r.second != b.second)) {
            r.first -= 1;
            movement = true;
            // R 낙
            if(grid[r.first][r.second] == 'O') return true;
        }
        // 아무도 안 낙
        if(movement)que.push({r, b});
        return false;
    }
}

bool down(node cur, queue<node> & que) {
    co r = cur.r, b = cur.b;
    bool movement = false;
    // r 먼저 움직이는 경우
    if(r.first > b.first) {
        bool flag = false;
        // r 움직이기
        while(grid[r.first+1][r.second] != '#') {
            r.first += 1;
            movement = true;
            // R 낙
            if(grid[r.first][r.second] == 'O') {
                flag = true;
                break;
            }
        }
        // b 움직이기
        while(grid[b.first+1][b.second] != '#' && (flag || (!flag && (b.first+1 != r.first || b.second != r.second)))) {
            b.first += 1;
            movement = true;
            // R 낙 B 낙 , B 낙
            if(grid[b.first][b.second] == 'O') return false;
        }
        // R 낙
        if(flag) return true;
        // 아무도 안 낙
        else {
            if(movement)que.push({r, b});
            return false;
        }
    }
    // b 먼저 움직이는 경우
    else {
        // b 움직이기
        while(grid[b.first+1][b.second] != '#') {
            b.first += 1;
            movement = true;
            // R 낙 B 낙 , B 낙
            if(grid[b.first][b.second] == 'O') return false;
        }
        // r 움직이기
        while(grid[r.first+1][r.second] != '#' && (r.first+1 != b.first || r.second != b.second)) {
            r.first += 1;
            movement = true;
            // R 낙
            if(grid[r.first][r.second] == 'O') return true;
        }
        // 아무도 안 낙
        if(movement) que.push({r, b});
        return false;
    }
}

//cout << r.first << "," << r.second << "/" <<b.first << "," << b.second <<endl;
//for(int i=0; i<N; ++i) {
//    for(int j=0; j<M; ++j) {
//        printf("%c ", grid[i][j]);
//    }
//    printf("\n");
//}

int run() {
    int tick = 0;
    queue<node> que;
    que.push({rpos, bpos});
    
    bool flag = false;
    while(!que.empty() && !flag) {
        int size = (int)que.size();
        
        tick += 1;
        if(tick > 10) break;
        
//        cout << tick << endl;
//        cout << (flag ? "true" : "false")<< endl;
//        cout << size << endl;
        for(int i=0; i<size; ++i) {
            node cur = que.front(); que.pop();
//             cout << cur.r.first << "," << cur.r.second << "/" <<cur.b.first << "," << cur.b.second <<endl <<endl;
            if(left(cur, que)) {
                flag = true;
                break;
            }
            if(right(cur, que)) {
                flag = true;
                break;
            }
            if(up(cur, que))  {
                flag = true;
                break;
            }
            if(down(cur, que)) {
                flag = true;
                break;
            }
        }
    }
    
    return flag ? tick : -1;
}

int main(void) {
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i) {
        string str; cin >> str;
        for(int j=0; j<M; ++j) {
            grid[i][j] = str[j];
            if(grid[i][j] == 'R') {
                grid[i][j] = '.';
                rpos = {i, j};
            }
            if(grid[i][j] == 'B') {
                grid[i][j] = '.';
                bpos = {i, j};
            }
        }
    }
    
    int turn = run();
    printf("%d\n", turn);
    
    return 0;
}
