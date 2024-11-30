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

ll M=(ll)1e9+7ll;

ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

void solve(){
    int n;
    cin>>n;
    ll a[n];
    forn(i,n){
        cin>>a[i];
    }
    ll p[n];
    forn(i,n){
        cin>>p[i];
    }
    ll dp[n+1][20][2]; // dp[i][b][0]=n dp[i][b][1]=m, probability of getting a 1 at index i is n/m for bit i;
    forn(i,20){
        dp[0][i][0]=0;
        dp[0][i][1]=1;
    }

    forn(i,n){
        forn(b,20){
            // dbgv(a[i]);
            if(a[i]&(1<<b)){
                ll x=dp[i][b][0];
                ll w=p[i];
                ll q=dp[i][b][1];
                ll c=10000;

                ll top=q*(w-2*x)+c*x;
                ll bottom=c*q;
                ll d=gcd(top,bottom);
                // dbgv(top);
                top/=d;
                bottom/=d;
                // dbgv(i);
                // dbgv(b);
                // dbgv(top);
                // dbgv(bottom);
                dp[i+1][b][0]=top;
                dp[i+1][b][1]=bottom;
            } else {
                dp[i+1][b][0]=dp[i][b][0];
                dp[i+1][b][1]=dp[i][b][1];
            }            
        }
    }

    

    ll top=0;
    ll bottom=1;
    forn(i,20){
        // dbgv(dp[n][i][0]);
        // dbgv(bottom);
        top=top*dp[n][i][1]+(1<<i)*dp[n][i][0]*bottom;
        bottom=bottom*dp[n][i][1];
        ll d=gcd(top,bottom);
        top/=d;
        bottom/=d;
    }
    dbgv(top);
    dbgv(bottom);
    top*=top;
    bottom*=bottom;
    
    // cout<<top<<endl;
    ll x, y;
    ll g = extended_euclidean(bottom, M, x, y);
    // if (g != 1) {
    //     cout << "No solution!";
    // }
    // else {
        x = (x % M + M) % M;
        // cout << x << endl;
        cout<<(top*x)%M<<endl;
    // }



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
