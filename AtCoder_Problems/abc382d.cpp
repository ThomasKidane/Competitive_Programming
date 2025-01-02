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

void lm(int n,int m,vector<vector<int>>&sups,vector<int>&cur){
    if(n==1){
        int c=(cur.empty()?1:10+cur.back());
        for(int i=c;i<=m-(10*(n-1));i++){
            cur.push_back(i);
            sups.push_back(cur);
            cur.pop_back();
        }
    } else {
        int c=(cur.empty()?1:10+cur.back());
        for(int i=c;i<=m-(10*(n-1));i++){
            cur.push_back(i);
            lm(n-1,m,sups,cur);
            // sups.push_back(cur);
            cur.pop_back();
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vs;
    vector<int> cur;
    lm(n,m,vs,cur);
    cout<<vs.size()<<endl;
    for(int i=0;i<vs.size();i++){
        forn(j,n){
            cout<<vs[i][j]<<' ';
        }
        cout<<endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
