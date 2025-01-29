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
    int a[n];
    ll S=0;
    forn(i,n){
        cin>>a[i];
        S+=a[i];
    }
    int b[m];
    forn(i,m){
        cin>>b[i];
    }
    int maxval[n][min(11,m+1)];
    forn(i,n){
        forn(j,min(11,m+1)){
            maxval[i][j]=INFINITY;
        }
    }
    vector<ll> difs;

    forn(i,n){
        vector<int> vals((1<<min(10,m)),INFINITY);
        
        vals[0]=a[i];

        for(int j=0;j<(1<<(min(10,m)));j++){
            int bits=__builtin_popcount(j);
                maxval[i][bits]=min(maxval[i][bits],vals[j]);
        
            for(int l=0;l<min(10,m);l++){
                // if()
                if(!(1&(j>>l))){
                    vals[(j|(1<<l))]=min(vals[(j|(1<<l))],vals[j]&b[l]);
                    
                }
                
            }
            
        }
    }

    forn(i,n){
       forn(j,min(m,10)){
            difs.push_back(maxval[i][j]-maxval[i][j+1]);
       }
    }
    sort(difs.begin(),difs.end());
    reverse(difs.begin(),difs.end());
    ll M=0;
    forn(i,k){
        M+=difs[i];
    }

    cout<<S-M<<endl;
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
