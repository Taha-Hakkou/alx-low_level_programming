#!/usr/bin/python3
def is_palindrome(n):
    return str(n) == ''.join(reversed(str(n)))

pal = 10001
for i in range(100, 999):
    for j in range(100, 999):
        p = i * j
        if is_palindrome(p) and p > pal:
            pal = p
            print(pal)
print(pal)
