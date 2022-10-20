// 행렬을 돌리는 방식 : 수식으로 표현할 수 있음. 안보이면 손으로 그려서 나타내봐라.

#include <iostream>
#include <algorithm>
#define MAX_STICKER_SIZE 12
using namespace std;

int N, M, K;
int grid[43][43];
int sticker[MAX_STICKER_SIZE][MAX_STICKER_SIZE];

// 스티커 붙은 칸수 세기
int count_sticker() {
    int cnt = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(grid[i][j]) cnt += 1;
        }
    }
    return cnt;
}

// 스티커 돌리기
void rotate_sticker(int &row, int &col) {
    swap(row, col);
    // sticker 행렬 돌리기
    int tmp[MAX_STICKER_SIZE][MAX_STICKER_SIZE];
    for(int i=0; i<MAX_STICKER_SIZE; ++i) {
        for(int j=0; j<MAX_STICKER_SIZE; ++j) {
            tmp[j][MAX_STICKER_SIZE-i-1] = sticker[i][j];
            if(sticker[i][j]) sticker[i][j] = 0;
        }
    }
    // sticker 행렬을 0,0 기준에 맞추기
    for(int i=0; i<MAX_STICKER_SIZE; ++i) {
        for(int j=MAX_STICKER_SIZE-col; j<MAX_STICKER_SIZE; ++j) {
            sticker[i][j-MAX_STICKER_SIZE + col] = tmp[i][j];
        }
    }
}

// 스티커 붙이기
bool paste_sticker (int row, int col) {
    // 감당 불가능한 스티커 사이즈
    if(N < row || M < col) return false;
    // 스티커 왼쪽위부터 붙일 수 있는지 확인
    bool result = false;
    for(int i=0; i<N-row+1; ++i) {
        for(int j=0; j<M-col+1; ++j) {
            // 붙일수 있는지 확인
            bool canStickFlag = true;
            for(int k=0; k<row; ++k) {
                for(int l=0; l<col; ++l) {
                    if(sticker[k][l]==1 && grid[i+k][j+l]==1) {
                        canStickFlag = false;
                        break;
                    }
                }
                if(!canStickFlag) break;
            }
            // 붙일수 있다면 붙인다.
            if(canStickFlag) {
                for(int k=0; k<row; ++k) {
                    for(int l=0; l<col; ++l) {
                        if(sticker[k][l]==1) {
                            grid[i+k][j+l] = 1;
                        }
                    }
                }
                result = true;
                break;
            }
        }
        if(result) break;
    }
    
    return result;
}

int main(void) {
    
    cin >> N >> M >> K;
    for(int i=0; i<K; ++i) {
        // 스티커 초기화
        for(int j=0; j<MAX_STICKER_SIZE; ++j) {
            for(int k=0; k<MAX_STICKER_SIZE; ++k) {
                sticker[j][k] = 0;
            }
        }
        // 스티커 입력
        int Ri, Ci; cin >> Ri >> Ci;
        for(int j=0; j<Ri; ++j) {
            for(int k=0; k<Ci; ++k) {
                scanf("%d", &sticker[j][k]);
            }
        }
        // 가능하면 스티커 붙히기
        for(int j=0; j<4; ++j) {
            if(paste_sticker(Ri, Ci)) break;
            rotate_sticker(Ri, Ci);
        }
    }
    
    // 스티커 붙은 수 출력
    cout << count_sticker() << endl;
    
    return 0;
}
