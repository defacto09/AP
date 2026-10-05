import random

R = float(input("R: "))
while R <= 0:
    R = float(input("R: "))

method = int(input("Which method? "))
while method != 1 and method != 2:
    method = int(input("Which method: 1 or 2? "))

if method == 1:
    for i in range(10):
        x = float(input("x: "))
        y = float(input("y: "))
        if x >= 0 and y >= 0 and (x*x + y*y <= R ** 2):
                print("yes")
        elif x <= 0 and y <= 0 and (x*x + y*y <= R ** 2):
                print("yes")
        elif x <= 0 and y <= x + R and y >= 0:
                print("yes")
        else:
                print("no")

elif method == 2:
    for i in range(10):
        x = random.uniform(-R, R)
        print(f"X: {x:.2f}")
        y = random.uniform(-R, R)
        print(f"Y: {y:.2f}")
        if x >= 0 and y >= 0 and (x*x + y*y <= R ** 2):
                print("yes")
        elif x <= 0 and y <= 0 and (x*x + y*y <= R ** 2):
                print("yes")
        elif x <= 0 and y <= x + R and y >= 0:
                print("yes")
        else:
                print("no")

