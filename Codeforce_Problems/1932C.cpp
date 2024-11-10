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
    int n,m;
    cin>>n>>m;
    int a[n];
    forn(i,n){
        cin>>a[i];
    }
    string ops;
    cin>>ops;
    int l=0,r=n-1;
    forn(i,n-1){
        if(ops[i]=='L'){
            l++;
        } else {
            r--;
        }
    }
    int res[n];
    res[n-1]=a[l]%m;
    int cur=a[l]%m;
    for(int i=n-2;i>=0;i--){
        if(ops[i]=='L'){
            l--;
            cur=(cur*a[l])%m;
            
        } else {
            r++;
            cur=(cur*a[r])%m;
        }
        res[i]=cur;
    }
    dbga(res,n);
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
