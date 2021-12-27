# 트리의 순회

### Divide and Conquer를 통해 해결
  - 가장 작은 단위로 divide
  - divide된 것들을 조합하는 과정에서 conquer한다.

### 쪼갤 수 있는가?
  - 트리의 순회는 root를 기준으로 root를 먼저 고려할 것인지, 중간에 고려할 것인지, 나중에 고려할 것인지로 나눠진다.
  - 연산이 수행되는 방식, tree의 정의를 고려해 봤을 때, root 노드를 기준으로 좌-우 subtree들이 고려되고, 각 subtree에서도 재귀적으로 반복된다.

### 쪼갤 수 있다면, 어떻게 Divide할 것인가?
  - root를 기준으로 divide 한다.

### Root를 어떻게 찾을 것인가?
  - postOrder의 가장 오른쪽에 root가 존재한다.

### Left, Right Sub-Tree를 어떻게 찾을 것인가?
  - preOrder에 위치한 root의 왼쪽, 오른쪽이 각각 left, right subtree일 것이다.

### 어떻게 Conquer할 것인가?
  - 굳이 tree를 생성하지 않아도, root-left-right로 순서를 재조직하면 된다.
  - 배열을 이용하거나, vector container를 이용한다.
