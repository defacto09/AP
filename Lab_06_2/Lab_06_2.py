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

def max_num(t):
    biggest = t[0]
    for i in t:
        if i > biggest:
            biggest = i
    return biggest

def min_num(t):
    smallest = t[0]
    for i in t:
        if i < smallest:
            smallest = i
    return smallest

def avg(manu, minu):
    return (manu + minu) / 2

def main():
    t = create_array(-20, 20, 10)
    print_array(t)
    manu = max_num(t)
    minu = min_num(t)
    print(f"Max: {manu} \nMin: {minu}")
    print(f"Average: {avg(manu, minu)}")


if __name__ == "__main__":
    main()