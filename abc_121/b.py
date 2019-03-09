# Score: 200/200

import numpy as np

N, M, C = [int(s) for s in input().split(" ")]
B = np.array([int(s) for s in input().split(" ")])
counter = 0
for _ in range(N):
    A = np.array([int(s) for s in input().split(" ")])
    if np.dot(A, B) + C > 0:
        counter += 1
print(counter)
