from collections import defaultdict

INF = int(1e18)

t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    a = [0] * (n + 1)
    a[1:] = list(map(int, input().split()))
    adj = defaultdict(list)

    for i in range(1, n + 1):
        adj[min(n, a[i])].append(i)

    l = INF
    r = -INF
    l_ans = -INF
    r_ans = INF
    flag = True

    for i in range(1, n + 1):
        for u in adj[i]:
            l = min(l, u)
            r = max(r, u)

        if l == INF:
            continue

        if r - l + 1 > i:
            flag = False

        l_ans = max(l_ans, r - i + 1)
        r_ans = min(r_ans, l + i - 1)

    if not flag or l_ans > r_ans:
        print(0)
    else:
        print(r_ans - l_ans + 1)
