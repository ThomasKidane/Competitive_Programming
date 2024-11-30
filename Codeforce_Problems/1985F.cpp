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

struct VectorComparator {
    bool operator()(const vector<ll>& a, const vector<ll>& b) {
        // Prioritize based on the first element of each vector
        return a[0] > b[0];
    }
};
void solve(){
    ll h,n;
    cin>>h>>n;
    ll a[n];
    ll c[n];
    priority_queue<vector<ll>, vector<vector<ll>>, VectorComparator> attacks;
    
    forn(i,n)cin>>a[i];
    forn(i,n){cin>>c[i];}
    forn(i,n){attacks.push({1ll,c[i],a[i]});}
    // sort(attacks.begin(),attacks.end(),comp);
    ll t=1;
    while(h>0){
        h-=attacks.top().back();
        t=attacks.top().front();
        // attacks.top().front()+=attacks.top()[1];
        vector<ll> car=attacks.top();
        attacks.pop();
        car.front()+=car[1];
        attacks.push(car);
    }

    cout<<t<<endl;
    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
