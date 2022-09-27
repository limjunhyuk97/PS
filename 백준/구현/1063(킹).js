//** 제출용 입력 경로 */
const submission = "/dev/stdin";

//** 테스트용 입력 경로 */
const testcase = "./testcase.txt";

//** fs 모듈 import */
let fs = require("fs");

let input = fs
  .readFileSync(submission)
  .toString()
  .split("\n")
  .map((el) => el.trim().split(" "));

const rowLogic = {
  A: ["A", "B"],
  B: ["A", "C"],
  C: ["B", "D"],
  D: ["C", "E"],
  E: ["D", "F"],
  F: ["E", "G"],
  G: ["F", "H"],
  H: ["G", "H"],
};

const positionChange = (pos, movement) => {
  const movementArr = movement.split("");
  let afterPos = pos;
  if (movementArr.filter((el) => el === "R")?.length) {
    afterPos = rowLogic[afterPos[0]][1] + afterPos[1];
  }
  if (movementArr.filter((el) => el === "L")?.length) {
    afterPos = rowLogic[afterPos[0]][0] + afterPos[1];
  }
  if (movementArr.filter((el) => el === "B")?.length) {
    afterPos =
      afterPos[0] + (Number(afterPos[1]) - 1 < 1 ? 1 : Number(afterPos[1]) - 1);
  }
  if (movementArr.filter((el) => el === "T")?.length) {
    afterPos =
      afterPos[0] + (Number(afterPos[1]) + 1 > 7 ? 8 : Number(afterPos[1]) + 1);
  }
  let changes = pos.split("").reduce((prev, el, idx) => {
    if (el !== afterPos[idx]) return prev + 1;
    else return prev;
  }, 0);
  return changes !== movement.length ? pos : afterPos;
};

let moveCount = Number(input[0][2]);
let kingPos = input[0][0];
let rockPos = input[0][1];

for (let i = 0; i < moveCount; ++i) {
  let beforeKingPos = kingPos;
  let afterKingPos = positionChange(kingPos, input[1 + i][0]);

  // 돌과 부딪히는 경우
  if (afterKingPos === rockPos) {
    let beforeRockPos = rockPos;
    let afterRockPos = positionChange(rockPos, input[1 + i][0]);
    // 돌이 밖으로 튕겨 나가는 경우
    if (beforeRockPos === afterRockPos) {
      kingPos = beforeKingPos;
      rockPos = beforeRockPos;
    }
    // 돌이 안튕겨 나가는 경우
    else {
      kingPos = afterKingPos;
      rockPos = afterRockPos;
    }
  }
  // 돌과 부딪히지 않는 경우
  else {
    kingPos = afterKingPos;
  }
}

console.log(`${kingPos}\n${rockPos}`);
