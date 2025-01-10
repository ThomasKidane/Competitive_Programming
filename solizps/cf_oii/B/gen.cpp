#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define ld long double
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ll t = atoi(argv[1]);
    ll n_min = atoi(argv[2]);
    ll n_max = atoi(argv[3]);
    ll q_min = atoi(argv[4]);
    ll q_max = atoi(argv[5]);
    ll a_min = atoi(argv[6]);
    ll a_max = atoi(argv[7]);
    ll k_min = atoll(argv[8]);
    ll k_max = atoll(argv[9]);
    ld good_prob = atof(argv[10]);
    ld range_prob = atof(argv[11]);

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);
        ll q = rnd.next(q_min, q_max);
        vector<ll> a(n + 1, 0);
        for (ll i = 1; i <= n; i++) a[i] = rnd.next(a_min, a_max - n + 1);
        sort(a.begin() + 1, a.end());
        for (ll i = 1; i <= n; i++) a[i] += i - 1;

        cout << n _ q << nl;
        for (ll i = 1; i <= n; i++) {
            cout << a[i];
            if (i == n) cout << nl;
            else cout << ' ';
        }

        for (ll i = 1; i <= q; i++) {
            if (rnd.next(1.0) < good_prob) {
                if (rnd.next(1.0) < 0.5) {
                    ll j = rnd.next((ll)1, n - 1);
                    cout << j * (n - j);
                } else {
                    ll j = rnd.next((ll)1, n);
                    cout << j * (n - j + 1) - 1;
                }
            } else if (rnd.next(1.0) < range_prob) {
                cout << rnd.next((ll)1, (n * (n - 1)) / 2);
            } else {
                cout << rnd.next(k_min, k_max);
            }
            if (i == q) cout << nl;
            else cout << ' ';
        }
    }
}
