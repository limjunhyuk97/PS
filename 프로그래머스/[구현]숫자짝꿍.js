// X, Y 값 비교 -> 공통된 원소 추출
// 가장 큰 값부터 차례대로 string에 붙이기
function solution(X, Y) {
    var answer = '';
    
    let num_X = (new Array(10)).fill(0)
    let num_Y = (new Array(10)).fill(0)
    
    X.split('').forEach(el => num_X[Number(el)] += 1)
    Y.split('').forEach(el => num_Y[Number(el)] += 1)
    
    num_X.forEach((el, i) => {
        if(num_X[i] !==0 && num_Y[i]!==0) {
            for(let j=0; j<Math.min(num_X[i], num_Y[i]); ++j) {
                answer = i + answer;
            }
        }
    })
    
    if (answer === '') return answer = '-1'
    else if (answer.split('').filter(el => el !== '0').length === 0) {
        return answer = '0'
    }
    else return answer;
}
