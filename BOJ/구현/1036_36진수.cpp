#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXBUF 70
#define MAXROW 38
#define BASE 36
using namespace std;

int N, K;
int count_grid[MAXROW][MAXBUF];
int num_grid[MAXROW][MAXBUF];
bool checked[BASE];
vector<int> sorted_ordinal;

int base_to_dec(char c) {
    if('0' <= c && c <= '9') return c - '0';
    else return c - 'A' + 10;
}

void grid_add_operation(int n, int m, int operand) {
    count_grid[n][m] += operand;
    if(count_grid[n][m] > BASE-1) {
        grid_add_operation(n, m+1, count_grid[n][m]/BASE);
        count_grid[n][m] = count_grid[n][m] % BASE;
    }
}

void numgrid_add_operation(int n, int m, int operand) {
    num_grid[n][m] += operand;
    if(num_grid[n][m] > BASE-1) {
        numgrid_add_operation(n, m+1, num_grid[n][m]/BASE);
        num_grid[n][m] = num_grid[n][m] % BASE;
    }
}

char dec_to_base(int n) {
    if(n<10) return n + '0';
    else return n - 10 + 'A';
}

void get_order() {
    for(int i=0; i<MAXROW; ++i) {
        for(int j=0; j<MAXBUF; ++j) {
            if(count_grid[i][j] > 0) num_grid[i][j] = count_grid[i][j] * i;
            else num_grid[i][j] = 0;
        }
        for(int j=0; j<MAXBUF; ++j){
            numgrid_add_operation(i, j, 0);
        }
    }
    
    int col = MAXBUF-1;
    while(col>=0) {
        int minval = 200;
        bool flag = false;
        for(int i=0; i<BASE; ++i) {
            if(checked[i]) continue;
            else {
                if(minval > num_grid[i][col] && (num_grid[i][col] != 0 || i==0 )) {
                    minval = num_grid[i][col];
                    flag = true;
                }
            }
        }
        for(int i=0; i<BASE; ++i) {
            if(minval == num_grid[i][col]) {
                if(minval == 0 && i != 0) continue;
                sorted_ordinal.push_back(i);
                checked[i] = true;
            }
        }
        if(!flag) col -= 1;
    }
}

int main(void){
    
    for(int i=0; i<BASE; ++i) checked[i] = true;
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        string tmp;
        cin >> tmp;
        int tmplen = (int)tmp.size() - 1;
        for(int j=tmplen; j>=0; --j) {
            int alphabet = base_to_dec(tmp[j]);
            count_grid[alphabet][tmplen-j] += 1;
            checked[alphabet] = false;
        }
    }
    scanf("%d", &K);

    // 정렬
    get_order();
    
    // 정렬 체크
    // for(int i=0; i<sorted_ordinal.size();++i) {
    //     if(sorted_ordinal[i] < 10) printf("%c\n", sorted_ordinal[i] + '0');
    //     else printf("%c\n", sorted_ordinal[i]-10+'A');
    // }
    
    // 작은 순서부터 count_grid값을 Z의 값으로 올림
    for(int i=0; K>0 && i<sorted_ordinal.size(); K--, i++) {
        for(int j=0; j<MAXBUF; ++j) {
            count_grid[BASE-1][j] += count_grid[sorted_ordinal[i]][j];
            count_grid[sorted_ordinal[i]][j] = 0;
        }
    }
    
    for(int i=0; i<BASE; ++i) {
        for(int j=0;j<MAXBUF; ++j) {
            count_grid[i][j] *= i;
        }
    }
    
    for(int j=0; j<MAXBUF; ++j) {
        int colval = 0;
        for(int i=0; i<BASE; ++i) {
            colval += count_grid[i][j];
        }
        count_grid[MAXROW-1][j] = colval;
    }
    
    for(int i=0; i<MAXBUF; ++i) {
        grid_add_operation(MAXROW-1, i, 0);
    }
    
    bool flag = false;
    for(int i=MAXBUF-1; i>=0; --i) {
        if(count_grid[MAXROW-1][i] != 0) flag = true;
        if(flag) {
            printf("%c", dec_to_base(count_grid[MAXROW-1][i]));
        }
    }
    if(!flag) printf("0");
    printf("\n");
    
    return 0;
}
