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
        vector<vector<ll>> adj(n + 1);
        for (ll i = 0; i < n - 1; i++) {
            ll a, b; cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }

        vector<bool> vis(n + 1, false);
        vector<ll> depth(n + 1, 0), max_depth(n + 1, 0);

        function<void(ll)> dfs = [&](ll s) {
            vis[s] = true;
            for (auto u : adj[s]) {
                if (vis[u]) continue;
                depth[u] = depth[s] + 1;
                dfs(u);
                max_depth[s] = max(max_depth[s], max_depth[u]);
            }
            max_depth[s] = max(max_depth[s], depth[s]);
        };

        dfs(1);

        vector<ll> sweep(n + 2, 0);
        for (ll i = 1; i <= n; i++) {
            sweep[depth[i]]++; sweep[max_depth[i] + 1]--;
        }

        for (ll i = 1; i <= n + 1; i++) sweep[i] += sweep[i - 1];

        ll ans = n - (*max_element(sweep.begin(), sweep.end()));
        cout << ans << nl;
    }

    return 0;
}
