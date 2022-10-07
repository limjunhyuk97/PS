// --> import
// stack
function stack(c = 0, v = []) {
  let arr = v;
  let cur = c;
  const top = () => {
    return cur !== 0 ? arr[cur - 1] : null;
  };
  const push = (val) => {
    arr[cur++] = val;
  };
  const pop = () => {
    if (cur == 0) return null;
    cur -= 1;
    return arr[cur];
  };
  const size = () => cur;
  const isEmpty = () => {
    return cur === 0 ? true : false;
  };
  const at = (idx) => {
    return cur > idx ? arr[idx] : null;
  };
  const erase = () => {
    arr = [];
    cur = 0;
  };
  return {
    push,
    pop,
    size,
    isEmpty,
    at,
    erase,
    top,
  };
}
// <-- import

// --> input
const submission = "/dev/stdin";
const testcase = "./testcase.txt";
let fs = require("fs");
const input = fs.readFileSync(submission).toString().trim().split("");
// <-- input

// 중위표현식 생성
let OP1 = "";
const makeOP = stack();
input.forEach((el) => {
  if (el === "(") {
    OP1 += "'" + (makeOP.size() - 1) + "'";
    OP1 += "+";
    OP1 += "'" + makeOP.pop() + "'";
    OP1 += "*";
    OP1 += "(";
    makeOP.erase();
  } else if (el === ")") {
    OP1 += "'" + makeOP.size() + "'" + ")+";
    makeOP.erase();
  } else {
    makeOP.push(el);
  }
});
// 괄호가 없는 경우
if (OP1.length === 0) OP1 = makeOP.size().toString();
// 꽁지가 남은 경우
if (OP1[OP1.length - 1] === "+") OP1 += "'" + makeOP.size() + "'";
makeOP.erase();

// 후위표기식 생성
let OP2 = "";
OP1.split("").forEach((el) => {
  if (el === "+") {
    while (makeOP.top() !== "(" && !makeOP.isEmpty()) {
      OP2 += makeOP.pop();
    }
    makeOP.push("+");
  } else if (el === "*") {
    makeOP.push("*");
  } else if (el === "(") {
    makeOP.push("(");
  } else if (el === ")") {
    while (makeOP.top() !== "(") {
      OP2 += makeOP.pop();
    }
    makeOP.pop();
  } else {
    OP2 += el;
  }
});
while (!makeOP.isEmpty()) {
  OP2 += makeOP.pop();
}
makeOP.erase();
OP2 = OP2.split("'")
  .filter((el) => el !== "")
  .map((el) => (el[0] === "*" || el[0] === "+" ? el.split("") : el));

// 후위표기식 연산
OP2.forEach((el) => {
  if (typeof el === "object") {
    el.forEach((op) => {
      if (op === "*") {
        let n1 = makeOP.pop();
        let n2 = makeOP.pop();
        makeOP.push(Number(n1) * Number(n2));
      } else {
        let n1 = makeOP.pop();
        let n2 = makeOP.pop();
        makeOP.push(Number(n1) + Number(n2));
      }
    });
  } else {
    makeOP.push(Number(el));
  }
});

console.log(makeOP.top());
