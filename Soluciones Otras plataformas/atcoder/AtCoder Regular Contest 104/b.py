n, s = input().split()
ans = 0

for i in range(len(s)):
    a, b = 0, 0
    for j in range(i, len(s)):
        a += (s[j] == 'A')
        a -= (s[j] == 'T')
        b += (s[j] == 'C')
        b -= (s[j] == 'G')
        ans += (a == 0 and b == 0)
print(ans)
