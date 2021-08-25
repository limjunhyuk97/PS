# 정규 표현식을 사용한 풀이

## fullmatch(문자열) : 문자열과 전체적으로 match하는지 안하는지를 확인해야한다.
## match(문자열) : 전체 문자열을 확인하기 이전에, 이미 매치되는 부분이 있는경우, 그 부분에 대한 match 객체를 먼저 반환하는 경우가 생긴다.
 
from sys import stdin
import re

N = int(stdin.readline())
arr = [stdin.readline().strip() for _ in range (N)]
p = re.compile('(100+1+|01)+')

for string in arr:
    if p.fullmatch(string) : print("YES")
    else : print('NO')

