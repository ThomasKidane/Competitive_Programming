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
bool comp(pair<int,int>p1,pair<int,int>p2){
    return p1.ss<p2.ss;
}
void solve(){
    int n,m;
    cin>>n>>m;
    string s[n];
    forn(i,n){
        cin>>s[i];
    }
    vector<pair<int,int>> cells;
    forn(i,n){
        forn(j,m){
            if(s[i][j]=='B'){
                cells.push_back(make_pair(i+1,j+1));
            }
        }
    }
    sort(cells.begin(),cells.end());
    int x=(cells.front().ff+cells.back().ff)/2;
    sort(cells.begin(),cells.end(),comp);
    int y=(cells.front().ss+cells.back().ss)/2;
    cout<<x<<' '<<y<<endl;
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
