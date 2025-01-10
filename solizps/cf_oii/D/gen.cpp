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

#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// Function to determine if the configuration is solvable
bool solve(int N, const vector<int>& T) {
    // Create a list of events as pairs (t, i)
    vector<pair<int, int>> events;
    for(int i = 0; i < N; ++i){
        events.emplace_back(T[i], i);
    }

    // Sort events based on t (ascending order)
    sort(events.begin(), events.end());

    int l = N;
    int r = -1;

    // Iterate through each event
    for(auto &[t, i] : events){
        l = min(l, i);
        r = max(r, i);

        if(r - l > t){
            return false;
        }
    }
    return true;
}

// Function to generate a smart configuration
vector<int> gen_smart(int N, int start, double p) {
    // If start is -1, choose a random starting index
    if(start == -1){
        start = rnd.next(0, N-1);
    }

    // Initialize T with zeros
    vector<int> T(N, 0);

    int l = start;
    int r = start + 1;
    int dir = +1;

    while(l > 0 || r < N){
        double rand_double = rnd.next(1.0);
        if(rand_double < p){
            dir *= -1;
        }

        if(dir == +1 && r < N){
            T[r] = r - l;
            r += 1;
        }
        if(dir == -1 && l > 0){
            l -= 1;
            T[l] = r - l - 1;
        }
    }

    return T;
}

// Function to perturbate the configuration
vector<int> perturbate(int N, vector<int> T, bool solvable, int ma_pert, bool preserve_0, bool swap_flag){
    if(swap_flag){
        // Determine the starting index based on preserve_0
        int start = preserve_0 ? 1 : 0;
        for(int i = 0; i < ma_pert; ++i){
            // Ensure there are at least two distinct indices to swap
            if (N - start < 2){
                break; // Not enough elements to swap
            }
            int u = rnd.next(start, N-1);
            int v = rnd.next(start, N-1);
            while(v == u){
                v = rnd.next(start, N-1);
            }
            swap(T[u], T[v]);
        }
    }
    else{
        // Determine the starting index based on preserve_0
        int start = preserve_0 ? 1 : 0;
        for(int i = start; i < T.size(); ++i){
            int lower = T[i];
            int upper = T[i] + ma_pert;
            // Choose a random integer in [lower, upper]
            int choice = rnd.next(lower, upper);
            T[i] = min(choice, N-1);
        }

        if(!solvable){
            int idx;
            vector<int> new_t;
            for(ll attempt = 1; attempt <= 100; attempt++){
                idx = rnd.next(0, N-1);
                new_t = T;
                new_t[idx] = 0;
                if( (preserve_0 || idx != 0) && !solve(N, new_t)){
                    break;
                }
            }

            int l = 0;
            int r = T[idx];
            while(r - l > 1){
                int m = (l + r) >> 1;
                new_t[idx] = m;
                if(solve(N, new_t)){
                    r = m;
                }
                else{
                    l = m;
                }
            }
            T[idx] = l;
        }
    }

    return T;
}

// Function to generate a random configuration
vector<int> gen_random(int N, bool perm){
    if(!perm){
        vector<int> T;
        T.reserve(N);
        for(int i = 0; i < N; ++i){
            T.push_back(rnd.next(0, N-1));
        }
        return T;
    }
    else{
        vector<int> T(N);
        for(int i = 0; i < N; ++i){
            T[i] = i;
        }
        // Shuffle T using rnd.next for randomness
        for(int i = 0; i < N; ++i){
            int j = rnd.next(i, N-1);
            swap(T[i], T[j]);
        }
        return T;
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ll t = atoll(argv[1]);
    ll n_min = atoll(argv[2]);
    ll n_max = atoll(argv[3]);
    double p_change = atof(argv[4]);
    double p_solvable = atof(argv[5]);
    ll start = atoll(argv[6]);
    ll ma_pert = atoll(argv[7]);
    ll swap_flag = atoll(argv[8]);

    cout << t << nl;
    for (ll t_id = 1; t_id <= t; t_id++) {
        ll n = rnd.next(n_min, n_max);

        vector<int> a = gen_smart(n, start, p_change);

        a = perturbate(n, a, (rnd.next(1.0) < p_solvable), ma_pert,
            0, swap_flag);

        cout << n << nl;
        for (ll i = 1; i <= n; i++) {
            cout << a[i - 1] + 1;
            if (i == n) cout << nl;
            else cout << ' ';
        }
    }
}
