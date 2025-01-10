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
            ll a, b; cin >> a >> b; a--; b--;
            adj[a].pb(b); adj[b].pb(a);
        }

        vector<bool> vis(n, false);
        vector<ll> depth(n, 0), parent(n, 0);

        function<void(ll)> dfs = [&](ll s) {
            vis[s] = true;
            for (auto u : adj[s]) {
                if (vis[u]) continue;
                depth[u] = depth[s] + 1;
                parent[u] = s;
                dfs(u);
            }
        };

        dfs(0);

        auto try_depth = [&](ll d) {
            ll ans = n;
            vector<bool> marked(n, false);
            for (ll i = 0; i < n; i++) {
                if (depth[i] != d) continue;
                for (ll j = i; marked[j] == false; j = parent[j]) {
                    marked[j] = true; ans--;
                }
            }
            return ans;
        };

        ll ans = n;
        for (ll i = 1; i <= n; i++) ans = min(ans, try_depth(i));
        cout << ans << nl;
    }

    return 0;
}
