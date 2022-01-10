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

int N, r, c;

// i행, j열
int find_ordinal(int i, int j, int l){
    if(l==0) return 1;
    
    int len = (int)pow((double)2, (double)l);
    int len_square = (len/2) * (len/2);
    if(((i + len/2) > r) && ((j + len/2) > c)){
        return find_ordinal(i, j, l-1);
    }
    else if(((i + len/2) > r) && ((j + len/2) <= c)){
        return len_square + find_ordinal(i, j + len/2, l-1);
    }
    else if(((i + len/2) <= r) && ((j + len/2) > c)){
        return len_square * 2 + find_ordinal(i + len/2, j, l-1);
    }
    else{
        return len_square * 3 + find_ordinal(i + len/2, j + len/2, l-1);
    }
}

int main(void){
    
    scanf("%d %d %d", &N, &r, &c);
    
    if(N == 0) printf("1\n");
    else printf("%d\n", find_ordinal(0, 0, N) - 1);
    
    return 0;
}
