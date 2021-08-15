
N, K = list(map(int, input().split()))

n_to_bin = bin(N)[2:]
one_in_bin = 0
zero_in_bin = [num for num in range(len(n_to_bin)) if n_to_bin[num] == '0']
for i in range(len(n_to_bin)):
    if n_to_bin[i] == '1' : one_in_bin += 1

if one_in_bin <= K: print(0)
else:
    if K == 1: print((1 << len(n_to_bin)) - N)
    else :
        flag = False
        for i in range(len(zero_in_bin)-1, -1, -1):
            if zero_in_bin[i] - i + 1 <= K:
                tmp = N
                tmp = tmp | (1 << len(n_to_bin) - 1 - zero_in_bin[i])
                tmp = tmp >> (len(n_to_bin) - 1 - zero_in_bin[i])
                tmp = tmp << (len(n_to_bin) - 1 - zero_in_bin[i])
                print(tmp - N)
                flag = True
                break
        if flag == False:
            print((1 << len(n_to_bin)) - N)
