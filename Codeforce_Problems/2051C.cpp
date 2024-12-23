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
   int n,m,k;
   cin>>n>>m>>k;
    map<int,int> know;
    int a[m];
    forn(i,m){
        cin>>a[i];
        // know[a[i]]++;
    }

    forn(i,k){
        int d;
        cin>>d;
        know[d]++;
    }

    forn(i,m){
        if(know[a[i]]==1 && k==n){
            cout<<1;
        } else if(know[a[i]]==0 && k==n-1){
            cout<<1;
        } else {
            cout<<0;
        }
    }

    cout<<endl;

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
