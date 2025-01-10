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

static constexpr int MAXN = 2.5e4;
static constexpr int MAXT = 2 * MAXN;
static constexpr int THRESHOLD = 600;	// about sqrt{n log n}
static constexpr int THRESHOLD2 = 256;

struct Segment {
	struct Node {
		int mx;
		int lz;
		Node(int _mx = 0, int _lz = 0)
			: mx(_mx), lz(_lz) {}
	};

	int n;
	vector<Node> t;

	Segment(int _n) {
		for (n = 1; n < _n; n <<= 1);
		t.resize(2 * n);
	}

	void prop(int i) {
		if (t[i].lz && i < n) {
			t[2*i  ].mx += t[i].lz;
			t[2*i+1].mx += t[i].lz;
			t[2*i  ].lz += t[i].lz;
			t[2*i+1].lz += t[i].lz;
			t[i].lz = 0;
		}
	}

	void upd(int i, int a, int b, int l, int r, int x) {
		prop(i);
		if (b <= l || r <= a) return;
		if (l <= a && b <= r) {
			t[i].mx += x;
			t[i].lz += x;
		} else {
			int m = (a + b) / 2;
			upd(2*i  , a, m, l, r, x);
			upd(2*i+1, m, b, l, r, x);
			t[i].mx = max(t[2*i].mx, t[2*i+1].mx);
		}
	}

	int get_max() {
		return t[1].mx;
	}
};

struct MySegment : public Segment {
	vector<array<int, 3>> upds;

	MySegment(int n) : Segment(n) {}

	void add(int l, int r, int x) {
		upds.push_back({l, r, x});
		upd(1, 0, n, l, r, x);
	}
	void clean() {
		for (auto [l, r, x] : upds) {
			upd(1, 0, n, l, r, -x);
		}
		upds.clear();
	}
};

int maxpartition(int n, vector<int> l, vector<int> r) {
	vector<int> idxs(n);
	iota(begin(idxs), end(idxs), 0);
	sort(begin(idxs), end(idxs), [&](int i, int j){ return r[i] < r[j]; });

	MySegment st(2 * n + 1);
	auto max_k = [&](int m) -> int {
		// return max{k : one can form k subsets of m elements each}
		int k = 0;
		int last_r = -1;
		for (int i : idxs) {
			if (l[i] <= last_r) continue;
			st.add(l[i], r[i]+1, 1);
			if (st.get_max() >= m) {
				++k;
				last_r = r[i];
				st.clean();
			}
		}
		st.clean();
		return k;
	};

	int ans = 1;
	for (int m = 1; m <= min(n, THRESHOLD); ++m)
		ans = max(ans, m * max_k(m));
	for (int k = 1; k <= n / THRESHOLD; ++k) {
		int bsl = 0, bsu = n + 1;
		while (bsu - bsl > 1) {
			int bsm = (bsl + bsu) / 2;
			if (max_k(bsm) >= k)
				bsl = bsm;
			else
				bsu = bsm;
		}
		ans = max(ans, k * bsl);
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
