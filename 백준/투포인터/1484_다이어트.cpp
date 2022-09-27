// G(kg) = cur^2 - mem (cur > mem)
// 가능한 cur 를 모두 구해라
// 접근방식
//  - 제곱수를 미리 다 생성해 둔다.
//  - 두개의 포인터를 사용하여 p0, p1의 간격을 벌려가며
//      - 간격이 특정 수준 이상으로 벌어지면 : p1을 움직이고
//      - 간격이 특정 수준이라면 : 답에 추가하고
//      - 간격이 특정 수준 이하로 벌어지면 : p0을 움직인다
//      - 결국 특정 조건에 부합하는 구간을 찾기 위해서 두개의 포인터를 이동시키며 구한다.

#include <iostream>
#include <vector>
#include <utility>
#define BUFLEN 50005
using namespace std;

typedef long long int ll;

int G;
ll fat[BUFLEN];
int p0=BUFLEN-3, p1=BUFLEN-2;

vector<int> cur_fat;

int main(void) {
    
    // get G
    scanf("%d", &G);
    
    // initialize : fat에 내림차순으로 제곱수 들어가있음
    for(int i=1; i<BUFLEN; ++i){
        fat[BUFLEN - i - 1] = (ll)i*i;
    }
    
    while(p0 > 1) {
        if(fat[p0] - fat[p1] > G) p1 -= 1;
        else if(fat[p0] - fat[p1] == G) {
            cur_fat.push_back(BUFLEN - p0 - 1);
            p0 -= 1;
        }
        else p0 -= 1;
    }
    
    if(cur_fat.empty()) cur_fat.push_back(-1);
    for(int i=0; i<cur_fat.size(); ++i)
        printf("%d\n", cur_fat[i]);
    
    return 0;
}

