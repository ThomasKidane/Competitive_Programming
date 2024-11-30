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
    ll x;
    cin>>x;
    deque<int> dp;
    deque<ll> vals;
    x-=2;
    dp.push_back(200);
    vals.push_back(2);
    while(x>0){
        int j=vals.size();
        for(int i=0;i<vals.size();i++){
            if(2*vals[i]>=x){
                j=i;
                break;
            }
        }
        if(x==1){
            dp.push_front(10000);
            break;
        }
        // int j=lower_bound(vals.begin(),vals.end(),x)-vals.begin();
        if(j==vals.size()){
            x-=(2*vals.front());
            vals.push_front(vals.front()*2);
            dp.push_front(dp.front()-1);
        } else {
            x-=(vals[j]);
            vals.push_front(2*vals[j]);
            dp.push_front(dp[j]); 
        }
    }

    dbga(dp,dp.size());
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
