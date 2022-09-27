//***********************************/
//** 제출용 입력 경로 */
const submission = "/dev/stdin";

//** 테스트용 입력 경로 */
const testcase = "./testcase.txt";

//** fs 모듈 import */
let fs = require("fs");
//***********************************/

const input = fs.readFileSync(submission).toString().split("\n");
const N = Number(input[0]);
const board = input.slice(1);

// 후보 생성
const candidates = {};
for (let i = 0; i < N; ++i) {
  candidates[i] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
}

// # 있으면 안되는 경우만 빼기
const nonAvailableSharp = {
  0: [1],
  1: [1, 4],
  2: [],
  3: [1, 2, 3, 7],
  4: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
  5: [5, 6],
  6: [1, 7],
  7: [0, 1, 7],
  8: [],
  9: [1, 3, 4, 5, 7, 9],
  10: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
  11: [2],
  12: [1, 4, 7],
  13: [1, 4, 7],
  14: [],
};

// 0 ~ 14까지의 점자 위치 중 어디
let pos = 0;

// 후보에서 제거
board.forEach((el) => {
  // 중간 . 제거
  let count = 1;
  // 몇번째 수
  let cur = 0;
  el.split("").forEach((el) => {
    if (count > 3) {
      pos -= 3;
      count = 1;
      cur += 1;
      return;
    }
    if (el === "#") {
      nonAvailableSharp[pos].forEach((el) => {
        candidates[cur] = candidates[cur].filter((num) => num !== el);
      });
    }
    count += 1;
    pos += 1;
  });
});

let sum = 0;
let count = 1;

Object.keys(candidates).forEach((i) => {
  let tmpCount = Object.keys(candidates).reduce((prev, j) => {
    if (i === j) return prev;
    else return prev * candidates[j].length;
  }, 1);
  count *= candidates[i].length;
  candidates[i].forEach((j) => {
    sum += 10 ** (N - 1 - i) * j * tmpCount;
  });
});

if (count === 0) console.log(-1);
else console.log(sum / count);
