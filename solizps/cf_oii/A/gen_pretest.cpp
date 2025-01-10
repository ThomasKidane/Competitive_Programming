#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ll t = atoi(argv[1]);
    ll types = atoi(argv[2]);
    vector<ll> N_MIN(types + 1, 0), N_MAX(types + 1, 0);
    vector<ll> A_MIN(types + 1, 0), A_MAX(types + 1, 0);
    for (ll i = 1; i <= types; i++) {
        N_MIN[i] = atoi(argv[4 * i - 1]);
        N_MAX[i] = atoi(argv[4 * i]);
        A_MIN[i] = atoi(argv[4 * i + 1]);
        A_MAX[i] = atoi(argv[4 * i + 2]);
    }

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll type = rnd.next((ll)1, types);
        ll n_min = N_MIN[type], n_max = N_MAX[type];
        ll a_min = A_MIN[type], a_max = A_MAX[type];
        ll n = rnd.next(n_min, n_max);
        ll a_partial_max = rnd.next(a_min, a_max);
        vector<ll> a(n + 1, 0);
        for (ll i = 1; i <= n; i++) a[i] = rnd.next(a_min, a_partial_max);

        cout << n << nl;
        for (ll i = 1; i <= n; i++) {
            cout << a[i];
            if (i == n) cout << nl;
            else cout << ' ';
        }
    }
}
