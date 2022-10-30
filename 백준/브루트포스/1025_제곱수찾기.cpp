// 로직 상에서의 문제 찾는데 시간 오래 걸림
// : '640'이라는 문자열이 찾아지더라도, 그 안에서 64를 또 추출할 수 있어야 함..!

#include <iostream>
#include <string>
using namespace std;

int N, M, max_result = -1;
string grid[12];

bool OOB(int x, int y) {
    if(x<0 || x>=N || y<0 || y >= M) return true;
    return false;
}

void getMax(string target) {
    int size = (int)target.size();
    // 640 으로 문자열이 찍혔더라도, 64가 제곱수인거 감안해야 함.
    for(int i=size; i>0; --i) {
        int num = stoi(target.substr(0, i));
        for(int j=0; j*j<=num; ++j) {
            if(j*j == num) {
                max_result = max_result < num ? num : max_result;
                return;
            }
        }
    }
    return;
}

string DFS(int x, int y, int i, int j) {
    if(OOB(x,y)) return "";
    string str(1, grid[x][y]);
    if(i==0 && j==0) return str;
    return str + DFS(x+i, y+j, i, j);
}

int main(void) {
    
    cin >> N >> M;
    for(int i=0; i<N; ++i) {
        cin >> grid[i];
    }
    
    for(int i=-8; i<9; ++i) {
        for(int j=-8; j<9; ++j) {
            for(int x=0; x<N; ++x) {
                for(int y=0; y<M; ++y) {
                    string str = DFS(x, y, i, j);
                    if(!str.empty()) {
                        getMax(str);
                    }
                }
            }
        }
    }
    
    cout << max_result << endl;
    
    return 0;
}
