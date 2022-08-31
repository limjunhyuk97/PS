//* 제출과 테스트케이스
//* 제출 시 fs.readFileSync("/dev/stdin") 으로 받아들인다.
//* 테스트케이스 실험 시 fs.readFileSync("./testcase.txt") 으로 받아들인다.

//** 제출용 입력 경로 */
const submission = "/dev/stdin";

//** 테스트용 입력 경로 */
const testcase = "./testcase.txt";

//** fs 모듈 import */
let fs = require("fs");

//** 한줄 입력 받아서, 배열로 넘겨주는 코드 */
// 1 2 3 4
// -> ['1', '2', '3', '4']
let oneline = fs.readFileSync(testcase).toString().trim().split(" ");

//** 여러줄 입력 받아서, 숫자로 변경 후, 배열로 넘겨주는 코드 */
// 1 2 3 4
// 3 4 5 7
// -> [[1, 2, 3, 4], [3, 4, 5, 7]]
let multiline = fs
  .readFileSync(testcase)
  .toString()
  .split("\n")
  .map((el) =>
    el
      .trim()
      .split(" ")
      .map((el) => Number(el))
  );

//** 들어올 숫자 배열 수 입력 받은 후, 각 숫자 배열 받아서, 배열로 넘겨주는 코드  */
// 2 3
// 1 2 3
// 5 6 7
// -> N = 2, M = 3, [[1, 2, 3], [5, 6, 7]]
let complex = fs
  .readFileSync(testcase)
  .toString()
  .split("\n")
  .map((el) =>
    el
      .trim()
      .split(" ")
      .map((el) => Number(el))
  );
