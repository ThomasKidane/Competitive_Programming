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
        ll n; cin >> n;
        vector<ll> a(n + 1, 0);
        for (ll i = 1; i <= n; i++) cin >> a[i];

        auto brute = [&]() {
            vector<vector<vector<ll>>> all(n + 1);
            all[0].pb({0});
            for (ll i = 1; i <= n; i++) {
                for (auto v : all[i - 1]) {
                    for (ll j = 0; j <= 1; j++) {
                        v.pb(j);
                        if (v[i] == 0 || v[i - 1] == 0) {
                            all[i].pb(v);
                        }
                        v.pop_back();
                    }
                }
            }

            auto solve = [&](vector<ll> v) {
                ll ans = 0;
                for (ll i = 1; i <= n; i++) ans = max(ans, a[i] * v[i]);
                for (ll i = 1; i <= n; i++) ans += v[i];

                return ans;
            };

            ll ans = 0;
            for (auto v : all[n]) ans = max(ans, solve(v));

            return ans;
        };

        cout << brute() << nl;
    }

    return 0;
}
