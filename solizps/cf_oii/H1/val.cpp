#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    ll t = inf.readInt(1, 80, "t");
    inf.readEoln();
    ll tot = 0;

    auto prime = [&](ll x) {
        for (ll i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    };

    for (ll t_id = 1; t_id <= t; t_id++) {
        setTestCase(t_id);
        ll n = inf.readInt(1, 80, "n");
        tot += n;
        ensuref(tot <= 80, "sum(n) too large");
        inf.readSpace();
        ll p = inf.readInt(1e8, 1e9, "p");
        ensuref(prime(p), "p is not prime");
        inf.readEoln();
    }
    inf.readEof();
}
