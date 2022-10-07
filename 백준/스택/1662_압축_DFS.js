const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

const solution = (strings) => {
  let index = 0;

  // 클로저 dfs는 length를 반환한다.
  const dfs = () => {
    let length = 0;
    let prevCount = 0;
    // index로 strings(input)을 반복해서 돈다.
    while (index < strings.length) {
      const char = strings[index];
      index++;
      switch (char) {
        case "(":
          length += Number(prevCount) * dfs() - 1;
          break;
        case ")":
          return length;
        default:
          length++;
          prevCount = char;
          break;
      }
    }
    return length;
  };

  return dfs();
};

// DFS 연쇄적 호출
console.log(solution(input));
