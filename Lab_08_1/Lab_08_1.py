# Лабораторна робота 8.1, варіант 25. Ітераційний спосіб.
# Дано літерний рядок s[0], ..., s[n], ...
# 1. Вияснити, чи є в рядку такі елементи s[i], s[i+1], що s[i] - кома (','),
#    а s[i+1] - тире ('-'), та обчислити їх кількість.
# 2. Замінити кожну групу символів ",-" зірочкою "*".


def scan_comma_dash(s):
    # повертає True, якщо в рядку s є хоча б одна пара ",-"
    for i in range(len(s) - 1):
        if s[i] == "," and s[i+1] == "-":
            return True
    return False


def qty_comma_dash(s):
    # повертає кількість пар ",-" у рядку s
    q = 0
    for i in range(len(s) - 1):
        if s[i] == "," and s[i+1] == "-":
            q += 1
    return q


def replace_comma_dash(s):
    # повертає новий рядок, у якому кожна пара ",-" замінена на "*"
    i = 0
    result = ''
    while i < len(s):
        if (i + 1) < len(s) and s[i] == "," and s[i+1] == "-":
            result += "*"
            i += 2
        else:
            result += s[i]
            i += 1
    return result


def main():
    s = input("Введіть рядок: ")
    if scan_comma_dash(s):
        print("Пари \",-\" є, їх кількість:", qty_comma_dash(s))
    else:
        print("Пар \",-\" немає")
    print("Змінений рядок:", replace_comma_dash(s))


if __name__ == "__main__":
    main()
