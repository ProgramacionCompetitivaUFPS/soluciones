ans = [0, 1]
for i in range(5000):
    ans.append(ans[-1] + ans[-2])

while True:
    try:
        n = int(input())
        print(f"The Fibonacci number for {n} is {ans[n]}")
    except:
        break
