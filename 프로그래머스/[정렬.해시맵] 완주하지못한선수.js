// [A1] sorting 방식
function solution(participant, completion) {
    var answer = '';
    
    participant.sort();
    completion.sort();
    
    participant.forEach((el, idx) => {
        if(participant[idx] !== completion[idx] && answer === '') answer = participant[idx];
    })
    
    answer = answer === '' ? completion[completion.length-1] : answer;
    
    return answer;
}

// [A2] 객체 사용하는 방식
function solution(participant, completion) {
    var answer = '';
    
    participant = participant.reduce((acc, cur)=> {
        if(cur in acc) acc[cur] += 1;
        else acc[cur] = 1;
        return acc;
    }, {});
    
    completion.forEach(el => {
        participant[el] -= 1;
    })
    
    for(let key in participant) {
        if(participant[key]) {
            answer = key;
            break;
        }
    }
     
    return answer;
}
