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
    forn(i,n){
        cin>>a[i];
    }
    set<int> seen;
    string res="";
    int c=0;
    for(int i=0;i<n;i++){
        seen.insert(a[i]);
        for(int j=a[i];j<=n;j++){
            if(seen.find(j)==seen.end()){
                res+=to_string(j)+" "+to_string(a[i])+endl;
                c++;
            }
        }
        for(int j=n;j>=1;j--){
            if(seen.find(j)==seen.end()){
                res+=to_string(a[i])+" "+to_string(j)+endl;
                c++;
            }
        }
    }
    cout<<c<<endl;
    cout<<res;
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
