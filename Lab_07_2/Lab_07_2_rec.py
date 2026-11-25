import random

def init_row(n, low, high):
    if n == 0:
        return []
    t = init_row(n - 1, low, high)
    t.append(random.randint(low, high))
    return t

def init_matrix(n, k, low, high):
    if k == 0:
        return []
    m = init_matrix(n, k - 1, low, high)
    m.append(init_row(n, low, high))
    return m

def print_row(t, i):
    if i == len(t):
        print()
        return
    print(f"{t[i]:4}", end="")
    print_row(t, i + 1)

def print_matrix(m, i):
    if i == len(m):
        return 
    print_row(m[i], 0)
    print_matrix(m, i + 1)

def sum_main_diagonal(m, i):
    if i == len(m):
        return 0
    return (m[i][i]) + sum_main_diagonal(m, i + 1)
    
def main():
    m = init_matrix(3, 3, -10, 10)
    print_matrix(m, 0)
    print(f"Sum: {sum_main_diagonal(m, 0)}")

if __name__ == "__main__":
    main()