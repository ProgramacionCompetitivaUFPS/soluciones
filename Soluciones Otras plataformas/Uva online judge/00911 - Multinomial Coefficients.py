fac = [1]
while True:
    try:
        n = int(input())
        k = int(input())
        i = len(fac)
        while i <= n:
            fac.append(fac[-1]*i)
            i += 1
        a = list(map(int, input().strip().split()))
        num = fac[n]
        den = 1
        for i in a:
            den *= fac[i]
        print(num//den)
    except:
        break
