#include "testlib.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ff = double;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

constexpr long long INF = 1e18;

void shuffle_and_print(ll n, vector<pair<ll, ll>>& e) {
    shuffle(e.begin(), e.end());

    vector<ll> p(n);
    iota(p.begin(), p.end(), 0);
    // Node 0 is the root, so we don't want to shuffle it.
    shuffle(p.begin() + 1, p.end());

    vector<ll> a, b;
    for (auto [x, y] : e) {
        if (rnd.next(0, 1)) {
            swap(x, y);
        }
        a.push_back(p[x]);
        b.push_back(p[y]);
    }

    assert(n - 1 == a.size());
    cout << n << endl;
    for (ll i = 0; i < n - 1; i++) {
        cout << a[i] + 1 << " " << b[i] + 1 << endl;
    }
}

static void generator1(int argc, char** argv) {
    assert(argc >= 6);

    ll t = atoi(argv[2]);
    ll n_min = atoi(argv[3]);
    ll n_max = atoi(argv[4]);
    ll elong = atoi(argv[5]);

    cout << t << endl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);
        vector<ll> p(n);

        // Set up parents for vertices 1, ..., n - 1.
        for (ll i = 1; i < n; ++i) {
            p[i] = rnd.wnext(i, elong);
        }

        // Add edges considering shuffled vertices.
        vector<pair<ll, ll>> edges;
        set<pair<ll, ll>> visited;
        for (ll i = 1; i < n; i++) {
            edges.emplace_back(i, p[i]);
            visited.insert({p[i], i});
        }

        shuffle_and_print(n, edges);
    }
}

static void generator2(int argc, char** argv) { // star
    assert(argc >= 8);

    ll t = atoi(argv[2]);
    ll n_min = atoi(argv[3]);
    ll n_max = atoi(argv[4]);
    ll elong = atoi(argv[5]);
    ll max_depth = atoi(argv[6]);
    ll stretch = atoi(argv[7]);
    ll add_rand = atoi(argv[8]);

    cout << t << endl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);
        assert(add_rand <= n);

        ll rem = n - 1 - add_rand;
        vector<ll> branches;
        // Generate branches randomly.
        while (rem != 0) {
            ll len = rnd.next((ll)1, min(rem, max_depth));
            len *= pow(rnd.next(1.0), stretch);
            len = max(len, (ll)1);
            len = min(len, max_depth);
            branches.push_back(len); rem -= len;
        }

        vector<ll> p(n);

        // Assign parents according to branch lengths.
        ll curr = 1;
        for (auto u : branches) {
            p[curr] = 0;
            for (ll i = curr + 1; i <= curr + u - 1; i++) {
                p[i] = i - 1;
            }
            curr += u;
        }

        // Add additional random edges.
        for (ll i = n - add_rand; i < n; i++) {
            p[i] = rnd.wnext(i, elong);
        }

        // Add edges considering shuffled vertices.
        vector<pair<ll, ll>> edges;
        set<pair<ll, ll>> visited;
        for (ll i = 1; i < n; i++) {
            edges.emplace_back(i, p[i]);
            visited.insert({p[i], i});
        }

        shuffle_and_print(n, edges);
    }
}

static void generator3(int argc, char** argv) { // small answer, maybe also good for bigger answer
    assert(argc >= 11);

    ll t = atoi(argv[2]);
    ll n_min = atoi(argv[3]);
    ll n_max = atoi(argv[4]);
    ll elong = atoi(argv[5]);
    ll target_depth = atoi(argv[6]);
    ll add_rand = atoi(argv[7]);
    ll add_bottom = atoi(argv[8]);
    ll add_bottom_chain = atoi(argv[9]);
    ll max_leaves = atoi(argv[10]);
    ll additional = add_rand + add_bottom;

    cout << t << endl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);
        assert(n >= additional);

        vector<ll> p(n), depth(n, 0);
        ordered_set leaves;
        leaves.insert(0);
        ll i = 1;

        auto add_edge = [&](ll parent) {
            p[i] = parent; depth[i] = depth[parent] + 1;
            leaves.erase(parent); leaves.insert(i);
            i++;
        };

        while (i < n) {
            assert(leaves.size() <= max_leaves);

            if (leaves.size() == max_leaves) {
                ll pos = rnd.wnext(max_leaves, elong);
                ll parent = *leaves.find_by_order(pos);
                add_edge(parent);
            } else if (i < n - additional) {
                // It looks weird but it's O(nlog(n)) on average.
                while (true) {
                    // Every time you add a new node, add a chain until target_depth.
                    ll parent = rnd.wnext(i, elong);
                    ll len = target_depth - depth[parent];
                    if (i + len > n - additional) continue;
                    if (len == 0) continue;
                    add_edge(parent);
                    for (ll j = 1; j < len; j++) {
                        add_edge(i - 1);
                    }
                    break;
                }
            } else if (i < n - add_bottom) {
                // Add new edges (to be removed in the solution).
                add_edge(rnd.wnext(i, elong));
            } else {
                // We might want to add edges to leaves to avoid (final depth) = (max depth).
                vector<ll> candidates;
                for (ll j = 0; j < i; j++) {
                    if (depth[j] >= target_depth) candidates.push_back(j);
                }

                // Add a chain of random length to a node with big depth.
                ll start = candidates[rnd.next((ll)0, (ll)candidates.size() - 1)];
                ll len = min(n - i, rnd.next((ll)1, add_bottom_chain));
                add_edge(start);
                for (ll j = 1; j < len; j++) {
                    add_edge(i - 1);
                }
            }
        }

        // Add edges considering shuffled vertices.
        vector<pair<ll, ll>> edges;
        set<pair<ll, ll>> visited;
        for (ll i = 1; i < n; i++) {
            edges.emplace_back(i, p[i]);
            visited.insert({p[i], i});
        }

        shuffle_and_print(n, edges);
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    assert(argc >= 2);

    ll type = atoi(argv[1]);

    switch (type) {
        case 1:
            generator1(argc, argv);
            break;
        case 2:
            generator2(argc, argv);
            break;
        case 3:
            generator3(argc, argv);
            break;
        default:
            cerr << "Usage: ./" << argv[0] << " type:(1|2|3) [other params]" << endl;
    }
}
