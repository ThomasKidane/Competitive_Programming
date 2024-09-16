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
    cin>>s;
    int n=s.length();
    bool flag=false;
    string res="";
    for(int i=n-1;i>=0;i--){
        if(s[i]!='0'){
            if(s[i]=='.') res=s.substr(0,i);
            else res=s.substr(0,i+1);

            break;
        }
    }
    cout<<res;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
