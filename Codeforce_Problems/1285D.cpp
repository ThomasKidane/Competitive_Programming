#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
#define int ll
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
int func(vector<int> vals,int i){
    
    if(i==-1){
        return 0;
    }

    vector<int> ones;
    vector<int> twos;

    for(int j=0;j<vals.size();j++){
        if((vals[j]>>i) & 1){
            ones.push_back(vals[j]);
        } else {
            twos.push_back(vals[j]);
        }
    }

    if(ones.size()==0 || twos.size()==0){
        if(ones.size()>0){
            return func(ones,i-1);
        } else {
            return func(twos,i-1);
        }
        // return  max(func(ones,i-1),func(twos,i-1));
    } else {
        return (1<<i)+min(func(ones,i-1),func(twos,i-1));
    }

}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    forn(i,n){
        cin>>a[i];
    }
    cout<<func(a,31)<<endl;
    
    
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
