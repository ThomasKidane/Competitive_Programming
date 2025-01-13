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
    int c=0;
    int ind=n-2;
    vector<bool>used(n,false);
    for(int i=n-1;i>=0;i--){
        while(ind>=0 && (used[ind]||a[ind]>a[i]/2)){
            ind--;
        }
        if(ind>=0){
            // ind=i;
            c++;
            used[ind]=true;
            used[i]=true;
            ind-=1;
        } else {
            break;
        }
    }

    cout<<c<<endl;
}

signed main() {
    // ios_base::sync_with_stdio(false);
// i?    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
