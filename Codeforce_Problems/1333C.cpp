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
    int n;
    cin>>n;
    ll a[n];
    ll pref[n+1];
    pref[0]=0;
    map<ll,vector<ll>> vals;
    vals[0].push_back(0);
    ll dp[n]={0ll};
    for(int i=0;i<n;i++){
        cin>>a[i];
        pref[i+1]=pref[i]+a[i];
        vals[pref[i+1]].push_back(i+1);
    }

    // vector<int> inds;
    for(auto it=vals.begin();it!=vals.end();it++){
        // dbgv(it->ss.size());
        if(it->ss.size()>1){
            // cout<<"here"<<endl;
            // inds.push_ba
            for(int i=1;i<it->ss.size();i++){
                // inds.push_back(it->ss[i]);
                dp[it->ss[i]-1]=max(dp[it->ss[i]-1],it->ss[i-1]+1);
            }

        }
    }
    // sort(inds.begin(),inds.end());

    ll carry=0;
    ll res=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            carry=i+1;
        } else {
            carry=max(dp[i],carry);
            res+=(i+1)-carry;
        } 
    }

    cout<<res<<endl;

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
