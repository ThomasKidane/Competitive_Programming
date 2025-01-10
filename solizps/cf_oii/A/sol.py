t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    a = [0] * (n + 1)
    a[1:] = list(map(int, input().split()))

    ans = 0
    for i in range(1, n + 1):
        sz = n // 2 + (n % 2 == 1 and i % 2 == 1)
        ans = max(ans, a[i] + sz)

    print(ans)
