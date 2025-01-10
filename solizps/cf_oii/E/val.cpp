#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    long long t = inf.readInt(1, 1e4, "t");
    inf.readEoln();
    long long tot = 0;
    for (long long t_id = 1; t_id <= t; t_id++) {
        setTestCase(t_id);
        long long n = inf.readInt(3, 5e5, "n");
        tot += n;
        ensuref(tot <= 5e5, "sum(n) too large");
        inf.readEoln();

        vector<vector<long long>> adj(n + 1);
        for (long long i = 1; i <= n - 1; i++) {
            long long u = inf.readInt(1, n, "u");
            inf.readSpace();
            long long v = inf.readInt(1, n, "v");
            ensuref(u != v, "self-loop");
            inf.readEoln();
            adj[u].push_back(v); adj[v].push_back(u);
        }

        vector<bool> vis(n + 1, false);
        function<void(long long)> dfs = [&](long long s) {
            vis[s] = true;
            for (auto u : adj[s]) {
                if (vis[u]) continue;
                dfs(u);
            }
        };

        dfs(1);
        for (long long i = 1; i <= n; i++) {
            ensuref(vis[i] == true, "node i is disconnected");
        }
    }
    inf.readEof();
}
