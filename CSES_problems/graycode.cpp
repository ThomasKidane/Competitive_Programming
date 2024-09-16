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

vector<string> getlist(int i){
    if(i==1){
        return vector<string> {"0","1"};
    }
    else {
        vector<string> f;
        f=getlist(i-1);
        vector<string> res;
        forn(j,f.size()){
            res.push_back("0"+f[j]);
        }
        forn(j,f.size()){
            res.push_back("1"+f[f.size()-j-1]);
        }
        return res;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<string> res=getlist(n);
    forn(i,res.size()){
        cout<<res[i]<<endl;
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
