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
#include <bitset>
#include <cmath>
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int N, n, g1, g2 ,g3;

struct player{
    int number;
    int grade1;
    int grade2;
    int grade3;
    bool operator<(const player &other) const{
        if(grade1 * grade2 * grade3 == other.grade1 * other.grade2 * other.grade3){
            if(grade1 + grade2 + grade3 == other.grade1 + other.grade2 + other.grade3){
                return number < other.number;
            }
            return grade1 + grade2 + grade3 < other.grade1 + other.grade2 + other.grade3;
        }
        return grade1 * grade2 * grade3 < other.grade1 * other.grade2 * other.grade3;
    }
};

vector<player> players;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i =0; i<N; ++i){
        cin >> n >> g1 >> g2 >> g3;
        players.push_back({n, g1, g2, g3});
    }
    
    sort(players.begin(), players.end());
    
    cout << players[0].number << " " << players[1].number << " " << players[2].number << endl;
 
    return 0;
}
