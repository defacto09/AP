i = 1 
i_max = 15
s = 0

# First method 
while i <= i_max:
    p = 1
    k = 1
    while k <= i:
        p *= k ** 2 + 1
        k += 1
    i += 1
    s += p / (1 + (p ** 2))
print(f"Result 1: {s}")

# Second method
i = 1
s = 0
while True:
    p = 1
    k = 1
    while True:
        p *= k ** 2 + 1
        k += 1
        if not (k <= i): break
    i += 1
    s += p / (1 + (p ** 2))
    if not (i <= i_max): break
print(f"Result 2: {s}")

# Third method
s = 0
for i in range (1, i_max+1):
    p = 1
    for k in range (1, i + 1):
        p *= k ** 2 + 1
    s += p / (1 + (p ** 2))
print(f"Result 3: {s}")


# Fourth method
s = 0
for i in range (i_max, 0, -1):
    p = 1
    for k in range (i, 0, -1):
        p *= k ** 2 + 1
    s += p / (1 + (p ** 2))
print(f"Result 4: {s}")