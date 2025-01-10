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
    ll type = atoi(argv[4]);

    auto gauss = [&](ll x) {
        return (x * (x + 1)) / 2;
    };

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);
        vector<int> l(n, 0), r(n, 0);
        const int MAXT = 1000000000; // Compress limit

        for (int i = 0; i < n; ++i) {
            l[i] = rnd.next(1, MAXT);
            r[i] = rnd.next(1, MAXT);
            if (r[i] < l[i]) swap(l[i], r[i]);
        }

        if (type == 1) {  // max_k(m) assume Theta(sqrt(n)) valori distinti
            int t = 1;
            while (gauss(t) <= n) {
                int mid = 30 * gauss(t); // Punto di intersezione del blocco da t
                for (int i = 0; i < t; ++i) {
                    l[gauss(t - 1) + i] = rnd.next(mid - 10 * t, mid);
                    r[gauss(t - 1) + i] = rnd.next(mid, mid + 10 * t);
                }
                ++t;
            }
        } else if (type == 2) {  // M grande
            for (int i = 0; i < rnd.next((ll)(n * 0.9), n); ++i) {
                l[i] = rnd.next((ll)1, n);
                r[i] = n + rnd.next((ll)1, n);
            }
        } else if (type == 3) {
            for (int i = 0; i < rnd.next((ll)(n * 0.9), n); ++i) {
                l[i] = 2 * i;
                r[i] = 2 * i + 1;
            }
        } else if (type == 4) {
            int m = rnd.next((ll)1, n);
            int k = n / m;
            for (int i = 0; i < k; ++i) {
                int mid = 30 * m * (i + 1);
                for (int j = 0; j < m; ++j) {
                    l[i * m + j] = rnd.next(mid - 10 * m, mid);
                    r[i * m + j] = rnd.next(mid, mid + 10 * m);
                }
            }
        } else if (type == 5) {
            ll maxc = atoi(argv[5]);
            ll maxl = atoi(argv[6]);
            assert(maxl <= maxc);
            for (int i = 0; i < n; ++i) {
                ll len = rnd.next((ll)0, maxl);
                l[i] = rnd.next((ll)1, maxc - len);
                r[i] = l[i] + len;
            }
        }

        // Coordinate compression
        vector<int> z = l;
        z.insert(z.end(), r.begin(), r.end());
        sort(z.begin(), z.end());
        z.erase(unique(z.begin(), z.end()), z.end());

        vector<int> targets(z.size(), 0);
        for (int i = 0; i < z.size(); i++) {
            targets[i] = rnd.next((ll)1, 2 * n - (ll)z.size() + 1);
        }
        sort(targets.begin(), targets.end());
        for (int i = 0; i < z.size(); i++) targets[i] += i;

        map<int, int> mp;
        for (int i = 0; i < z.size(); ++i) {
            mp[z[i]] = targets[i];
        }

        for (int i = 0; i < n; ++i) {
            l[i] = mp[l[i]];
            r[i] = mp[r[i]];
        }

        // Output
        cout << n << nl;
        for (int i = 0; i < n; ++i) {
            cout << l[i];
            if (i == n - 1) cout << nl;
            else cout << ' ';
        }
        for (int i = 0; i < n; ++i) {
            cout << r[i];
            if (i == n - 1) cout << nl;
            else cout << ' ';
        }
    }
}
