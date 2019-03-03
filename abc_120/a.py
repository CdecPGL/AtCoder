# Score: 100/100

A, B, C = [int(s) for s in input().split(" ")]
print(C if B >= A*C else B // A)
