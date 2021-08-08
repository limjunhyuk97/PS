// 3


#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

string input, code;
const char alphabet[27] = {"abcdefghijklmnopqrstuvwxyz"};

char incoding(char target, char c){
    if(target == ' ') return ' ';
    
    if( target - c - 1 < 0){
        return alphabet[26 + (target - c - 1)];
    }
    else{
        return alphabet[target - c - 1];
    }
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getline(cin, input);
    cin >> code;
    
    for(int i = 0; i < input.size(); ++i){
        cout << incoding(input[i], code[i % code.size()]);
    }
    cout << "\n";
    
    return 0;
}
