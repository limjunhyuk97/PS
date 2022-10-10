# 좌표 압축

## 좌표 압축
- 중복하여 vector 상에 존재하는 값들을 유일하게 남긴다.
- 정렬된 상태여야만 가능하다.

```cpp
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void compressContainer(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
```
