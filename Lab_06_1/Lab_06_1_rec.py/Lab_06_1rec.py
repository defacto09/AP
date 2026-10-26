import random

def create_array(a, b, n):
    if n == 0:
        return []
    t = create_array(a, b, n - 1)
    t.append(random.randint(a, b))
    return t

def print_array(t, i):
    if i == len(t):
        print()
        return
    print(f"{t[i]:4}", end="")
    print_array(t, i + 1)

def count_elements(t, i):
    if i == len(t):
        return 0
    if t[i] < 0 and i % 3 != 0:
        return 1 + count_elements(t, i + 1)
    return count_elements(t, i + 1)

def sum_element(t, i):
    if i == len(t):
        return 0
    if t[i] < 0 and i % 3 != 0:
        return t[i] + sum_element(t, i + 1)
    return sum_element(t, i + 1)

def zeroing(t, i):
    if i == len(t):
        return
    if t[i] < 0 and i % 3 != 0:
        t[i] = 0
    return zeroing(t, i + 1)

def main():
    i = 0
    t = create_array(-11, 13, 25)
    print_array(t, i)
    print(f"quantity: {count_elements(t, i)}")
    print(f"sum: {sum_element(t, i)}")
    zeroing(t, i)
    print_array(t, i)

if __name__ == "__main__":
    main()