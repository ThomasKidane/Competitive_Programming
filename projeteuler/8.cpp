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
    string s;
    string temp;
    while(cin>>temp){
        if(temp=="0")break;
                s+=temp;

    }    
    ll mx=0;
    // ll res=1
    for(int i=0;i<s.size()-12;i++){
        ll res=1;
        for(int j=i;j<i+13;j++){
            res*=((int)s[j]-(int)'0');
        }
        mx=max(res,mx);
    }
    cout<<s.size()<<endl;
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
