import random

def create_array(a, b, n):
    t = []
    for _ in range(n):
        t.append(random.randint(a, b))
    return t

def print_array(t):
    for i in t:
        print(f"{i:4}", end="")
    print()

def count_elements(t):
    x = 0
    for c in range(len(t)):
        if t[c] < 0 and c % 3 != 0:
            x += 1
    return x

def sum_element(t):
    summary = 0
    for c in range(len(t)):
        if t[c] < 0 and c % 3 != 0:
            summary += t[c]
    return summary

def zeroing(t):
    for c in range(len(t)):
        if t[c] < 0 and c % 3 != 0:
            t[c] = 0

def main():
    t = create_array(-11, 13, 25)
    print_array(t)
    print(f"quantity: {count_elements(t)}")
    print(f"sum: {sum_element(t)}")
    zeroing(t)
    print_array(t)

if __name__ == "__main__":
    main()
    