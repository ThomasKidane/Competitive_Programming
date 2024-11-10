import math

def solve():
    n, k = map(int, input().split())
    c = 0

    if k > n or k == 1:
        print(n)
        return

    while n:
        if n < k:
            c += n
            break

        
        power = math.floor(math.log10(n) / math.log10(k))

        
        n -= pow(k, power)
        c += 1

    print(c)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solve()