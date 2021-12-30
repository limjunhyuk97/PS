n = int(input()); cnt = 1
sequence = [None] * n
stack = []; ans = []; flag = True
for i in range(n): sequence[i] = int(input())
for i in range(0, n):
    if len(stack) == 0:
        stack.append(cnt)
        cnt += 1
        ans.append('+')
    if stack[len(stack)-1] == sequence[i]:
        stack.pop()
        ans.append('-')
    else:
        if cnt <= n and stack[len(stack)-1] < sequence[i]:
            for j in range(cnt, sequence[i] + 1):
                ans.append('+')
                stack.append(j)
            cnt = sequence[i] + 1
            stack.pop()
            ans.append('-')
        else:
            flag = False
            break
if flag:
    for i in range(len(ans)):
        print(ans[i])
else:
    print('NO')
