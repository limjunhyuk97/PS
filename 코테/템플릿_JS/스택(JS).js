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

function solution(numbers, hand) {
    let answer = '';
    const pos = {L : [0, 0], R :[2, 0], 0 : [1, 0], 7:[0,1], 8:[1,1], 9:[2,1], 4:[0,2], 5:[1,2], 6:[2,2], 1:[0,3], 2:[1,3], 3:[2,3]}
    
    numbers.forEach(el => {
        if(el === '1' || el === '4' || el === '7') {
            answer += 'L';
            pos[L][0] = pos[el][0];
            pos[L][1] = pos[el][1];
        }
        
        else if(el === '3' || el ==='6' || el==='9') {
            answer += 'R';
            pos[R][0] = pos[el][0];
            pos[R][1] = pos[el][1];
        }
        
        else { 
            if(Math.abs(pos[el][0] -pos[L][0]) + Math.abs(pos[el][1]-pos[L][1]) > Math.abs(pos[el][0]-pos[R][0]) +Math.abs(pos[el][1]-pos[R][1])) 
            {
                answer += 'R';
                pos[R][0] = pos[el][0];
                pos[R][1] = pos[el][1];
            }
            else if(Math.abs(pos[el][0] -pos[L][0]) + Math.abs(pos[el][1]-pos[L][1]) === Math.abs(pos[el][0]-pos[R][0]) +Math.abs(pos[el][1]-pos[R][1]))
            {
                answer += (hand==='right' ? 'R' : 'L');
                pos[hand==='right' ? 'R' : 'L'][0] = pos[el][0];
                pos[hand==='right' ? 'R' : 'L'][1] = pos[el][1];
            }
            else 
            {
                answer += 'L';
                pos[L][0] = pos[el][0];
                pos[L][1] = pos[el][1];
            }
        })
    
    return answer;
}