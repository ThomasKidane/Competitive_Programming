#!/usr/bin/env python3

from limiti import *

from sys import argv, exit, stderr
import os
import math
from random import choice, sample, shuffle, seed, random, randint, choices

"""
Possibli lamerate a cui rendere la vita difficile:
    * assumere M piccolo
    * assumere M in un range
    * assumere che i testcase siano fatti male e, quando M è artificialmente,
      grande, ci sono pochi intervalli distinti
"""

def run(N, st, gen_type):
    for k, v in subtask[st].items():
        globals()[k] = v

    l, r = [], []

    MAXT = 10**9 # poi comprimo

    if Keq2:
        # fissa tre punti x1 < x2 < x3. x1, x2 saranno di intersezione
        # gli intervalli di sinistra sono contenuti in [1, x3-1], gli altri
        # in [x3+1, MAXT]. La risposta consiste di M intervalli contenuti in
        # [1, x3-1] e altrettanti contenuti in [x3+1, MAXT]. I restanti N - 2*M
        # intervalli si possono piazzare a caso senza alterare la risposta, a
        # patto che M > N/3.
        x2 = randint(1, MAXT)
        while x2 == 1 or x2 == MAXT:
            x2 = randint(1, MAXT)
        x1 = randint(1, x2 - 1)
        x3 = randint(x2 + 1, MAXT)

        M = randint(N//3 + 1, N // 2);
        for i in range(M):
            l.append(randint(1, x1))
            r.append(randint(x1, x2 - 1))
        for i in range(M):
            l.append(randint(x2 + 1, x3))
            r.append(randint(x3, MAXT))
        for i in range(N - 2 * M):
            l.append(randint(1, MAXT))
            r.append(randint(1, MAXT))
            if r[-1] < l[-1]:
                l[-1], r[-1] = r[-1], l[-1]
    else:
        l = [randint(1, MAXT) for x in range(N)]
        r = [randint(1, MAXT) for x in range(N)]
        for i in range(N):
            if r[i] < l[i]:
                l[i], r[i] = r[i], l[i]
        if gen_type == 1:           # max_k(m) assume Theta(sqrt(n)) valori distinti
            Gauss = lambda x : x * (x + 1) // 2
            t = 1
            while Gauss(t) <= N:
                mid = 30 * Gauss(t) # punto di intersezione del blocco da t
                for i in range(t):
                    l[Gauss(t-1) + i] = randint(mid - 10*t, mid)
                    r[Gauss(t-1) + i] = randint(mid, mid + 10*t)
                t += 1
        elif gen_type == 2:         # M grande
            for i in range(randint(int(N*0.9), N)):
                l[i] = randint(1, N)
                r[i] = N + randint(1, N)
        elif gen_type == 3:
            for i in range(randint(int(N*0.9), N)):
                l[i] = 2 * i
                r[i] = 2 * i + 1
        elif gen_type == 4:
            M = randint(1, N)
            K = N // M;
            for i in range(K):
                mid = 30 * M * (i + 1)
                for j in range(M):
                    l[i * K + j] = randint(mid - 10 * M, mid)
                    r[i * K + j] = randint(mid, mid + 10 * M)

    # coordinate compression
    z = l + r;
    zz = sorted(set(z))
    mp = {value: index for index, value in enumerate(zz)}
    for i in range(N):
        l[i] = 1 + mp[l[i]]
        r[i] = 1 + mp[r[i]]

    print(N)
    print(' '.join(str(x) for x in l))
    print(' '.join(str(x) for x in r))

if __name__ == "__main__":
    *args, S = map(int, argv[1:])

    seed(S)
    run(*args)
