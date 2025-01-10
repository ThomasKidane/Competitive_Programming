from collections import defaultdict

t = int(input())

while t > 0:
    t -= 1
    n, q = map(int, input().split())
    x = [0] * (n + 1)
    x[1:] = list(map(int, input().split()))

    mp = defaultdict(int)

    for i in range(1, n):
        mp[i * (n - i)] += (x[i + 1] - x[i] - 1)

    for i in range(1, n + 1):
        mp[i * (n - i + 1) - 1] += 1

    queries = [0] * (n + 1)
    queries[1:] = list(map(int, input().split()))

    for i in range(1, q + 1):
        print(mp[queries[i]], end=' ')
    print()
