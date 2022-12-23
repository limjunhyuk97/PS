const submission = "/dev/stdin";

const testcase = "./testcase.txt";

let fs = require("fs");

let input = fs.readFileSync(submission).toString().trim();

const reg = /^(100+1+|01)+$/;

console.log(reg.test(input) ? "SUBMARINE" : "NOISE");
