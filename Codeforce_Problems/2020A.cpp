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
    ll n,k;
    cin>>n>>k;
    ll c=0;
    if(k>n || k==1){
        cout<<n<<endl;
        return ;
    }
    while(n){
        if(n<k){
            c+=n;
            break;
        }

        n-=(ll)pow(k,(ll)((log10(n)+(1e-9))/log10(k)));
        c++;
    }
    cout<<c<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
