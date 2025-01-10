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
    vector<int>v1;
    vector<int>v2;
    forn(i,n){
        int d;
        cin>>d;
        if((v1.empty()) || (d!=v1.back())){
            v1.push_back(d);
        } else{
            v2.push_back(d);
        }
    }
    // // dbga(v2,v2.size());

    int c=0;
    forn(i,v1.size()-1){
        if(v1[i+1]!=v1[i]){
            c++;
        }
    }
    if(v1.size())c++;
    // dbgv(c);
    for(int i=0;(int)i<(int)v2.size()-1;i++){
        if(v2[i+1]!=v2[i]){
            c++;
        }
    }

    if(v2.size())c++;
    cout<<c<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
