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
    int a[n];
    int b[m];
    forn(i,n){
        cin>>a[i];
    }
    forn(i,m){
        cin>>b[i];
    }

    int me=a[0];
    sort(a,a+n);
    sort(b,b+m);
    int points[m];
    forn(i,m){
        if(me>=b[i]){
            points[i]=0;
        } else {
            points[i]=n-(int)(lower_bound(a,a+n,b[i])-a);
        }
    }
    sort(points,points+m);
    // dbga(points,m);
    
    for(int i=1;i<=m;i++){
        ll c=0;
        for(int j=m-(m%i);j>0;j-=i){
            c+=points[j-1]+1;
            // dbgv(j-1);
        }
        cout<<c<<' ';
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
