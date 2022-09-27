//** 제출용 입력 경로 */
const submission = "/dev/stdin";

//** 테스트용 입력 경로 */
const testcase = "./testcase.txt";

//** fs 모듈 import */
let fs = require("fs");

const input = fs.readFileSync(testcase).toString().trim().split("\n");

const N = Number(input[0].trim().split(" ")[0]);
const d = Number(input[0].trim().split(" ")[1]);
const k = Number(input[0].trim().split(" ")[2]);
const c = Number(input[0].trim().split(" ")[3]);
const arr = input.slice(1).map((el) => Number(el));

let p1 = 0;
let p2 = 0;
let flag = true;
let max = 0;

const moveP1 = () => {
  // p1 ~ p2로 센 다음 -> p1이 어디로 와야하는지 고려
  // 7 7 4 7 5 -> 여기서 두번째 7로 보내야 함
  // 7 9 7 8 7 -> 여기서는 9 ..?
  const obj = {};
  const before = p1;
  let after = p1;
  if (p1 <= p2) {
    for (let i = p2; i > p1; --i) {
      if (!obj[arr[i]]) after = i;
      obj[arr[i]] = true;
    }
  } else {
    for (let i = p2; i >= 0; --i) {
      if (!obj[arr[i]]) after = i;
      obj[arr[i]] = true;
    }
    for (let i = arr.length - 1; i > p1; --i) {
      if (!obj[arr[i]]) after = i;
      obj[arr[i]] = true;
    }
  }
  p1 = after;
  if (p1 < before) flag = false;
};

const moveP2 = (count) => {
  p2 += count;
  if (p2 > arr.length - 1) p2 -= arr.length;
};

const watching = () => {
  if (p1 <= p2) return p2 - p1 + 1;
  else return arr.length - p1 + p2 + 1;
};

const checkChunk = () => {
  let obj = {};
  if (p1 < p2) {
    for (let i = p1; i <= p2; ++i) {
      if (arr[i] === c) continue;
      obj[arr[i]] = true;
    }
  } else {
    for (let i = p1; i < arr.length; ++i) {
      if (arr[i] === c) continue;
      obj[arr[i]] = true;
    }
    for (let i = 0; i <= p2; ++i) {
      if (arr[i] === c) continue;
      obj[arr[i]] = true;
    }
  }
  return Object.keys(obj).length;
};

while (flag) {
  let watchingCount = watching();
  moveP2(k - watchingCount);
  let tmp = checkChunk();
  max = max > tmp ? max : tmp;
  moveP1();
}

console.log(max + 1);
