function solution(n, info) {
  let answer = [];
  let gap = 0;

  function scoreGap(lion, apeach) {
    gap = 0;
    for (let i = 0; i < 11; ++i) {
      if (lion[i] > apeach[i]) gap += 10 - i;
      else gap -= 10 - i;
    }
    return gap;
  }

  function renewResult(lion, apeach) {
    if (gap < scoreGap(lion, apeach)) {
      gap = scoreGap(lion, apeach);
      answer = lion;
    }
  }

  function DFS(left, n, lion, apeach) {
    if (left === 0) {
      console.log(lion);
      renewResult(lion, apeach);
    }
    if (n === 11) {
      lion[10] += left;
      console.log(lion);
      renewResult(lion, apeach);
    }
    // 승리하는 경우 고려
    if (left > apeach[n] + 1) {
      lion[n] = apeach[n] + 1;
      DFS(left - (apeach[n] + 1), n + 1, lion, apeach);
      lion[n] = 0;
    }
    // 패배하는 경우 고려
    DFS(left, n + 1, lion, apeach);
  }

  const initializedScore = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
  DFS(n, 0, initializedScore, info);
  if (answer === initializedScore) answer = [-1];

  return answer;
}

solution(5, [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]);
