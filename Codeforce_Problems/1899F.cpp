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
    int d[q];
    for(int &b:d){
        cin>>b;
    }
    // Make straight tree
    forn(i,n-1){
        cout<<i+1<<' '<<i+2<<endl;
    }
    // d transfer n from prev to d
    int prev=n-1;
    int curd=n-1;
    forn(i,q){
        if(curd==d[i]){
            cout<<-1<<' '<<-1<<' '<<-1<<endl;
        } else {
            cout<<n<<' '<<prev<<' '<<d[i]<<endl;
            prev=d[i];
            curd=d[i];
        }
    }
    
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
