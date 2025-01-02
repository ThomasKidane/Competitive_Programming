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
    int mx=0;
    for(int i=100;i<1000;i++){
        for(int j=100;j<1000;j++){
            string res=to_string(i*j);
            string res2=res;
            reverse(res2.begin(),res2.end());
            if(res2==res){
                mx=max(mx,i*j);
            }
        }
    }

    // string res="12021";
    // string res2=res;
    // reverse(res2.begin(),res2.end());
    // cout<<res<<endl;
    // cout<<res2<<endl;
    // cout<<(res==res2 ? 1:0)<<endl;

    cout<<mx<<endl;
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
