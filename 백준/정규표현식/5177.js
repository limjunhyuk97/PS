const submission = "/dev/stdin";

const testcase = "./testcase.txt";

let fs = require("fs");

let input = fs.readFileSync(submission).toString().trim().split("\n");

let cnt = 0;

function normalize(str) {
  str = str.replace(/[A-Z]/g, (match) => {
    return match.toLowerCase();
  });

  str = str.replace(/\s*[\(\)\[\]\{\}\.\,\;\:]\s*/g, (match) => {
    return match.trim();
  });

  str = str.replace(/\s+/g, (match) => {
    return " ";
  });

  str = str.trim();

  str = str.replace(/[\(\[\{]/g, (match) => "(");

  str = str.replace(/[\)\}\]]/g, (match) => ")");

  str = str.replaceAll(";", ",");

  return str;
}

while (cnt < Number(input[0])) {
  let s1 = normalize(input[cnt * 2 + 1]);
  let s2 = normalize(input[cnt * 2 + 2]);
  cnt += 1;

  if (s1 === s2) console.log(`Data Set ${cnt}: equal\n`);
  else console.log(`Data Set ${cnt}: not equal\n`);
}
