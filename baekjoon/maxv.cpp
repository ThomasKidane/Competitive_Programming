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
    int a[9];
    forn(i,9){
        int d;
        cin>>d;
        a[i]=d;
    }
    int m=a[0];
    int j=0;
    forn(i,9){
        if(m<a[i]){
            m=a[i];
            j=i;
        }
    }

    cout<<m<<endl;
    cout<<j+1<<endl;
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
