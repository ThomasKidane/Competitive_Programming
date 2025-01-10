#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    long long t = inf.readInt(1, 1e3, "t");
    inf.readEoln();
    long long tot = 0;
    for (long long t_id = 1; t_id <= t; t_id++) {
        setTestCase(t_id);
        long long n = inf.readInt(1, 3e5, "n");
        tot += n;
        ensuref(tot <= 3e5, "sum(n) too large");
        inf.readEoln();

        vector<long long> l(n + 1, 0), r(n + 1, 0);
        for (long long i = 1; i <= n; i++) {
            l[i] = inf.readInt(1, 2 * n, "l_i");
            if (i == n) inf.readEoln();
            else inf.readSpace();
        }
        for (long long i = 1; i <= n; i++) {
            r[i] = inf.readInt(1, 2 * n, "r_i");
            ensuref(l[i] <= r[i], "l_i > r_i");
            if (i == n) inf.readEoln();
            else inf.readSpace();
        }
    }
    inf.readEof();
}
