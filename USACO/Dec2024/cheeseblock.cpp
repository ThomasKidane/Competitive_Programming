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
    int n,q;
    cin>>n>>q;
    map<pair<int,int>,int> ab;
    map<pair<int,int>,int> ac;
    map<pair<int,int>,int> bc;
    int s=0;
    for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        ab[make_pair(a,b)]++;
        if(ab[make_pair(a,b)]==n){
            s++;
        }
        ac[make_pair(a,c)]++;
        if(ac[make_pair(a,c)]==n){
            s++;
        }
        bc[make_pair(b,c)]++;
        if(bc[make_pair(b,c)]==n){
            s++;
        }
        cout<<s<<endl;
        
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
