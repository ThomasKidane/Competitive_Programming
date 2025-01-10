#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        ll n, q; cin >> n >> q;
        vector<ll> x(n + 1, 0);
        for (ll i = 1; i <= n; i++) cin >> x[i];

        vector<array<ll, 2>> v;
        for (ll i = 1; i <= n - 1; i++) {
            v.pb({i * (n - i), x[i + 1] - x[i] - 1});
        }
        for (ll i = 1; i <= n; i++) {
            v.pb({i * (n - i + 1) - 1, 1});
        }

        while (q--) {
            ll x; cin >> x;
            ll ans = 0;
            for (auto [cnt, freq] : v) {
                if (cnt == x) ans += freq;
            }

            cout << ans << ' ';
        }
        cout << nl;
    }

    return 0;
}
