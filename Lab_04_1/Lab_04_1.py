# Lab_04_1.py
# Саламаха Роман, РІ-12
# Лабораторна робота № 4.1 «Цикли»
# Варіант 25

N = int(input("enter N:"))

k = N
k_max = 19
p = 1

# First method
while k <= k_max:
    p *= (k-N)/(k+N) + 1
    k += 1
    
result1 = round(p, 5)
print(f"Result 1: {result1}")

# Second method
p = 1
k = N
while True:
    p *= (k-N)/(k+N) + 1
    k += 1
    if not (k <= k_max): break

result2 = round(p, 5)
print(f"Result 2: {result2}")

# Third method
p = 1
for k in range (N, k_max+1):
    p *= (k-N)/(k+N) + 1

result3 = round(p, 5)
print(f"Result 3: {result3}")

# Fourth method
p = 1
for k in range (k_max, N - 1, -1):
    p *= (k-N)/(k+N) + 1

result4 = round(p, 5)
print(f"Result 4: {result4}")

if result1 == result2 == result3 == result4:
    print("True")
