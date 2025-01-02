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
    bool isdif=false;
    bool bigger=false;
    forn(i,s.size()){
        if(s[i]!=t[i] || isdif){
            if(isdif){
                if(bigger){
                    if(s[i]>t[i]){
                        swap(s[i],t[i]);
                    }
                } else {
                    if(t[i]>s[i]){
                        swap(s[i],t[i]);
                    }
                }
            } else {
                isdif=true;
                bigger=s[i]>t[i];
            }
        }
    }

    cout<<s<<endl;
    cout<<t<<endl;
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
