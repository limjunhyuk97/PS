// 놓친 것
// - 뒤에서부터 앞으로 갔어야 했다. (멤버쉽 계산의 기준이 무엇인가?)
// - 문제 똑바로 읽자. (다이아몬드 '등급의 계산'은 다이아몬드 기준액 '이상' 이고, '과금의 한도'는 다이아몬드 기준액 까지이다.)
// greedy, dp 떠올린 것 잘했음.

#include <iostream>
#include <string>
#include <map>
using namespace std;

int sum, max_sum;
map< char, int > constraint;
int n, s, g, p, d;
string str;
int DP[40];

int main(void){
    
    cin >> n;
    cin >> s >> g >> p >> d;
    cin >> str;
    
    constraint.insert({'B', s - 1});
    constraint.insert({'S', g - 1});
    constraint.insert({'G', p - 1});
    constraint.insert({'P', d - 1});
    constraint.insert({'D', d});
    

    int last_one = constraint[str[n - 1]];
    for(int j=0; j<=last_one; ++j){
        DP[n-1] = j;
        for(int i= n - 2; i>=0; --i){
            if(str[i+1] == 'D') DP[i] = constraint[str[i]];
            else if(constraint[str[i+1]] - DP[i+1] <= constraint[str[i]]) DP[i] = constraint[str[i+1]] - DP[i+1];
            else DP[i] = constraint[str[i]];
        }
        sum = 0;
        for(int i = 0; i < n; ++i){
            sum += DP[i];
        }
        if(sum > max_sum) max_sum = sum;
    }
    
    cout << max_sum << endl;
    
    return 0;
}
