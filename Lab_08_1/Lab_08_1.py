def scan_comma_dash(s):
    for i in range(len(s) - 1):
        if s[i] == "," and s[i+1] == "-":
            return True
    return False

def qty_comma_dash(s):
    q = 0
    for i in range(len(s) - 1):
        if s[i] == "," and s[i+1] == "-":
            q += 1
    return q

def replace_comma_dash(s):
    i = 0
    result = ''
    while i < len(s) - 1:             
        if s[i] == "," and s[i+1] == "-":
            result += "*"
            i += 2
        else:
            result += s[i]
            i += 1
    result += s[i:]                    
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
