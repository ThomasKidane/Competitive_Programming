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
    string s,r;
    cin>>s>>r;
    int ones=0;
    int zeros=0;
    forn(i,s.size()){
        if(s[i]=='0'){
            zeros++;
        } else {
            ones++;
        }
    }
    bool can=true;
    forn(i,r.size()){
        if(ones==0 || zeros==0){
            can=false;
        }
        if(r[i]=='0'){
            ones--;
        } else {
            zeros--;
        }
    }

    if(can){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
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
