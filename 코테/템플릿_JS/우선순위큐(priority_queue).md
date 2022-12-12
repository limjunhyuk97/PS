# 우선순위 큐 (priority queue)

- max heap, min heap을 기반으로 구현한다.

## 우선순위 큐

```js
// 우선순위큐 구현.
// 우선순위는 루트가 제일 크다.

class PriorityQueue {
  // 배열 형태의 heap
  #heap = Array.from({ length: 0 });

  // 우선순위 큐 내 원소의 갯수
  #numOfData = 0;

  // 부모 노드 찾기
  #getP = (idx) => Math.floor(idx / 2);

  // 좌측 자식 노드 찾기
  #getL = (idx) => idx * 2;

  // 우측 자식 노드 찾기
  #getR = (idx) => idx * 2 + 1;

  // 우선순위가 높은 자식 노드 찾기
  // 우선순위는 (a, b) 에서 a가 더 크면 양수. b가 더 크면 음수.
  #getH = (idx) => {
    const LChild = this.#getL(idx);
    const RChild = this.#getR(idx);
    if (LChild < this.numOfData) return 0;
    else if (LChild === this.numOfData) return LChild;
    else
      return this.comp(this.#heap[LChild], this.#heap[RChild]) > 0
        ? LChild
        : RChild;
  };

  // compare(비교 함수)를 전달받는다.
  constructor(comp) {
    this.comp = comp;
  }

  // 우선순위큐가 비어있는 경우 true를 반환한다.
  isEmpty() {
    return this.#numOfData === 0;
  }

  // value(자식)이 더 우선순위가 높으면 부모 자식을 바꿔나간다.
  push(value) {
    let idx = ++this.#numOfData;
    this.#heap[idx] = value;

    while (idx > 1) {
      const pIdx = this.#getP(idx);
      if (this.comp(value, this.#heap[pIdx]) > 0) {
        this.#heap[idx] = this.#heap[pIdx];
        idx = pIdx;
      } else break;
    }

    this.#heap[idx] = value;
  }

  // value(자식)이 더 우선순위가 높으면 부모 자식을 바꿔나간다.
  pop() {
    // 루트 노드를 밖으로 빼버리고, 맨 뒤에 있던 값을 부모 노드에 올린다. -> 그리고 재정렬을 수행한다.
    const topEl = this.#heap[1];
    const lastEl = this.#heap[this.#numOfData];

    let pIdx = 1;
    let cIdx;

    while ((cIdx = this.#getH(pIdx))) {
      if (this.comp(this.#heap[cIdx], lastEl) > 0) {
        this.#heap[pIdx] = this.#heap[cIdx];
        pIdx = cIdx;
      } else break;
    }

    this.#heap[pIdx] = lastEl;
    this.#numOfData -= 1;

    return topEl;
  }

  // 루트 노드의 값을 반환한다.
  top() {
    return this.#heap[1];
  }
}
```
