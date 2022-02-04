// i번쨰 일을 처리 - Ti 시간이 걸리고, Si 시간 내에 일을 처리해야 한다.
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct prop{
    int Ti;
    int Si;
    bool operator<(const prop &other) const{
        if(Si != other.Si) return Si > other.Si;
        else return Ti < other.Ti;
    }
}prop;

int N, cp=1000010;
vector<prop> vec;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        int ti, si; scanf("%d %d", &ti, &si);
        vec.push_back({.Ti=ti, .Si=si});
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i=0; i<N; ++i){
        if(vec[i].Si<cp) cp = vec[i].Si;
        cp -= vec[i].Ti;
        if(cp<0){
            cp = -1;
            break;
        }
    }
    
    printf("%d\n", cp);
    
    return 0;
}
