import random

def init_matrix(n, low, high):
    a = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(random.randint(low, high))
        a.append(row)
    return a

def print_matrix(a):
    for i in range(len(a)):
        for j in range (len(a[i])):
            print(f"{a[i][j]:4}", end="")
        print()

def sum_main_diagonal(a):
    summary = 0
    for d in range(len(a)):
        summary += a[d][d]
    return summary

def main():
    a = init_matrix(3, -10, 10)
    print_matrix(a)
    print(f"Sum: {sum_main_diagonal(a)}")

if __name__ == "__main__":
    main()