#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#define INF 1234567891
using namespace std;
typedef long long int ll;

int K;
string N;
deque<string> que;

bool compare(const string& str1, const string& str2) {
    return stoi(str1) < stoi(str2);
}

string BFS(int n) {

    que.push_back(N);
    
    // K번 연산
    for (int i = 0; i < n; ++i) {
        int size = que.size();
        
        // set 자료구조를 통해서 중복되어 저장되는 경우를 막음으로써, 메모리 낭비를 막을 수 있다.
        set<string> numbers;
        
        while (size--) {
            string tmp = que.front();
            que.pop_front();
            
            for (int j = 0; j < tmp.size() - 1; ++j) {
                for (int k = j + 1; k < tmp.size(); ++k) {
                    
                    swap(tmp[j], tmp[k]);
                    if (numbers.find(tmp) == numbers.end()) {
                        numbers.insert(tmp);
                        que.push_back(tmp);
                    }
                    swap(tmp[j], tmp[k]);
                    
                }
            }
            
        }
        
    }

    return *max_element(que.begin(), que.end(), compare);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    
    if(N.size() == 1 || (N.size() == 2 && N[1] == '0')){
        cout << -1 << endl;
    }
    else{
        cout << BFS(K) << endl;
    }

    return 0;
}
