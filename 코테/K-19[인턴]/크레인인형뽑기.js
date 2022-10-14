function solution(board, moves) {
    var answer = 0;
    
    const transpose = rows => rows[0].map((_, c) =>rows.map(row=>row[c]));
    board = transpose([...board]);
    board = board.map(el => el.reverse());
    board = board.map(el=>el.reduce((prev, cur)=> {return cur === 0 ? prev : [...prev, cur]}, []));

    let stack = [];
    moves.forEach(i => {
        if(board[i-1]?.length) {
            const cur = board[i-1].pop()
            stack.push(cur)
            let cnt = 0;
            if(stack.length > 1) {
                for(let j=stack.length-2; j>=0; --j) {
                    console.log(stack[j])
                    if(stack[j] === cur) {
                        cnt += 1;
                    }
                    else break;
                }
            }
            if(cnt > 0) {
                cnt += 1;
                stack = stack.slice(0, -cnt);
                answer += cnt
            }
        }
    })
    
    return answer;
}
