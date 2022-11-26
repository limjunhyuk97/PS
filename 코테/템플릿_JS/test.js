// 6가지의 경우에 대한 연산 결과를 모두 구하면 될 것 같다.
// - stack을 사용하여 중위 표현식을 후위 표현식으로 바꾸어 연산하는 방식

function solution(expression) {
  var answer = 0;

  // value가 클수록 우선순위가 높다.
  const priory = [
    { "+": 1, "-": 2, "*": 3 },
    { "+": 1, "-": 3, "*": 2 },
    { "+": 2, "-": 3, "*": 1 },
    { "+": 2, "-": 1, "*": 3 },
    { "+": 3, "-": 1, "*": 2 },
    { "+": 3, "-": 2, "*": 1 },
  ];

  // exp로 문자열을 쪼갠다.
  const exp = [];
  let s = 0;
  for (let i = 0; i < expression.length; ++i) {
    if (
      expression[i] === "-" ||
      expression[i] === "+" ||
      expression[i] === "*"
    ) {
      exp.push(parseInt(expression.slice(s, i)));
      exp.push(expression[i]);
      s = i + 1;
    }
  }
  exp.push(parseInt(expression.slice(s)));

  // 6가지 경우에 대한 후위표기식 생성
  const postfixExps = priory.map((pri) => {
    let postfix = [];
    let stack = [];

    // "신삥"의 우선순위가 낮다면 stack으로 누르고, 우선순위가 높다면 직전 것 pop 시켜서 postfix에 넣는다.
    const stackOperation = (top) => {
      console.log(pri, top, stack, postfix);
      if (stack.length === 0) {
        stack.push(top);
      } else if (pri[stack[stack.length - 1]] > pri[top]) {
        stack.push(top);
      } else {
        postfix.push(top);
        postfix.push(stack[stack.length - 1]);
        stack.pop();
      }
    };

    // exp 읽으면서 수행한다.
    postfix.push(exp[0]);
    exp.forEach((el, idx) => {
      if (idx === 0) return;
      if (typeof el === "string") {
        stackOperation(el, idx);
      }
    });

    console.log();

    // 마지막에 연산자가 2개 혹은 1개 남았으니 마저 postfix에 밀어 넣어준다.
    if (stack.length > 0) stack.forEach((op) => postfix.push(op));

    return postfix;
  });

  console.log(postfixExps);

  // 후위 표기식들에 대해서 연산
  const postfixResult = postfixExps.map((postfix) => {
    let stack = [];

    const operation = (a, b, op) => {
      if (op === "-") return a - b;
      else if (op === "+") return a + b;
      else return a * b;
    };

    postfix.forEach((el) => {
      if (typeof el === "string") {
        let b = stack.pop();
        let a = stack.pop();
        stack.push(operation(a, b, el));
      } else {
        stack.push(el);
      }
    });

    return Math.abs(stack[0]);
  });

  console.log(postfixResult);

  // 최대값 반환
  answer = Math.max.apply(null, postfixResult);

  return answer;
}

console.log(solution("1+1*3"));
