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
    ll n_min = atoi(argv[2]);
    ll n_max = atoi(argv[3]);
    ll a_min = atoll(argv[4]);
    ll a_max = atoll(argv[5]);
    ll k_min = atoll(argv[6]);
    ll k_max = atoll(argv[7]);
    ll elong = atoll(argv[8]);

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);
        ll k = rnd.next(k_min, k_max);

        vector<ll> a(n + 1, 0);
        ll tot = 0;
        for (ll i = 1; i <= n; i++) {
            ll nw_elong = (double)elong * rnd.next(1.0);
            a[i] = rnd.wnext(a_min, a_max, nw_elong);
            tot += a[i];
        }

        if (tot == 0) a[rnd.next((ll)1, n)] = 1;

        cout << n _ k << nl;
        for (ll i = 1; i <= n; i++) {
            cout << a[i];
            if (i == n) cout << nl;
            else cout << ' ';
        }
    }
}
