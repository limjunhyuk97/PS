// 큐브 돌리는 개같은 문제 시도중
#include <iostream>
#include <string>
using namespace std;

int T, n;

// 0:w  1:y  2:h  3:o  4:g  5:b
char cube[6][3][3];

int faceToIndex(char face) {
    if(face == 'U') return 0;
    else if(face == 'D') return 1;
    else if(face == 'F') return 2;
    else if(face == 'B') return 3;
    else if(face == 'L') return 4;
    else return 5;
}

void initCube() {
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            cube[0][i][j] = 'w';
            cube[1][i][j] = 'y';
            cube[2][i][j] = 'r';
            cube[3][i][j] = 'o';
            cube[4][i][j] = 'g';
            cube[0][i][j] = 'b';
        }
    }
}

void printU() {
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            printf("%c", cube[0][i][j]);
        }
        printf("\n");
    }
}

void face_clockwise(char face) {
    int index = faceToIndex(face);
    int tmp = cube[index][0][0];
    for(int i=1; i<3; ++i) cube[index][i-1][0] = cube[index][i][0];
    for(int i=1; i<3; ++i) cube[index][2][i-1] = cube[index][2][i];
    for(int i=1; i>=0; --i) cube[index][i+1][2] = cube[index][i][2];
    cube[index][0][2] = cube[index][0][1]; cube[index][0][1] = tmp;
}

void face_anticlockwise(char face) {
    int index = faceToIndex(face);
    int tmp = cube[index][0][0];
    for(int i=1; i<3; ++i) cube[index][0][i-1] = cube[index][0][i];
    for(int i=1; i<3; ++i) cube[index][i-1][2] = cube[index][i][2];
    for(int i=1; i>=0; --i) cube[index][2][i+1] = cube[index][2][i];
    cube[index][2][0] = cube[index][1][0]; cube[index][1][0] = tmp;
}

void side_clockwise(char face) {
    switch(face) {
        case 'B' :
            
            
            break;
            
        case 'D':
            break;
            
        case 'U' :
            break;
            
        case 'L':
            break;
            
        case 'U':
            break;
            
        case 'F':
            break;
    }
}

void side_anticlockwise(char face) {
    
}

// 바라보는 방향 기준 - : 반시계 , + : 시계
void rotate(char face, char clock) {
    if(clock == '+') {
        face_clockwise(face);
        side_clockwise(face);
    } else {
        face_anticlockwise(face);
        side_anticlockwise(face);
    }
}

int main(void) {
    
    scanf("%d", &T);
    
    for(int t=0; t<T; ++t) {
        initCube();
        
        scanf("%d", &n);
        
        // cin으로 여러개의 문자들을 띄어서 입력받을 수 있다.
        for(int i=0; i<n; ++i) {
            string cmd; cin >> cmd;
            rotate(cmd[0], cmd[1]);
        }
        
        printU();
    }
    
    return 0;
}
