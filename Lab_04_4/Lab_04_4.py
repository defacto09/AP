import math

R = float(input("R: "))
while R <= 0:
    R = float(input("R: "))

xp = float(input("xp: "))
xk = float(input("xk: "))
dx = float(input("xd: "))

x = xp
e = 1e-9

print(f"{'X':>7} | {'Y':>7} ")
while x <= xk + e:
    if x <= -2:
        y = x + 3
    elif x <= 4:
        y = 1 - (R + 1) * (x + 2) / 6
    elif x <= 8 - R:
        y = -R
    elif (x <= 8 + R):
        y = -R + math.sqrt(R * R - (x - 8) * (x - 8))
    else:
        y = -R
    print(f"{x:7.2f} | {y:7.2f}")
    x += dx

print("="*17)
