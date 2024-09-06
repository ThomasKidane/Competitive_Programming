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
    int a[n];
    forn(i,n)cin>>a[i];
    map<int,vector<int>> dic;
    int b[n];
    forn(i,n){
        dic[a[i]>>2].push_back(a[i]);
        b[i]=a[i]>>2;
    }
    for(auto it=dic.begin();it!=dic.end();it++){
        sort(it->second.begin(),it->second.end());
        reverse(it->second.begin(),it->second.end());
    }
    int c[n];
    forn(i,n){
        c[i]=dic[b[i]].back();
        dic[b[i]].pop_back();
    }
    dbga(c,n);
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
