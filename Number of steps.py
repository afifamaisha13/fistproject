n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

value = min(a)
i = 0
c = 0

while i < n:
    if a[i] >= b[i]:
        while a[i] > value:
            a[i] -= b[i]
            c += 1

    if a[i] != value:
        c = -1
        break
    i += 1

print(c)
