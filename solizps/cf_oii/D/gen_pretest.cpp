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
    ll n_max = atoi(argv[2]);
    vector<vector<ll>> tests;

    auto gen_all = [&](ll n) {
        vector<vector<vector<ll>>> all(n + 1);
        all[0].pb({0});
        for (ll i = 1; i <= n; i++) {
            for (auto v : all[i - 1]) {
                for (ll j = 1; j <= n; j++) {
                    v.pb(j); all[i].pb(v); v.pop_back();
                }
            }
        }

        for (auto v : all[n]) tests.pb(v);
    };

    for (ll i = 1; i <= n_max; i++) gen_all(i);
    t = min(t, (ll)tests.size());
    shuffle(tests.begin(), tests.end());

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        vector<ll> a = tests[t_id - 1];
        ll n = (ll)a.size() - 1;

        cout << n << nl;
        for (ll i = 1; i <= n; i++) {
            cout << a[i];
            if (i == n) cout << nl;
            else cout << ' ';
        }
    }
}
