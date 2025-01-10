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
        vector<ll> a(n, 0);
        for (ll i = 0; i < n; i++) cin >> a[i], a[i]--;

        ll flag = 0;
        auto costruisci = [&](ll N, vector<ll> T) {
            vector<int> curr;

            auto brute = [&](auto &&brute, int l, int r){
                if(r-l+1 == N){
                    flag = 1;
                    return;
                }

                if(l > 0 and T[l-1] >= r-l+1){
                    curr.push_back(l-1);
                    brute(brute, l-1, r);
                    curr.pop_back();
                }

                if(r < N-1 and T[r+1] >= r-l+1){
                    curr.push_back(r+1);
                    brute(brute, l, r+1);
                    curr.pop_back();
                }
            };

            ll ans = 0;
            for(int i=1; i<=N; i++){
                flag = 0;
                curr.push_back(i);
                brute(brute, i, i);
                curr.pop_back();
                ans += flag;
            }

            return ans;
        };

        ll ans = costruisci(n, a);
        cout << ans << nl;
    }

    return 0;
}
