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

        map<ll, ll> mp;
        for (ll i = 1; i <= n - 1; i++) {
            mp[i * (n - i)] += (x[i + 1] - x[i] - 1);
        }
        for (ll i = 1; i <= n; i++) {
            mp[i * (n - i + 1) - 1]++;
        }

        while (q--) {
            ll x; cin >> x;
            cout << mp[x] << ' ';
        }
        cout << nl;
    }

    return 0;
}
