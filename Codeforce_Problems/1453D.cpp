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
pair<string,ll> getmost(ll k){
    ll r=2;
    int c=0;
    string s="1 ";
    while((r<<1)-2ll<=k){
        r=r<<1;
        c++;
    }
    forn(i,c-1){
        s+="0 ";
    }

    return make_pair(s,r-2);
}
void solve(){
    ll k;
    cin>>k;
    string s="";
    // int t=10;
    if(k&(1)){
        cout<<-1<<endl;
        

    } else {
        while(k>0ll){
                s+=getmost(k).ff;
        // dbgv(k);
        k-=getmost(k).ss;
        
        // dbgv(getmost(k).ss);
    }
    cout<<s.size()/2<<endl;
    cout<<s<<endl;
        
    }
    
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
