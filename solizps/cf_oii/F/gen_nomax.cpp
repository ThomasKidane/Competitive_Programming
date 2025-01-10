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
    ll a_start_min = atoll(argv[4]);
    ll a_start_max = atoll(argv[5]);
    assert(a_start_min > n_max / 2 + 1);

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);

        deque<ll> dq1;
        ll start_len = rnd.next((ll)1, (n - 100) / 4);
        ll start = rnd.next(a_start_min, a_start_max);
        for (ll i = 1; i <= start_len; i++) dq1.pb(start - 1), dq1.pb(start);
        for (ll i = 1; i <= 5; i++) dq1.pb(start - 1);
        deque<ll> dq2 = dq1;
        for (ll i = start - 2;; i--) {
            if (dq1.size() + dq2.size() >= n - 2) break;
            ll dir = rnd.next(1, 3);
            if (dir == 1) dq1.push_front(i), dq1.push_front(i);
            if (dir == 2) dq2.push_front(i), dq2.push_front(i);
            if (dir == 3) dq1.pb(i), dq2.pb(i);
        }

        vector<ll> a(1, 0);
        for (auto u : dq1) a.pb(u);
        for (ll i = 1; i <= (ll)n - dq1.size() - dq2.size(); i++) a.pb(1);
        for (auto u : dq2) a.pb(u);

        cout << n << nl;
        for (ll i = 1; i <= n; i++) {
            cout << a[i];
            if (i == n) cout << nl;
            else cout << ' ';
        }
    }
}
