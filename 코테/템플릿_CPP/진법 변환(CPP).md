# 진법 변환

## 10진법 -> n진법

```
#include <deque>

// 진법 변환
void conversion(deque<int> & dq, ll num, ll dest) {
    while(num) {
        dq.push_front((int)(num % dest));
        num /= dest;
    }
}

```
