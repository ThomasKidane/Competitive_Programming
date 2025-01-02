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

bool comp(vector<ll>v1,vector<ll>v2){
    return v1[0]>v2[0];
}

void solve(){
    int n;
    cin>>n;
    ll a[n];
    ll b[n];
    forn(i,n){
        cin>>a[i];
    }
    forn(i,n){
        cin>>b[i];
    }
    vector<vector<ll>> scores1;
    vector<vector<ll>> scores2;
    ll score=0;
    forn(i,n){
        score+=abs(a[i]-b[i]);
        scores1.push_back({max(a[i],b[i]),min(a[i],b[i]),i});
        scores2.push_back({min(a[i],b[i]),max(a[i],b[i]),i});
    }
    ll imp=0;
    sort(scores1.begin(),scores1.end());
    sort(scores2.begin(),scores2.end(),comp);
    if(n>1){
       
        if(scores1[0][2]!=scores2[0][2]){
            
            imp=max(0ll,2*(scores2[0][0]-scores1[0][0]));
        } else {
            //  cout<<"her"<<endl;
            imp=max(0ll,2*(scores2[1][0]-scores1[0][0]));
            imp=max(0ll,2*(scores2[0][0]-scores1[1][0]));

        }
        // imp=max(0,)
    }

    cout<<score+imp<<endl;
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
