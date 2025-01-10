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
        vector<vector<ll>> adj(n + 1);
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            adj[min(n, a[i])].pb(i);
        }

        ll l = INF, r = -INF;
        ll flag = 1;
        for (ll i = 1; i <= n; i++) {
            for (auto u : adj[i]) {
                l = min(l, u); r = max(r, u);
            }
            if (r - l + 1 > i) flag = 0;
        }

        ll l_ans = 1, r_ans = n;
        for (ll i = 1; i <= n; i++) {
            l_ans = max(l_ans, i - a[i] + 1);
            r_ans = min(r_ans, i + a[i] - 1);
        }

        if (flag == 0 || l_ans > r_ans) cout << 0 << nl;
        else cout << r_ans - l_ans + 1 << nl;
    }

    return 0;
}
