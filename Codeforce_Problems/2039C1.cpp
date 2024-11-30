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

vector<ll> getDivisors(ll n)
{
    // Note that this loop runs till square root

    vector<ll> res;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal, print only one
            if (n / i == i)
                {
                    res.push_back(i);
                }
            else // Otherwise print both
                res.push_back(i);
                res.push_back(n/i);
        }
    }

    return res;
}

void solve(){
    ll x,m;
    cin>>x>>m;
    int c=0;
    for(int i=1;i<=m && i<=2*x;i++){
        if(i!=x){
            if(x%(i^x)==0 || i%(i^x)==0){
                c++;
            }
            
        }
    }

    cout<<c<<endl;
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
