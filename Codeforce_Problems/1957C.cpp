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

const int N=4e5;
const int MOD=1e9+7;
ll VAL[N];


void solve(){
    int n,k;
    cin>>n>>k;
    int c=n;
    forn(i,k){
        int a,b;
        cin>>a>>b;
        if(a==b){
            c--;
        } else {
            c-=2;
        }
    }

    cout<<VAL[c]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    VAL[0]=1;
    VAL[1]=1;
    VAL[2]=3;
    for(int i=3;i<=N;i++){
        VAL[i]=(VAL[i-1]+2*(i-1)*VAL[i-2])%MOD;
    }

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
