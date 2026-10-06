import math as m

xp = float(input("xp: "))
while not (-1 < xp < 1):
    xp = float(input("xp: "))

xk = float(input("xk: "))
while not (-1 < xk < 1):
    xk = float(input("xk: "))

dx = float(input("dx: "))

eps = float(input("eps: "))

x = xp

print(f"{'X':>7} | {'n':>4} | {'S':>6} | {'ln':>1}")
while x <= xk:
    n = 0
    a = x
    S = 0
    ln = m.log((1+x)/(1-x))
    while True:
        n += 1
        R = x * x * (2*n - 1) / (2*n + 1)
        if abs(a) >= eps:
            S += a
            a *= R
        if abs(a) <= eps:
            break
    s2 = 2 * S
    print(f"{x:7.4f} | {n:4d} | {s2:.4f} | {ln:.4f}")
    x += dx


