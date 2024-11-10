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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    forn(i,n){
        forn(j,m){
            a[i][j]=0;
        }
    }
    forn(i,n){
        forn(j,m){
            int d;
            cin>>d;
            a[i][j]+=d;
        }
    }
    forn(i,n){
        forn(j,m){
            int d;
            cin>>d;
            a[i][j]+=d;
        }
    }

    forn(i,n){
        forn(j,m){
            cout<<a[i][j]<<' ';
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
