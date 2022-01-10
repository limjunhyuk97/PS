#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v[100001];
int infe[100001];
int init[100001];
int last[100001];
// last : 입력받은 결과
// infe : 시뮬레이션 결과
// init : 초기상태

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> infe[i];
        last[i] = infe[i];
        init[i] = infe[i];
    }
    
    
    
    for (int i = m - 1; i > -1; i--) {
        int no = 0;
        for (auto user : v[i]) {
            if (infe[user] == 0) {
                no = 1;
                break;
            }
        }
        if (no) {
            for (auto user : v[i]) {
                init[user] = 0;
                infe[user] = 0;
            }
        }
    }

    
    
    for (int i = 0; i < m; i++) {
        int yes = 0;
        for (auto user : v[i]) {
            if (infe[user]) {
                yes = 1;
            }
        }
        if (yes) {
            for (auto user : v[i]) {
                infe[user] = 1;
            }
        }
    }
    
    
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        if (infe[i] != last[i]) {
            flag = 0;
        }
    }
    if (flag) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << init[i] << " ";
        }
    }
    else {
        cout << "NO";
    }
}
