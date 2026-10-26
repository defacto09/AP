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

def max_num(t, i, biggest):
    if i == len(t):
        return biggest
    if t[i] > biggest:
        biggest = t[i]
    return max_num(t, i + 1, biggest)

def min_num(t, i, smallest):
    if i == len(t):
        return smallest
    if t[i] < smallest:
        smallest = t[i]
    return min_num(t, i + 1, smallest)

def avg(manu, minu):
    return (manu + minu) / 2

def main():
    t = create_array(-20, 20, 10)
    print_array(t, 0)
    manu = max_num(t, 1, t[0])
    minu = min_num(t, 1, t[0])
    print(f"Max: {manu} \nMin: {minu}")
    print(f"Average: {avg(manu, minu)}")

if __name__ == "__main__":
    main()