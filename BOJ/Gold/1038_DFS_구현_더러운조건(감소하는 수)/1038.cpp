#include <iostream>
using namespace std;

typedef long long int ll;
ll DP[13][13] = {{0, }, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  };
ll N;
string ans = "";

bool make_string(int len, int biggest){
    if(len == 0){
        N--;
        if (N == 0 ) return true;
        else return false;
    }   
    for(int i=0; i<=biggest; ++i){
        if (ans.size() == 0 && i ==0) continue;
        ans += to_string(i);
        if(make_string(len-1, i - 1)) return true;
        ans.pop_back();
    }
    return false;
}

int main(void){
    
    cin >> N;
    
    // 11 col : row_total
    ll total_sum = 0, row_sum =0;
    for(int i=1; i<=10; ++i){
        row_sum = 0;
        for(int j=1; j<=10 ; ++j){
            for(int k=0; k<j; ++k){
                DP[i][j] += DP[i-1][k];
            }
            row_sum += DP[i][j];
        }
        DP[i][11] = row_sum;
        total_sum += row_sum;
    }
    
    if (total_sum - 1 < N){
        cout << - 1 << endl;
        return 0;
    }
    
    if (N < 10){
        cout << N << endl;
        return 0;
    }
    
    N -= 9;
    int string_length = 0;
    for(int i = 2; i<=10; ++i){
        if(N <= DP[i][11]) {
            string_length = i; break;
        }
        N -= DP[i][11];
    }
    
    // string_length length string, Nth
    make_string(string_length, 9);
    cout << ans << endl;

    return 0;
}
