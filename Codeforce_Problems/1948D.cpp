#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && ((s[z[i]] == s[i + z[i]]) || s[z[i]]=='?' || s[i+z[i]]=='?')) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve(){
    string s;
    cin>>s;
    int res=0;
    for(int i=0;i<s.size();i++){
        vector<int> w=z_function(s.substr(i,s.size()));
        dbga(w,w.size());
        for(int i=0;i<w.size();i++){
            if(w[i]>=i && w[i]+i<=s.size()){
                res=max(res,2*i);
            }
        }
    }

    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
