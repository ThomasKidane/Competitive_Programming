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

int N;

struct DSU {
    int cc;
    vector<int> arr, ans;

    int find(int node) {
        if (arr[node] < 0) return node;
        return arr[node] = find(arr[node]);
    }

    void join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        cc--;

        if (arr[u] > arr[v]) swap(u, v);

        arr[u] += arr[v];
        arr[v] = u;
        ans[u] = min(ans[u], ans[v]);
    }

    void reset() {
        ans.resize(2 * N + 1);
        arr.assign(2 * N + 1, -1);
        iota(ans.begin(), ans.end(), 0);
        cc = 2 * N + 1;
    }
};

DSU dsu;
vector<pair<int, int>> rangers;

int max_groups(int group_size) {
    dsu.reset();

    int curr_l = 0;
    int last_r = 1;
    int cnt = 0;
    int actual_l = 0;

    for (auto [l, r]: rangers) {
        if (l < curr_l) continue;

        while (last_r < r - 1) {
            dsu.join(last_r, last_r - 1);
            last_r++;
        }
        last_r++;

        int fake = dsu.ans[dsu.find(l - 1)];
        if (fake > actual_l)
            dsu.join(fake, fake - 1);

        if (dsu.cc - (2 * N + 1 - r) - cnt - 1 == group_size) {
            cnt++;
            curr_l = r;

            int curr = r - 1;
            while (curr != actual_l) {
                dsu.join(curr, curr - 1);
                curr = dsu.ans[dsu.find(curr)];
            }

            actual_l = last_r;
            last_r++;
        }
    }

    return cnt;
}

int maxpartition(int N, vector<int> L, vector<int> R) {
    ::N = N;
    vector<array<int, 3>> positions(2 * N);
    for (int i = 0; i < N; i++) {
        positions[2 * i] = {L[i], 0, i};
        positions[2 * i + 1] = {R[i], 1, i};
    }

    sort(positions.begin(), positions.end());

    rangers.resize(N);
    for (int i = 0; i < 2 * N; i++) {
        auto [z, wh, pos] = positions[i];
        if (!wh) rangers[pos].first = i + 1;
        else rangers[pos].second = i + 2;
    }

    sort(rangers.begin(), rangers.end(), [&](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    int ans = 0;
    function<void(int, int, int, int)> solve =
        [&](int tl, int tr, int al, int ar) {
        if (tl > tr) return;
        if (al == ar) {
            ans = max(ans, tr * ar); return;
        }

        int tm = (tl + tr) / 2;
        int am = max_groups(tm);
        ans = max(ans, tm * am);
        solve(tl, tm - 1, am, ar); solve(tm + 1, tr, al, am);
    };

    solve(1, N, 0, N);

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
