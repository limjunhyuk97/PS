N, L = list(map(int, input().split()))

flag = False
listLen = 0
for n in range(L, 101):
    if n % 2 == 0:
        if n == 2 and N % 2 == 1 and N != 1:
            listLen = n
            flag = True
            break
        else:
            if (N // (n // 2)) % 2 == 1 and (N % (n//2)) == 0 and ((N // (n/2)) // 2 - (n//2-1)) >= 0:
                   listLen = n
                   flag = True
                   break
    else:
        if N % n == 0 and (N // n  - (n // 2)) >= 0:
            listLen = n
            flag = True
            break

if flag:
    print(*[num for num in range( int(N/listLen) - (listLen//2) , int(N/listLen) - (listLen//2) + listLen )]) if listLen % 2 == 1 else print(*[num for num in range( int(N/(listLen//2))//2 - (int(listLen/2)-1), int(N/(listLen//2))//2 - (int(listLen/2)-1) + listLen)])
else:
    print(-1)
