//** 제출용 입력 경로 */
const submission = "/dev/stdin";

//** 테스트용 입력 경로 */
const testcase = "./testcase.txt";

//** fs 모듈 import */
let fs = require("fs");

const input = fs
  .readFileSync(testcase)
  .toString()
  .split("\n")
  .map((el) =>
    el
      .trim()
      .split(" ")
      .map((el) => Number(el))
  );

const N = input[0][0];
const Lectures = {};
input.slice(1).forEach((el) => {
  Lectures[el[0]] = [el[1], el[2]];
});

// 아니 이거 우선순위 큐를 만들어야 되네..
