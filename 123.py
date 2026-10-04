import math

x = int(input("x="))

if x < -2:
    y = abs(x) + 1
elif x <= 3:
    y = pow(x, 2) - 4
else:
    y = math.sqrt(x)

print(y)