//***********************************/
//** 제출용 입력 경로 */
const submission = "/dev/stdin";

//** 테스트용 입력 경로 */
const testcase = "./testcase.txt";

//** fs 모듈 import */
let fs = require("fs");
//***********************************/

const input = fs
  .readFileSync(submission)
  .toString()
  .split("\n")
  .map((el) =>
    el
      .trim()
      .split(" ")
      .map((el) => Number(el))
  );

const N = input[0];
const P = input[1];
const S = input[2];

// P -> base : i라는 수는 i%N 번째에 할당되어야 한다.
let base = {};
for (let i = 0; i < N; ++i) {
  base[i] = P[i];
}

// arr는 카드배열이다
let arr = [];
for (let i = 0; i < N; ++i) arr.push(i);

// 셔플한 횟수
let shuffles = 0;

const arrCheck = (arr) => {
  for (let i = 0; i < N; ++i) {
    if (base[arr[i]] !== i % 3) return false;
  }
  return true;
};

const arrShuffle = (arr) => {
  let tmp = {};
  S.forEach((el, idx) => {
    tmp[S[idx]] = arr[idx];
  });

  Object.keys(tmp).forEach((el) => {
    arr[el] = tmp[el];
  });
};

// arr가 원위치로 돌아옴..?
const arrCompare = (arr) => {
  for (let i = 0; i < N; ++i) {
    if (arr[i] !== i) return false;
  }
  return true;
};

while (!arrCheck(arr)) {
  ++shuffles;
  arrShuffle(arr);
  if (arrCompare(arr)) {
    shuffles = -1;
    break;
  }
}

console.log(shuffles);
