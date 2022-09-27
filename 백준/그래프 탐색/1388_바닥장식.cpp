// 그냥 그리디하게 풀어도 상관 없음
#include <iostream>
using namespace std;

char grid[55][55];
int N, M, cnt;

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        scanf("%s", grid[i]);
    }
    
    // flag : true(- | 등장) / false(가로막힘)
    bool flag=false;
    
    // row check
    for(int i=0; i<N; ++i){
        flag=false;
        for(int j=0; j<M; ++j){
            if(grid[i][j]=='-'){
                if(!flag) cnt += 1;
                flag = true;
            }
            else flag = false;
        }
    }
    
    // column check
    flag=false;
    for(int i=0; i<M; ++i){
        flag=false;
        for(int j=0; j<N; ++j){
            if(grid[j][i]=='|'){
                if(!flag) cnt += 1;
                flag = true;
            }
            else flag = false;
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
