#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
// #define int ll

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

bool comp(vector<int> a,vector<int> b){
    // if(a[0]!=b[0]){
        return a[0]<b[0];
    // } else {

    // }
}

const int N=2100700;

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[n];
    forn(i,n){
        cin>>a[i];
    }
    forn(i,n){
        cin>>b[i];
    }

    vector<vector<int>> tob;
    forn(i,n){
        tob.push_back({a[i]-b[i],a[i],b[i]});
    }

    sort(tob.begin(),tob.end());
    vector<vector<int>> inc;
    inc.push_back(tob.front());
    for(int i=1;i<n;i++){
        if(tob[i][1]<inc.back()[1]){
            inc.push_back(tob[i]);
        }
    }

    vector<ll> dp(N+20);
    dp[0]=0ll;
    int j=inc.size()-1;
    for(int i=1;i<N;i++){
        if(j>0){
            while(i>=inc[j-1][1]){
                j--;
                if(j==0){
                    break;
                }
        }
        }
        if(i>=inc[j][1]){
            dp[i]=dp[i-inc[j][0]]+2;
        } else {
            dp[i]=0;
        }
        
    }
    ll c[m];
    ll res=0;
    forn(i,m){
        cin>>c[i];
        if(c[i]>=1000000-50){
            res+=(2*((c[i]-inc[0][1])/inc[0][0]));
            c[i]-=(((c[i]-inc[0][1])/inc[0][0])*inc[0][0]);
            // res+=(2*((c[i]-inc[1][1])/inc[1][0]));
            // c[i]-=((c[i]-inc[1][1])/inc[1][0])*inc[1][0];
            res+=dp[c[i]];            
        } else {
            res+=dp[c[i]];
        }
    }

    cout<<res<<endl;


}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
