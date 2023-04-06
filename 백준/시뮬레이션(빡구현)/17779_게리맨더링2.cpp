#include <iostream>
#include <algorithm>
#define MAXLEN 25
#define INF 500000
using namespace std;

int N;
int A[MAXLEN][MAXLEN];
int grid[MAXLEN][MAXLEN];

int x, y, d1, d2;
int gap = INF;

void initGrid() {
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            grid[i][j] = 0;
        }
    }
}

void setArea() {
    // 초반
    for(int i=1; i<x; ++i) {
        for(int j=1; j<=N; ++j) {
            if(j <= y) grid[i][j] = 1;
            else grid[i][j] = 2;
        }
    }
    // 중간계
    if(d1 == d2) {
        for(int i=x; i<x+d1; ++i) {
            int gap = i-x;
            for(int j=1; j<=N; ++j) {
                if(j < y-gap) grid[i][j] = 1;
                else if(j > y+gap) grid[i][j] = 2;
                else grid[i][j] = 5;
            }
        }
        for(int j=1; j<=N; ++j) {
            if(j<y-d1) grid[x+d1][j] = 3;
            else if(j>y+d2) grid[x+d1][j] = 2;
            else grid[x+d1][j] = 5;
        }
        for(int i=x+d1+1; i<=x+d1+d2; ++i) {
            int gap = i-x-d1;
            for(int j=1; j<=N; ++j) {
                if(j < y-d1+gap) grid[i][j] = 3;
                else if(j > y+d2-gap) grid[i][j] = 4;
                else grid[i][j] = 5;
            }
        }
    }
    else if(d1 < d2) {
        // 1
        for(int i=x; i<x+d1; ++i) {
            for(int j=1; j<=N; ++j) {
                int gap = i-x;
                if(j < y-gap) grid[i][j] = 1;
                else if(j > y+gap) grid[i][j] = 2;
                else grid[i][j] = 5;
            }
        }
        // 2
        for(int j=1; j<=N; ++j) {
            if(j<y-d1) grid[x+d1][j] = 3;
            else if(j>y+d1) grid[x+d1][j] = 2;
            else grid[x+d1][j] = 5;
        }
        // 3
        for(int i=x+d1+1; i<x+d2; ++i) {
            int gap = i-(x+d1);
            for(int j=1; j<=N; ++j) {
                if(j<y-d1+gap) grid[i][j] = 3;
                else if(j>y+d1+gap) grid[i][j] = 2;
                else grid[i][j] = 5;
            }
        }
        // 4
        for(int j=1; j<=N; ++j) {
            int gap = d2-d1;
            if(j<y-d1+gap) grid[x+d2][j] = 3;
            else if(j>y+d2) grid[x+d2][j] = 2;
            else grid[x+d2][j] = 5;
        }
        // 5
        for(int i=x+d2+1; i<=x+d1+d2; ++i) {
            int gap = i-x-d2;
            for(int j=1; j<=N; ++j) {
                if(j < y+ d2 - 2*d1 + gap) grid[i][j] = 3;
                else if(j > y+d2-gap) grid[i][j] = 4;
                else grid[i][j] = 5;
            }
        }
    }
    else {
        // 1
        for(int i=x; i<x+d2; ++i) {
            for(int j=1; j<=N; ++j) {
                int gap = i-x;
                if(j < y-gap) grid[i][j] = 1;
                else if(j > y+gap) grid[i][j] = 2;
                else grid[i][j] = 5;
            }
        }
        // 2
        for(int j=1; j<=N; ++j) {
            if(j<y-d2) grid[x+d2][j] = 1;
            else if(j>y+d2) grid[x+d2][j] = 2;
            else grid[x+d2][j] = 5;
        }
        // 3
        for(int i=x+d2+1; i<x+d1; ++i) {
            int gap = i-(x+d2);
            for(int j=1; j<=N; ++j) {
                if(j<y-d2-gap) grid[i][j] = 1;
                else if(j>y+d2-gap) grid[i][j] = 4;
                else grid[i][j] = 5;
            }
        }
        // 4
        for(int j=1; j<=N; ++j) {
            int gap = d1-d2;
            if(j<y-d1) grid[x+d1][j] = 3;
            else if(j>y+d2-gap) grid[x+d1][j] = 4;
            else grid[x+d1][j] = 5;
        }
        // 5
        for(int i=x+d1+1; i<=x+d1+d2; ++i) {
            int gap = i-x-d1;
            for(int j=1; j<=N; ++j) {
                if(j < y-d1+gap) grid[i][j] = 3;
                else if(j > y+2*d2-d1 -gap) grid[i][j] = 4;
                else grid[i][j] = 5;
            }
        }
    }
    // 마지막
    for(int i=x+d1+d2+1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(j < y+d2-d1) grid[i][j] = 3;
            else grid[i][j] = 4;
        }
    }
}

void getGap() {
    int area[5] = {0, 0, 0, 0, 0};
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            area[grid[i][j]-1] += A[i][j];
        }
    }
    
    ///
//    cout << "x, y, d1, d2 : " << x << ", " << y << ", " << d1 << ", " << d2 <<endl;
//    for(int i=0; i<5; ++i) printf("%d ", area[i]);
//    cout << endl;
//    cout << "max:" << *max_element(area, area+5) << ", min:" <<*min_element(area, area+5) <<endl;
//    for(int i=1; i<=N; ++i) {
//        for(int j=1; j<=N; ++j) {
//            cout << grid[i][j] << " ";
//        }
//        cout << endl;
//    }
//    printf("\n\n");
    ///
    
    int new_gap = *max_element(area, area+5) - *min_element(area, area+5);
    
    gap = gap > new_gap ? new_gap : gap;
}

void setGrid() {
    initGrid();
    setArea();
    getGap();
}

void set_area() {
    for(int i=1; i<=N-2; ++i) {
        for(int j=1; j<=N-2; ++j) {
            if(i + j > N - 1) break;
            // d1과 d2를 택
            d1 = i; d2 = j;
            // x를 택
            for(int k=1; k<=N-d1-d2; ++k) {
                x = k;
                // y를 택
                for(int l=1+d1; l<=N-d2; ++l) {
                    y = l;
                    setGrid();
                }
            }
        }
    }
}

int main(void) {
    
    scanf("%d", &N);
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            scanf("%d", &A[i+1][j+1]);
        }
    }
    
    set_area();
    
    printf("%d\n", gap);
    
    return 0;
}
