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
    int n,x;
    cin>>n>>x;
    int c[n];
    for(int &d:c){
        cin>>d;
    }
    vector<ll> vals(x+1,0);
    // forn(i,n){
    //     vals[c[i]]=1;
    // }
    vals[0]=1;
    // forn(j,x){
    //     forn(i,n){
    //         if(vals[j]>)
    //     }
    // }
    sort(c,c+n);
    forn(i,n){
        forn(j,x){
            // if(vals[j]>=0){
                if(j+c[i]<=x){
                    vals[j+c[i]]+=vals[j];
                    vals[j+c[i]]%=((ll)1e9+7);
                } 
                //     vals[j+c[i]]+=vals[j];
                //     vals[j+c[i]]%=((ll)1e9+7); 
                // }
                
            // }
        }
    }
    if(vals[x]>=0){
        cout<<vals[x]<<endl;
        
    } else {
        cout<<0<<endl;
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
