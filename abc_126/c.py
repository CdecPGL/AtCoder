# Score: 300/300

import math

N, K = [int(s) for s in input().split(" ")]
p = 0
for n in range(1, N+1):
    if n >= K:
        p += 1/N
    else:
        p += 1/N * (0.5 ** (math.ceil(math.log2(K/n))))
print(p)
