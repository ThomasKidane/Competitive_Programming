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
        ll mx = 0;
        for (ll i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);

        vector<ll> pr(n + 1, 0), sz(n + 1, 0);
        iota(pr.begin(), pr.end(), 0);
        vector<ll> mx_even(n + 1, 0), mx_odd(n + 1, 0);

        function<ll(ll)> find = [&](ll x) {
            if (x == pr[x]) return x;
            return pr[x] = find(pr[x]);
        };

        ll total_sz = 0, cnt_mx = 0;

        auto toggle = [&](ll x) {
            sz[x] = 1; total_sz++;
            if (a[x] == mx) mx_even[x] = 1, cnt_mx++;
        };

        auto is_mx = [&](ll a) {
            if (mx_even[a]) return true;
            if (sz[a] % 2) return false;
            if (mx_odd[a]) return true;
            return false;
        };

        function<void(ll, ll)> onion = [&](ll a, ll b) {
            if (a <= 0 || a > n || b <= 0 || b > n) return;

            a = find(a); b = find(b);
            if (a == b) return;
            if (a > b) swap(a, b);
            pr[b] = a;

            total_sz -= (sz[a] + 1) / 2; total_sz -= (sz[b] + 1) / 2;
            cnt_mx -= (is_mx(a) + is_mx(b));

            if (sz[a] % 2) {
                mx_even[a] |= mx_odd[b]; mx_odd[a] |= mx_even[b];
            } else {
                mx_even[a] |= mx_even[b]; mx_odd[a] |= mx_odd[b];
            }
            sz[a] += sz[b];

            total_sz += (sz[a] + 1) / 2;
            cnt_mx += (is_mx(a));
        };

        map<ll, vector<ll>> events;
        for (ll i = 1; i <= n; i++) events[-a[i]].pb(i);

        ll ans = 0;
        for (auto [val, v] : events) {
            for (auto pos : v) toggle(pos);
            for (auto pos : v) {
                if (pos - 1 >= 1 && a[pos - 1] >= a[pos]) {
                    onion(pos - 1, pos);
                }
                if (pos + 1 <= n && a[pos + 1] >= a[pos]) {
                    onion(pos, pos + 1);
                }
            }

            ans = max(ans, mx - val + total_sz - (cnt_mx == 0));
        };

        cout << ans << nl;
    }

    return 0;
}
