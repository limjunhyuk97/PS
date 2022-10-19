function solution(n, lost, reserve) {
    var answer = 0;
    
    const duplicated = lost.reduce((acc, cur) => {
        if(reserve.filter(el => el === cur).length) acc.push(cur);
        return acc;
    }, [])
    
    lost = lost.filter(i => duplicated.filter(j => j === i).length ? false : true)
    reserve = reserve.filter(i => duplicated.filter(j => j===i).length ? false : true)
    
    const reservedOnes = new Array(35).fill(false);
    reserve.forEach(el => reservedOnes[el] = true);
    
    // 낮은 수에서부터 순서대로 그리디하게 체육복을 빌려줘야 함..
    lost.sort();
    lost = lost.filter(el => {
        if(el>1 && reservedOnes[el-1]) {
            reservedOnes[el-1] = false;
            return false;
        }
        if(el<n && reservedOnes[el+1]) {
            reservedOnes[el+1] = false;
            return false;
        }
        return true;
    })
    
    answer = n - lost.length;
    
    return answer;
}

/**
 
[Q] 그리디한 구현

- 순서의 강제 후 탐욕적인 검색이 요구됨
*/
