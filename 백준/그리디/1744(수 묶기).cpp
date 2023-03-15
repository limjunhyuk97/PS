#include <iostream>
#include <queue>
using namespace std;

int N;
int result = 0, zero_cnt = 0;

priority_queue<int, vector<int>, less<int> > pq_plus;
priority_queue<int, vector<int>, greater<int> > pq_minus;

int main(void) {
    
    scanf("%d", &N);
    
    for(int i=0; i<N; ++i) {
        int tmp; scanf("%d", &tmp);
        if(tmp > 0) pq_plus.push(tmp);
        else if (tmp == 0) zero_cnt += 1;
        else pq_minus.push(tmp);
    }

    int pq_plus_cnt = (int)pq_plus.size();
    int pq_minus_cnt = (int)pq_minus.size();
    
    for(int i=0; i<pq_plus_cnt/2; ++i) {
        int n1 = pq_plus.top(); pq_plus.pop();
        int n2 = pq_plus.top(); pq_plus.pop();
        if(n1 == 1 || n2 ==1) result += n1 + n2;
        else result += n1 * n2;
    }
    
    if(!pq_plus.empty()) result += pq_plus.top();
    
    for(int i=0; i<pq_minus_cnt/2; ++i) {
        int n1 = pq_minus.top(); pq_minus.pop();
        int n2 = pq_minus.top(); pq_minus.pop();
        result += n1 * n2;
    }
    
    if(!pq_minus.empty() && zero_cnt == 0) result += pq_minus.top();
    
    printf("%d\n", result);
    
    return 0;
}
