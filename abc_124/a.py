# Score: 100/100

A, B = [int(s) for s in input().split(" ")]
print(max(2 * A - 1, A + B, 2 * B - 1))
