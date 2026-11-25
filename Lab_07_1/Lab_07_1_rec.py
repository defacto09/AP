import random


def init_row(cols, low, high):
    if cols == 0:
        return []
    t = init_row(cols - 1, low, high)
    t.append(random.randint(low, high))
    return t


def init_matrix(rows, cols, low, high):
    if rows == 0:
        return []
    a = init_matrix(rows - 1, cols, low, high)
    a.append(init_row(cols, low, high))
    return a


def print_row(t, j):
    if j == len(t):
        print()
        return
    print(f"{t[j]:4}", end="")
    print_row(t, j + 1)


def print_matrix(a, i):
    if i == len(a):
        print()
        return
    print_row(a[i], 0)
    print_matrix(a, i + 1)


def count_row(t, j):
    if j == len(t):
        return 0
    if t[j] < 0 and t[j] % 4 != 0:
        return 1 + count_row(t, j + 1)
    return count_row(t, j + 1)


def count_criterion(a, i):
    if i == len(a):
        return 0
    return count_row(a[i], 0) + count_criterion(a, i + 1)


def sum_row(t, j):
    if j == len(t):
        return 0
    if t[j] < 0 and t[j] % 4 != 0:
        return t[j] + sum_row(t, j + 1)
    return sum_row(t, j + 1)


def sum_criterion(a, i):
    if i == len(a):
        return 0
    return sum_row(a[i], 0) + sum_criterion(a, i + 1)


def zero_row(t, j):
    if j == len(t):
        return
    if t[j] < 0 and t[j] % 4 != 0:
        t[j] = 0
    zero_row(t, j + 1)


def replace_criterion_with_zero(a, i):
    if i == len(a):
        return
    zero_row(a[i], 0)
    replace_criterion_with_zero(a, i + 1)


def need_swap(r1, r2, j):
    if j == 3:
        return False
    if r1[j] != r2[j]:
        return r1[j] > r2[j]
    return need_swap(r1, r2, j + 1)


def change_rows(a, row1, row2, j):
    if j == len(a[row1]):
        return
    tmp = a[row1][j]
    a[row1][j] = a[row2][j]
    a[row2][j] = tmp
    change_rows(a, row1, row2, j + 1)


def bubble_pass(a, i1, last):
    if i1 >= last:
        return
    if need_swap(a[i1], a[i1 + 1], 0):
        change_rows(a, i1, i1 + 1, 0)
    bubble_pass(a, i1 + 1, last)


def sort_rows(a, i0):
    if i0 >= len(a) - 1:
        return
    bubble_pass(a, 0, len(a) - i0 - 1)
    sort_rows(a, i0 + 1)


def main():
    a = init_matrix(8, 5, -17, 14)
    print("Matrix T:")
    print_matrix(a, 0)

    sort_rows(a, 0)
    print("Sorted rows:")
    print_matrix(a, 0)

    k = count_criterion(a, 0)
    s = sum_criterion(a, 0)
    replace_criterion_with_zero(a, 0)
    print(f"Count: {k}")
    print(f"Sum: {s}")
    print("Zeros instead of criterion elements:")
    print_matrix(a, 0)


if __name__ == "__main__":
    main()
