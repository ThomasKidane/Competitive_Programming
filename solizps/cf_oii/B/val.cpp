#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    long long t = inf.readInt(1, 1e4, "t");
    inf.readEoln();
    long long tot_n = 0, tot_q = 0;
    for (long long t_id = 1; t_id <= t; t_id++) {
        setTestCase(t_id);
        long long n = inf.readInt(2, 1e5, "n");
        tot_n += n;
        ensuref(tot_n <= 1e5, "sum(n) too large");
        inf.readSpace();
        long long q = inf.readInt(1, 1e5, "q");
        tot_q += q;
        ensuref(tot_q <= 1e5, "sum(q) too large");
        inf.readEoln();

        vector<long long> x(n + 1, 0);
        for (long long i = 1; i <= n; i++) {
            x[i] = inf.readInt(1, 1e9, "x_i");
            if (i >= 2) ensuref(x[i] > x[i - 1],
                "coordinates not increasing");
            if (i == n) inf.readEoln();
            else inf.readSpace();
        }

        for (long long i = 1; i <= q; i++) {
            inf.readLong(1, (long long)1e18, "k_i");
            if (i == q) inf.readEoln();
            else inf.readSpace();
        }
    }
    inf.readEof();
}
