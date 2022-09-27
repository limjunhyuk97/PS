// Greedy : 단계별 최선의 선택 -> 가능성 확인 -> solution 인지 확인
// 반대이면, 요소들 그냥 되는대로 다 뒤집어 주면 됨

#include <iostream>
using namespace std;

int N, M, tmp, flip_cnt;

char before[52][52], after[52][52];
int dx[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int dy[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

// 뒤집기
void flip(int n, int m){
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            if(before[n+dx[i]][m+dy[j]] == '1') before[n+dx[i]][m+dy[j]] = '0';
            else before[n+dx[i]][m+dy[j]] = '1';
        }
    }
}

int main(){
    
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N ; ++i){
        scanf("%s", before[i]);
    }
    for(int i=0; i<N; ++i){
        scanf("%s", after[i]);
    }
    
    if(N<3 || M<3){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(before[i][j] != after[i][j]){
                    printf("-1\n");
                    return 0;
                }
            }
        }
        printf("0\n");
        return 0;
    }
    
    for(int i=0; i+2<N; ++i){
        for(int j=0; j+2<M; ++j){
            if(before[i][j] != after[i][j]){
                flip(i, j);
                flip_cnt += 1;
            }
        }
    }
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(before[i][j] != after[i][j]){
                printf("-1\n");
                return 0;
            }
        }
    }
    
    printf("%d\n", flip_cnt);
    
    return 0;
}
