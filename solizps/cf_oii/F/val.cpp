#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    long long t = inf.readInt(1, 1e4, "t");
    inf.readEoln();
    long long tot = 0;
    for (long long t_id = 1; t_id <= t; t_id++) {
        setTestCase(t_id);
        long long n = inf.readInt(1, 2e5, "n");
        tot += n;
        ensuref(tot <= 2e5, "sum(n) too large");
        inf.readEoln();
        for (long long i = 1; i <= n; i++) {
            inf.readInt(1, 1e9, "a_i");
            if (i == n) inf.readEoln();
            else inf.readSpace();
        }
    }
    inf.readEof();
}
