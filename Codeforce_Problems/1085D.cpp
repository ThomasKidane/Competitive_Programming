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
    ld s;
    cin>>n>>s;
    map<int,int> freq;
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        freq[a]++;
        freq[b]++;
    }
    int c=0;
    for(auto it=freq.begin();it!=freq.end();it++){
        if(it->second==1){
            c++;
        }
    }

    cout<<setprecision(15)<<(ld)((s/c)*2)<<endl;
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
