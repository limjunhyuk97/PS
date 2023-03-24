#include <iostream>
#include <deque>
#define GRIDLEN 105
using namespace std;

typedef pair<int, int> co;

int N;
int x, y, d, g;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool grid[105][105];

co rotate_curve(const co & target, const co & base) {
    co vec = {base.first - target.first, base.second - target.second};
    return {base.first + 1 * vec.second, base.second - vec.first};
}

int get_cubes () {
    int cubes = 0;
    for(int i=0; i<100; ++i) {
        for(int j=0; j<100; ++j) {
            if(grid[i][j] && grid[i][j+1] && grid[i+1][j] && grid[i+1][j+1]) cubes += 1;
        }
    }
    return cubes;
}

void get_curves(int x, int y, int d, int g) {
    co start = {x, y};
    co end = {start.first + dx[d], start.second + dy[d]};
    
    // 0 세대
    deque<co> deq;
    
    // deque 등록
    deq.push_back(start);
    deq.push_back(end);
    
    // grid 등록
    grid[start.second][start.first] = true;
    grid[end.second][end.first] = true;
    
    for(int i=0; i<g; ++i) {
        co end = deq.back();
        int size = (int)deq.size();
        for(int i = size-2; i>=0; --i) {
            co cur = deq[i];
            co rotated = rotate_curve(cur, end);
            deq.push_back(rotated);
            grid[rotated.second][rotated.first] = true;
        }
    }
}

int main(void) {
    
    scanf("%d", &N);
    
    for(int i=0; i<N; ++i) {
        int x, y, d, g; scanf("%d %d %d %d", &x, &y, &d, &g);
        get_curves(x, y, d, g);
    }
    
    printf("%d\n", get_cubes());
    
    return 0;
}
