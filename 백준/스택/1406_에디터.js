const submission = "/dev/stdin";
const testcase = "./testcase.txt";
let fs = require("fs");

const input = fs.readFileSync(submission).toString().trim().split("\n");

let string = input[0];
let cursor = string.length;

input.forEach((el, idx) => {
  if (idx > 1) {
    if (el.length === 1) {
      if (el === "L") {
        cursor = cursor > 0 ? cursor - 1 : 0;
      }
      if (el === "D") {
        cursor = cursor < string.length ? cursor + 1 : string.length;
      }
      if (el === "B") {
        if (cursor > 0) {
          string = string.slice(0, cursor - 1) + string.slice(cursor);
        }
        cursor = cursor > 0 ? cursor - 1 : 0;
      }
    } else {
      string =
        string.slice(0, cursor) + el.split(" ")[1] + string.slice(cursor);
      cursor += 1;
    }
  }
});

console.log(string);
