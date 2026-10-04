import math

xp = float(input("xp = "))
xk = float(input("xk = "))
dx = float(input("dx = "))
e = 1e-9

x = xp

print(f"{'X':>7} | {'Y':>7} ")
while x <= xk + e:
    A = 8.1 + x ** 3
    if x < -3.5:
        B = 1 - x ** -5
    elif -3.5 <= x < 1:
        t = math.tan(abs(x + 1))
        if abs(t) < e:
            print(f"{x:7.2f} | Gives no definition") 
            x += dx
            continue
        B = 1 / t
    else:
        B = math.atan(2*x)-math.log10(x/2)
    y = A + B    
    print(f"{x:7.2f} | {y:7.2f}")
    x += dx
print("="*17)
