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
