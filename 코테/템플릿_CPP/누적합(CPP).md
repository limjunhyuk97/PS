# 누적합

<img width="400" alt="image" src="https://user-images.githubusercontent.com/59442344/201254488-1de80699-7654-4fc0-b655-9522458f04ed.png">

## 불변 구간합의 경우

- 불변 구간합은 어떤 **주어진 수의 뭉치에 대해 더 이상 누적이 일어나지 않는 경우**를 의미한다.
- 이와 같은 경우에 DP를 쓰는 이유는, 중복된 연산을 줄이기 위해서다. 즉, 특정 구간을 중복하여 더하는 연산을 여러번 하는 것을 방지하기 위해서 이다.
- **미리 특정 구간의 누적합을 구해놓는다.**

### 1차원 구간합

- **누적합** : acc[n] += acc[n-1]
- **구간합** : acc[n] 은 arr[1] + arr[2] + arr[3] + ... + arr[n] 을 이용한다.
    - arr[n] + ... arr[m] = acc[m] - acc[n-1]
- **어떤 구간의 합을 빠르게 구하기 위해서 사용**할 수 있다.

```cpp
// 초기화
acc[i] += acc[i-1];

// 부분 면적의 값
acc[i] - acc[j-1]
```

### 2차원 구간합

- **누적합** : acc[n][m] = acc[n-1][m] + acc[n][m-1] - acc[n-1][m-1] + arr[n][m]
    - acc[n-1][m] : 위쪽 직사각형 면적
    - acc[n][m-1] : 왼쪽 직사각형 면적
    - acc[n-1][m-1] : 두번 빠지는 부분의 면적
    - arr[n][m] : 현재 격자 속 값
- **구간합** : (x1,y1) ~ (x2,y2) 의 면적이 얼마인가?
    - acc[x2][y2] - acc[x2][y1-1] - acc[x1-1][y2] + acc[x1-1][y1-1]
- **어떤 격자 면적의 합을 빠르게 구하기 위해서 사용**할 수 있다.

```cpp
// 초기화
grid[i][j] = grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1] + grid[i][j]

// 부분 면적 값
grid[x2][y2] - grid[x2][y1-1] - grid[x1-1][y2] + grid[x1-1][y1-1]
```

## 가변 누적합의 경우

- 가변 누적합은 어떤 **주어진 수의 뭉치에 대해 값의 누적이 일어나는 경우**를 의미한다.
- 값의 변경이 일어나기 때문에 구간의 값, 구간에서의 최대 최소 값 등을 빠르게 구하기 위해서 **구간합의 변경을 추적할 수 있는 방법이 필요**하다.

### 누적의 누적합

- 마지막에 누적 결과 한번만 확인하면 되는 경우 유리하다.
- **값의 변경을 일으키는 누적값들을 누적시켜 둔다. 후에, 이 누적된 누적값들에 대한 누적합을 한번에 구해서 연산의 중복을 방지**한다.
    - **부분적인 연속 구간의 갱신 O / 기존 배열 갱신 X**
    - 값을 추출할 때 연산을 수행한다.
- 말로 풀어쓰기 어려워서 누적의 누적합이라 부르기로 했다.

<img width="799" alt="image" src="https://user-images.githubusercontent.com/59442344/201331779-75d174a7-bdf5-4fb9-9a25-78ae87048a6b.png">

  
### 세그먼트 트리

- 일반적으로 **구간에 대한 연산을 빠르게 수행할 수 있게 해준다.**
- 누적 + 결과확인을 계속 해줘야 하는 경우 유리하다.
- **누적의 영향이 적용되어야 하는 모든 부분적인 연속 구간들에 대해 누적을 적용**시킨다.
    - **부분적인 연속구간의 갱신 X / 기존 배열 갱신 O**
    - 값을 추출할때 별다른 연산이 필요없다.
- 다양한 경우에 범용적으로 적용시킬 수 있다.
- 중요한 것은 세그트리의 구조와 원리를 이해하는 것이다.
    
```cpp
class SegmentTree {
private:
    int n;
    vector<ll> tree;
public:
    // SegmentTree 클래스 객체 생성자
    SegmentTree(int n) : n(n) {
        tree = vector<ll> (n*4+6, 0);
    }
    
    // 기존 배열로 세그먼트 트리 초기화
    void init(int idx, ll value, int node, int nodeLeft, int nodeRight) {
        if(idx < nodeLeft || nodeRight < idx) return;
        if(nodeLeft == nodeRight) {
            tree[node] = value;
            return;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        init(idx, value, node*2, nodeLeft, mid);
        init(idx, value, node*2+1, mid+1, nodeRight);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    // 특정 구간에 값 더하기
    void acc_range(int idxLeft, int idxRight, ll value, int node, int nodeLeft, int nodeRight) {
        if(idxRight < nodeLeft || nodeRight < idxLeft) return;
        if(idxLeft <= nodeLeft && nodeRight <= idxRight) {
            tree[node] += value;
            return;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        acc_range(idxLeft, idxRight, value, node*2, nodeLeft, mid);
        acc_range(idxLeft, idxRight, value, node*2+1, mid+1, nodeRight);
    }
    
    // 특정 지점의 값 변경 후 갱신하기
    void set_point(int idx, ll value, int node, int nodeLeft, int nodeRight) {
        if(idx < nodeLeft || nodeRight < idx) return;
        if(nodeLeft == nodeRight) {
            tree[node] = value;
            return;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        set_point(idx, value, node*2, nodeLeft, mid);
        set_point(idx, value, node*2+1, mid+1, nodeRight);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    // 특정 구간합 도출하기
    ll get_sum(int idxLeft, int idxRight, int node, int nodeLeft, int nodeRight) {
        if(idxRight < nodeLeft || nodeRight < idxLeft) return 0;
        if(idxLeft <= nodeLeft && nodeRight <= idxRight) return tree[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        return get_sum(idxLeft, idxRight, 2*node, nodeLeft, mid) + get_sum(idxLeft, idxRight, 2*node+1, mid+1, nodeRight);
    }
};
```

### 펜윅 트리

- 세그먼트 트리에 비해 간결하게 구간에 대한 연산을 진행할 수 있게 해준다.
