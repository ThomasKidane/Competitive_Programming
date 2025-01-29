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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> vals;
    int cur=0;
    forn(i,n){
        // dbgv(k);
        // dbgv(cur);
        if(k>cur){
            if(vals.size()+1+cur<=k){
                vals.push_back(30);
                cur+=vals.size();
            } else {
                int s=-1;
                int j=vals.size();
                while(j>k-cur){
                    // if(vals[j-1]<0){
                    //     j--;
                    //     continue;
                    // }
                    s-=vals[j-1];
                    j--;
                }
                vals.push_back(s);
                cur+=j;
            }
        } else {
            vals.push_back(-999);
        }
    }
    dbga(vals,n);
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
