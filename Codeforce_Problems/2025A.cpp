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
    string s,t;
    cin>>s>>t;
    int match=0;
    bool flag=true;
    int ops=0;
    if(s.length()>t.length()){
        swap(s,t);
    }
    for(int i=0;i<min(s.length(),t.length());i++){
        if(s[i]!=t[i] && flag && i==0){
            ops+=2;
            flag=false;
        } else if(s[i]!=t[i] && flag){
            ops+=3;
            flag=false;
        } else if(s[i]==t[i] && !flag){
            ops+=2;
        } else if(s[i]==t[i] && flag){
            ops++;
        } else {
            ops+=2;
        }
    }
    for(int i=min(s.length(),t.length());i<max(s.length(),t.length());i++){
        ops++;
    }
    if(flag)ops++;
    cout<<ops<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
