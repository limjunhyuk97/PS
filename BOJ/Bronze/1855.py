K = int(input())
stringFrom = input()

fill = "right"
stringTo = []
for i in range(K):
    stringTo.append([])
for i in range(1, len(stringFrom)+1):
     if fill == "right":
        stringTo[(i-1)%K].append(stringFrom[i-1])
        if i % K == 0: fill = "left"
     else:
        stringTo[K - (i-1)%K -1].append(stringFrom[i-1])
        if i % K == 0: fill = "right"

for i in stringTo:
    for j in i:
        print(j, end='')
