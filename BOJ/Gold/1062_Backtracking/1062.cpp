#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
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

int N, K, res = 0;
char strings[55][20];
bool alphabet_arr[30];
const char always[5] = {'a', 'n', 't', 'i', 'c'};

int readwords(){
    int sum = 0;
    for(int i=0; i<N; ++i){
        int str_length = (int)strlen(strings[i]);
        for(int j=0; j<str_length; ++j){
            if(!alphabet_arr[strings[i][j] - 'a']) {
                sum -=1;
                break;
            }
        }
        sum += 1;
    }
    return sum;
}

void DFS(int n, int cnt){
    if(cnt == K - 5){
        int tmp = readwords();
        res = (res > tmp ? res : tmp);
        return;
    }
    
    for(int i=n; i<26-(K-6-cnt); ++i){
        if(alphabet_arr[i]) continue;
        alphabet_arr[i] = true;
        DFS(i+1, cnt+1);
        alphabet_arr[i] = false;
    }
}

int main(void){
    
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; ++i) scanf("%s", strings[i]);
    
    // 무조건 가능한 경우와 불가능 한 경우에 대한 예외 처리
    if(K == 26) {
        printf("%d\n", N);
        return 0;
    }
    else if(K < 5) {
        printf("0\n");
        return 0;
    }
    
    // a, n, t, i, c 항상 주어짐
    for(int i=0; i<5; ++i) alphabet_arr[always[i]-'a'] = true;
    
    DFS(0, 0);
    
    printf("%d\n", res);
    
    return 0;
}

/*
 50 15
 antarctica
 antahellotica
 antacafsdrtica
 antarngjocbtica
 antarnfzojctica
 antarnaffuctica
 antarnaapoctica
 antarnapgoctica
 antardsfjoctica
 antanapgoctica
 antaafsdrctica
 antarjhgctica
 antarfjhctica
 antarfbncttica
 antarrtctica
 antarbetrectica
 antarqreufctica
 antarrectica
 antarqfjectica
 antarafjtica
 antarqvawectica
 antarqofwyctica
 antarvnfjctica
 antarqovaeutica
 antareufjectica
 antarqefjtica
 antarqefjectica
 antaructica
 antarqafdoctica
 antarqictica
 antarqerjictica
 antarqoeictica
 antarqeeictica
 antarbroctica
 antarbuyuoctica
 antarbvuroctica
 antarbiuyyctica
 antarbdsfhctica
 antarbquroctica
 antarinfjctica
 antarirjectica
 antariqwctica
 antariwyectica
 antarigsdvctica
 antarijectica
 antarqegafdtica
 antarqctica
 antarqgoeictica
 antarqtqtoetica
 antarqnuyectica
 30
 */
