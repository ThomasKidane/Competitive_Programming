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
    int h,n;
    cin>>h>>n;
    int a[n];
    int c[n];
    map<int,int> dic;
    forn(i,n)cin>>a[i];
    forn(i,n){cin>>c[i];dic[c[i]]+=1;}
    ll LC=c[0];
    forn(i,n)LC=lcm(LC,a[i]);
    ll at[LC+1];
    for(auto it=dic.begin();it!=dic.end();it++){
        for(int i=0;i<=LC;i+=(it->first)){
            at[i]+=(it->first)*(it->second);
        }
    }
    ll cur=at[0];
    forn(i,LC+1){
        at[i+1]+=cur;
        cur=at[i+1];
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
