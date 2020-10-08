n = int(input())
eq = 0
for _ in range(n):
    a, b = [int(x) for x in input().split()]
    eq = eq + 1 if a == b else 0
    if eq == 3:
        break
print(["No", "Yes"][eq == 3])
