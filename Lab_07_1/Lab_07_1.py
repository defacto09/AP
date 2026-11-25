import random


def init_matrix(rows, cols, low, high):
    a = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(random.randint(low, high))
        a.append(row)
    return a


def print_matrix(a):
    for i in range(len(a)):
        for j in range(len(a[i])):
            print(f"{a[i][j]:4}", end="")
        print()
    print()


def is_criterion(x):
    return x < 0 and not x % 4 == 0


def count_criterion(a):
    k = 0
    for i in range(len(a)):
        for j in range(len(a[i])):
            if is_criterion(a[i][j]):
                k += 1
    return k


def sum_criterion(a):
    s = 0
    for i in range(len(a)):
        for j in range(len(a[i])):
            if is_criterion(a[i][j]):
                s += a[i][j]
    return s


def replace_criterion_with_zero(a):
    for i in range(len(a)):
        for j in range(len(a[i])):
            if is_criterion(a[i][j]):
                a[i][j] = 0


def need_swap(r1, r2):
    if r1[0] != r2[0]:
        return r1[0] > r2[0]
    if r1[1] != r2[1]:
        return r1[1] > r2[1]
    return r1[2] > r2[2]


def change_rows(a, row1, row2):
    for j in range(len(a[row1])):
        tmp = a[row1][j]
        a[row1][j] = a[row2][j]
        a[row2][j] = tmp


def sort_rows(a):
    n = len(a)
    for i0 in range(n - 1):
        for i1 in range(n - i0 - 1):
            if need_swap(a[i1], a[i1 + 1]):
                change_rows(a, i1, i1 + 1)


def main():
    a = init_matrix(8, 5, -17, 14)
    print("Matrix T:")
    print_matrix(a)

    sort_rows(a)
    print("Sorted rows:")
    print_matrix(a)

    k = count_criterion(a)
    s = sum_criterion(a)
    replace_criterion_with_zero(a)
    print(f"Count: {k}")
    print(f"Sum: {s}")
    print("Zeros instead of criterion elements:")
    print_matrix(a)


if __name__ == "__main__":
    main()

