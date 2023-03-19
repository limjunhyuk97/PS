#include <iostream>
#include <vector>
#define MAXLEN 105
using namespace std;

int N, L;
int arr[MAXLEN][MAXLEN];
bool slops[MAXLEN][MAXLEN];

void read_slops(int pos, char c, bool rep[]) {
    if(c == 'r') {
        for(int i=0; i<N; ++i) {
            rep[i] = slops[pos][i];
        }
    }
    else {
        for(int i=0; i<N; ++i) {
            rep[i] = slops[i][pos];
        }
    }
}

void write_slops(int pos, char c, bool rep[]) {
    if(c == 'r') {
        for(int i=0; i<N; ++i) {
            slops[pos][i] = rep[i];
        }
    }
    else {
        for(int i=0; i<N; ++i) {
            slops[i][pos] = rep[i];
        }
    }
}

// 길이 벗어난 경우
bool OOB_ADD(int head) {
    if(head + L - 1 < N) return false;
    else return true;
}

bool OOB_MIN(int head) {
    if(head - L < 0) return true;
    else return false;
}

// 행으로 살펴보기
bool seek_row(int row) {
    int cur = arr[row][0];
    bool flag = true;
    
    // slop 정보 복사
    vector<bool> slop(N+2, false);
    // read_slops(row, 'r', slop);
    
    // 좌에서 우로 살펴보기
    for(int head=1; head<N; ++head) {
        // 다음 높이가 동일
        if(arr[row][head] == cur) continue;
        // 다음 높이가 1 낮아짐
        else if(arr[row][head] == cur-1) {
            // 가로 길이 벗어나는 경우
            if(OOB_ADD(head)) {
                flag = false;
                break;
            }
            // slop 놓인 적 있거나, cur-1이 아닌 것 있는지 여부 확인
            for(int j=head; j<head+L; ++j) {
                if(arr[row][j] != cur-1 || slop[j]) {
                    flag = false;
                    break;
                }
                else slop[j] = true;
            }
            // 없다면 head와 cur 갱신
            head += L-1;
            cur = cur-1;
        }
        // 다음 높이가 1 높아짐
        else if(arr[row][head] == cur+1) {
            // 가로 길이 벗어나는 경우
            if(OOB_MIN(head)) {
                flag = false;
                break;
            }
            // slop 놓인 적 있거나, cur+1이 아닌 것 있는지 여부 확인
            for(int j = head-1; j>=head-L; --j) {
                if(arr[row][j] != cur || slop[j]) {
                    flag = false;
                    break;
                }
                else slop[j] = true;
            }
            // 없다면 head와 cur 갱신
            cur += 1;
        }
        // 다음 높이가 2이상 차이남
        else {
            flag = false;
            break;
        }
    }
    
    // 가능하다면 slop 갱신
    // if(flag) write_slops(row, 'r', slop);
    
    return flag;
}

// 열로 살펴보기
bool seek_col(int col) {
    int cur = arr[0][col];
    bool flag = true;
    
    // slop 정보 복사
    vector<bool> slop(N+2, false);
    // read_slops(col, 'c', slop);
    
    // 좌에서 우로 살펴보기
    for(int head=1; head<N; ++head) {
        // 다음 높이가 동일
        if(arr[head][col] == cur) continue;
        // 다음 높이가 1 낮아짐
        else if(arr[head][col] == cur-1) {
            // 가로 길이 벗어나는 경우
            if(OOB_ADD(head)) {
                flag = false;
                break;
            }
            // slop 놓인 적 있거나, cur-1이 아닌 것 있는지 여부 확인
            for(int j=head; j<head+L; ++j) {
                if(arr[j][col] != cur-1 || slop[j]) {
                    flag = false;
                    break;
                }
                else slop[j] = true;
            }
            // 없다면 head와 cur 갱신
            head += L-1;
            cur = cur-1;
        }
        // 다음 높이가 1 높아짐
        else if(arr[head][col] == cur+1) {
            // 가로 길이 벗어나는 경우
            if(OOB_MIN(head)) {
                flag = false;
                break;
            }
            // slop 놓인 적 있거나, cur+1이 아닌 것 있는지 여부 확인
            for(int j = head-1; j>=head-L; --j) {
                if(arr[j][col] != cur || slop[j]) {
                    flag = false;
                    break;
                }
                else slop[j] = true;
            }
            // 없다면 head와 cur 갱신
            cur += 1;
        }
        // 다음 높이가 2이상 차이남
        else {
            flag = false;
            break;
        }
    }
    
    // 가능하다면 slop 갱신
    // if(flag) write_slops(col, 'c', slop);
    
    return flag;
}

// 전체 가능한 행.열
int roads;

int main(void) {
    
    scanf("%d %d", &N, &L);
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i=0; i<N; ++i) {
        if(seek_row(i)) roads += 1;
    }
    
    for(int i=0; i<N; ++i) {
        if(seek_col(i)) roads += 1;
    }
    
    printf("%d\n", roads);
    
    return 0;
}
