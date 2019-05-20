# Score: 200/200

def is_month(value):
    return 1 <= value and value <= 12

S = input()
A = is_month(int(S[:2]))
B = is_month(int(S[2:]))


if A:
    if B:
        print("AMBIGUOUS")
    else:
        print("MMYY")
else:
    if B:
        print("YYMM")
    else:
        print("NA")