// --> input
const submission = "/dev/stdin";
const testcase = "./testcase.txt";
let fs = require("fs");
const input = fs
  .readFileSync(submission)
  .toString()
  .trim()
  .split("\n")
  .map((el) => Number(el));
// <-- input

class PriorityQueue {
  constructor(n, comp) {
    this.heap = Array.from({ length: n }, (_) => 0);
    this.numOfData = 0;
    this.compare = comp;
  }

  getLChildIdx(n) {
    return 2 * n;
  }

  getRChildIdx(n) {
    return 2 * n + 1;
  }

  // 0보다 크면 왼쪽이 우선순위 큰것. 0보다 작으면 오른쪽이 우선순위 큰 것.
  getHiPriChildIdx(n) {
    const left = this.getLChildIdx(n);
    const right = this.getRChildIdx(n);
    if (left > this.numOfData) return 0;
    else if (left === this.numOfData) return left;
    else
      return this.compare(this.heap[left], this.heap[right]) > 0 ? left : right;
  }

  getParentIdx(n) {
    return Math.floor(n / 2);
  }

  isEmpty() {
    return this.numOfData === 0;
  }

  push(value) {
    let idx = ++this.numOfData;
    while (idx > 1) {
      const pIdx = this.getParentIdx(idx);
      if (this.compare(value, this.heap[pIdx]) > 0) {
        this.heap[idx] = this.heap[pIdx];
        idx = pIdx;
      } else break;
    }
    this.heap[idx] = value;
  }

  pop() {
    const result = this.heap[1];
    const lastEl = this.heap[this.numOfData--];

    let pIdx = 1;
    let cIdx;

    while ((cIdx = this.getHiPriChildIdx(pIdx))) {
      if (this.compare(this.heap[cIdx], lastEl) > 0) {
        this.heap[pIdx] = this.heap[cIdx];
        pIdx = cIdx;
      } else break;
    }

    this.heap[pIdx] = lastEl;

    return result;
  }
}

const N = input[0];
const arr = input.slice(1);

const PQ = new PriorityQueue(N + 3, (a, b) => b - a);
arr.forEach((el) => {
  PQ.push(el);
});

let answer = 0;

while (true) {
  const i = PQ.pop();
  if (PQ.isEmpty()) {
    console.log(answer);
    break;
  }
  const j = PQ.pop();
  PQ.push(i + j);
  answer += i + j;
}
