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
        ll n, k; cin >> n >> k;
        vector<ll> a(n + 1, 0);
        ll mx = 0, tot = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i]; mx = max(mx, a[i]); tot += a[i];
        }

        ll ans = 0;
        for (ll sz = 1; sz <= n; sz++) {
            if (tot + k < mx * sz) continue; 
            ans = max(ans, sz);
        }

        cout << ans << nl;
    }

    return 0;
}
