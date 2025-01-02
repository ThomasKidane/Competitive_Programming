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
    vector<bool> sieve(3000000,true);
    // for(
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i<2900000;i++){
        if(sieve[i]){
            for(int j=2*i;j<2900000;j+=i){
                sieve[j]=false;
            }
        }
    }
    ll c=0;
    for(int i=0;i<2000000;i++){
        // c++;
        // if(sieve[i])c++;
        // if(c==10001){
            // cout<<i<<endl;
            // return;
        // }
        if(i<20000000){
            if(sieve[i]){
                c+=i;
            }
        }
    }

    cout<<c<<endl;

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
