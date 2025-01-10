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

int maxpartition(int n, vector<int> l, vector<int> r) {
	assert(n <= 20);

	vector<int> idxs(n);
	iota(begin(idxs), end(idxs), 0);
	sort(begin(idxs), end(idxs), [&](int i, int j){ return r[i] < r[j]; });

	auto valid = [&](vector<int> subset) -> bool {
		vector<vector<int>> sets;
		vector<int> cur;
		for (int i : subset) {
			if (cur.empty() || l[i] <= r[cur[0]]) {
				cur.push_back(i);
			} else {
				sets.push_back(cur);
				cur = {i};
			}
		}
		sets.push_back(cur);
		for (int i = 1; i < (int)sets.size(); ++i) {
			if (sets[i].size() != sets[0].size()) {
				return false;
			}
			for (int j : sets[i]) {
				if (l[j] <= r[sets[i - 1].back()]) {
					return false;
				}
			}
		}

		return true;
	};

	int ans = 1;
	for (int mask = 1; mask < (1 << n); ++mask) {
		vector<int> subset;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				subset.push_back(idxs[i]);
			}
		}
		if (valid(subset)) {
			ans = max(ans, (int)subset.size());
		}
	}

	return ans;
}

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
        vector<int> l(n, 0), r(n, 0);
        for (ll i = 0; i < n; i++) cin >> l[i];
        for (ll i = 0; i < n; i++) cin >> r[i];

        ll ans = maxpartition(n, l, r);
        cout << ans << nl;
    }

    return 0;
}
