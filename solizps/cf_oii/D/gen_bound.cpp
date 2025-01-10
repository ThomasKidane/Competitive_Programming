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

#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ll t = atoll(argv[1]);
    ll n_min = atoll(argv[2]);
    ll n_max = atoll(argv[3]);
    ll ans_min = atoll(argv[4]);
    ll ans_max = atoll(argv[5]);
    assert(ans_max <= n_min);

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);
        ll ans = rnd.next(ans_min, ans_max);

        vector<ll> a(n + 1, 0);
        if (ans == 0) {
            for (ll i = 1; i <= n; i++) a[i] = rnd.next((ll)1, n);
        } else {
            ll l = rnd.next((ll)1, n - ans + 1);
            ll r = l + ans - 1;
            ll cl = rnd.next(l, r);
            ll cr = cl;
            a[cl] = rnd.next(max(cl - l + 1, r - cl + 1), n);
            for (ll i = 2; i <= n; i++) {
                if (rnd.next(1, 2) == 1) {
                    if (cl == 1) {
                        i--; continue;
                    }
                    cl--;
                    a[cl] = rnd.next(max({i, cl - l + 1, r - cl + 1}), n);
                } else {
                    if (cr == n) {
                        i--; continue;
                    }
                    cr++;
                    a[cr] = rnd.next(max({i, cr - l + 1, r - cr + 1}), n);
                }
            }
        }

        cout << n << nl;
        for (ll i = 1; i <= n; i++) {
            cout << a[i];
            if (i == n) cout << nl;
            else cout << ' ';
        }
    }
}
