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
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<string,int>> strs;
    forn(i,n){
        string s;
        cin>>s;
        strs.push_back(make_pair(s,i));
    }
    forn(j,q){
        vector<pair<string,int>> tb;
        int v;
        char c;
        cin>>v>>c;
        forn(i,strs.size()){
            if(strs[i].ff[v-1]==c){
                tb.push_back(strs[i]);
            }
        }
        strs=tb;
    }

    if(strs.size()==1){
        cout<<"unique"<<endl;
        cout<<strs.front().ss+1;
    } else {
        cout<<"ambiguous"<<endl;
        cout<<strs.size()<<endl;
    }
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
