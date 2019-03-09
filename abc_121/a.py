# Score: 100/100

H, W = [int(s) for s in input().split(" ")]
h, w = [int(s) for s in input().split(" ")]
print(H * W - (H * w + W * h - w * h))
