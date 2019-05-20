# Score: 100/100

N, K = [int(s) for s in input().split(" ")]
S = input()
print(S[:max(0, K-1)] + S[K-1].lower() + S[K:])
