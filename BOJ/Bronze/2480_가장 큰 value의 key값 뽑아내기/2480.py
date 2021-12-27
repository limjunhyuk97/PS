a = list(map(int, input().split()))
di = {}
for num in a:
    if di.get(num) == None:
        di[num] = 1
    else:
        di[num] += 1

if len(di) == 3:
    a.sort(reverse=True)
    print(100 * a[0])
elif len(di) == 2:
    print(1000 + 100 * int(max(di, key = di.get)))
else:
    print(10000 + 1000 * a[0])
