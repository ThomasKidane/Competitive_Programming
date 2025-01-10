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

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);
        // todo: max_k
        vector<ll> a(n + 1, 0);
        for (ll i = 1; i <= n; i++) a[i] = rnd.next(a_min, a_max);

        cout << n << nl;
        for (ll i = 1; i <= n; i++) {
            cout << a[i];
            if (i == n) cout << nl;
            else cout << ' ';
        }
    }
}
