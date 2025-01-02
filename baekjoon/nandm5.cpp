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
void lm(int a[],int n,int m,vector<vector<int>>&sups,vector<int>&cur,set<int>&already){
    if(n==1){
        // int c=(cur.empty()?1:cur.back());
        for(int i=0;i<m;i++){
            // cout<<"here"<<endl;
            if(already.find(a[i])!=already.end())continue;
            cur.push_back(a[i]);
            sups.push_back(cur);
            cur.pop_back();
        }
    } else {
        // int c=(cur.empty()?1:cur.back());
        for(int i=0;i<m;i++){
            if(already.find(a[i])!=already.end())continue;
            already.insert(a[i]);
            cur.push_back(a[i]);
            lm(a,n-1,m,sups,cur,already);
            // sups.push_back(cur);
            cur.pop_back();
            already.erase(a[i]);
        }
    }
}

void solve(){
    int n,m;
    cin>>m>>n;
    int a[m];
    forn(i,m){
        cin>>a[i];
    }
    vector<vector<int>> vs;
    vector<int> cur;
    set<int>already;
    lm(a,n,m,vs,cur,already);
    // cout<<vs.size()<<endl;
    // set<int>already;
    sort(vs.begin(),vs.end());
    for(int i=0;i<vs.size();i++){
        forn(j,n){
            cout<<vs[i][j]<<' ';
        }
        cout<<endl;
    }
    
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
