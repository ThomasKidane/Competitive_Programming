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
vector<pair<int,int>> fb;

void solve(){
    int n;
    cin>>n;
    cout<<fb[n].ff<<' '<<fb[n].ss<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fb.push_back(make_pair(1,0));
    fb.push_back(make_pair(0,1));
    forn(i,40){
        fb.push_back(make_pair(fb[fb.size()-2].ff+fb.back().ff,fb[fb.size()-2].ss+fb.back().ss));
    }
    
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
