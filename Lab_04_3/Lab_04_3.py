
a = float(input("a = "))
b = float(input("b = "))

c = float(input("c = "))
while c == 0:
    c = float(input("c = "))

xp = float(input("xp = "))
xk = float(input("xk = "))
dx = float(input("dx = "))

x = xp
e = 1e-9

print(f"{'X':>7} | {'F':>7} ")
while x <= xk + e:
    if x < -e and b != 0:
        b10 = 10 + b
        if abs(b10) < e:
            print(f"{x:7.2f} | Gives no definition")
            x += dx
            continue
        F = a - (x / b10)
    elif x > e and b == 0:
        xc = (x - c)
        if abs(xc) < e:
            print(f"{x:7.2f} | Gives no definition")
            x += dx
            continue
        F = (x - a) / xc
    else:
        F = 3*x + 2/c
    print(f"{x:7.2f} | {F:7.2f}")
    x += dx
print("="*17)
 
