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
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    int cnt=0;
    int cur=0;
    int ones=0;
    bool notended=false;
    int r=0;
    vector<int> vals;
    for(int i=0;i<n;i++){
        if(r==0){
            notended=false;
        }
        if(notended || s[i]=='1'){
            cur=0;
            if(notended){
                r--;
            }
        } else {
            cur++;
        }
        if(cur==m){
            notended=true;
            r=k-1;
            cur=0;
            cnt++;
        }
    }

    cout<<cnt<<endl;
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
