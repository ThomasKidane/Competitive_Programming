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
    vector<ll> a,b;
    map<ll,ll> freq;
    bool p=true;
    ll d;
    while(cin>>d){
        if(p){
            a.push_back(d);            
        }else{
            b.push_back(d);
            freq[d]++;
        }
        p=!p;
    }
    sort(a.begin(),a.end());
    // sort(b.begin(),b.end());
    // dbgv(a.size());
    ll s=0;
    forn(i,a.size()){
        s+=(a[i]*freq[a[i]]);
    }
    cout<<s;
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