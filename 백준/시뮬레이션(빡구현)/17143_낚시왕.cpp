#include <iostream>
#include <queue>
#include <set>
#define MAXLEN 105
#define MAXSHARKS 10005
using namespace std;

struct shark {
    int r;
    int c;
    int s;
    int d;
    int z;
    int idx;
    // 내림차순 (operator< 에서는 반대로 부여. 즉, true일 때 뒤집히는 것이므로 내림차순)
    bool operator<(const shark & other) const {
        return r > other.r;
    }
};

int R, C, M;

shark grid[MAXLEN][MAXLEN];

int earns;

shark sharks[MAXSHARKS];
bool dead[MAXSHARKS];

void initGrid() {
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            grid[i][j] = {0,0,0,0,0, 10004};
        }
    }
}

void move_shark(shark * sh) {
    switch(sh->d) {
        case 1:
            if(sh->s <= sh->r - 1) sh->r -= sh->s;
            else {
                int remainer = sh->s - (sh->r - 1);
                if((remainer / (R-1)) % 2 == 0) {
                    sh->d = 2;
                    sh->r = 1 + (remainer % (R-1));
                }else {
                    sh->r = R - (remainer % (R-1));
                }
            }
            break;
        case 2:
            if(sh->s <= R - sh->r) sh->r += sh->s;
            else {
                int remainer = sh->s - (R - sh->r);
                if((remainer / (R-1)) % 2 == 0) {
                    sh->d = 1;
                    sh->r = R - (remainer % (R-1));
                } else {
                    sh->r = 1 + (remainer % (R-1));
                }
            }
            break;
        case 3:
            if(sh->s <= C - sh->c) sh->c += sh->s;
            else {
                int remainer = sh->s - (C - sh->c);
                if((remainer / (C-1)) % 2 == 0) {
                    sh->d = 4;
                    sh->c = C - (remainer % (C-1));
                } else {
                    sh->c = 1 + (remainer % (C-1));
                }
            }
            break;
        case 4:
            if(sh->s <= sh->c - 1) sh->c -= sh->s;
            else {
                int remainer = sh->s - (sh->c - 1);
                if((remainer / (C-1)) % 2 == 0) {
                    sh->d = 3;
                    sh->c = 1 + (remainer % (C-1));
                } else {
                    sh->c = C - (remainer % (C-1));
                }
            }
            break;
        default:
            break;
    }
}

void printGrid() {
    for(int i=1 ; i<=R; ++i) {
        for(int j=1; j<=C; ++j) {
            printf("%d ", grid[i][j].z);
        }
        printf("\n");
    }
    printf("\n");
}

void grab(priority_queue<shark> cols[]) {
    for(int i=0; i<M; ++i) {
        if(dead[i]) continue;
        cols[sharks[i].c].push(sharks[i]);
    }
}

void tick() {
    initGrid();
    for(int i=0; i<M; ++i) {
        // 죽은 상어는 고려하지 않는다.
        if(dead[i]) continue;
        // 상어 이동
        move_shark(&sharks[i]);
        // grid 체크
        if(grid[sharks[i].r][sharks[i].c].z > sharks[i].z) dead[i] = true;
        else {
            // grid 갱신
            dead[grid[sharks[i].r][sharks[i].c].idx] = true;
            grid[sharks[i].r][sharks[i].c] = sharks[i];
        }
    }
//    printGrid();
}

int main(void) {
    
    scanf("%d %d %d", &R, &C, &M);
    
    for(int i=0; i<M; ++i) {
        int r, c, s, d, z; scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        sharks[i]={r, c, s, d, z, i};
    }
    
    // column 수 만큼 이동한다
    for(int i=1; i<=C; ++i) {
        priority_queue<shark> cols[MAXLEN];
        grab(cols);
        if(!cols[i].empty()) {
            earns += cols[i].top().z;
            dead[cols[i].top().idx] = true;
        }
        tick();
    }
    
    printf("%d\n", earns);
    
    return 0;
}
