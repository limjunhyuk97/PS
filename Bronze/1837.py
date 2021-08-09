import math

N, K = list(map(int, input().split()))

def PrimeNumber(n):
    primeCheck = [True for i in range(n+1)]
    for i in range(2, int(math.sqrt(n+1)) + 1):
        if primeCheck[i]:
            j = 2
            while i * j <= n:
                primeCheck[i*j] = False
                j += 1
    return [i for i in range(2, n+1) if primeCheck[i] ]

# K-1 까지의 primeNumber list 로 반환
primeList = PrimeNumber(K-1)

n = 1; m =0
for num in primeList:
    if N % num == 0:
        n = num
        break

if n == 1:
    print("GOOD")
else:
    print("BAD", n if n < N/n else N/n)

