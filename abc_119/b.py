# Score: 200/200

V_MAP = {'JPY':1.0,'BTC':380000.0}
N = int(input())
o = 0
for n in range(N):
    items = [s for s in input().split(" ")]
    x = float(items[0])
    u = items[1]
    o += x*V_MAP[u]
print(o)