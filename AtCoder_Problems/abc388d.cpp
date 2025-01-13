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
    int n;
    cin>>n;
    int a[n];
    forn(i,n){
        cin>>a[i];
    }
    vector<int> vals(n,0);
    int c=0;
    forn(i,n){

        cout<<max(0,a[i]-(n-i-1)+c-vals[i])<<' ';
        if(a[i]+c-vals[i]<=(n-i)){
            vals[i+a[i]+c-vals[i]+1]++;
        }
        c++;
        c-=vals[i];
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
