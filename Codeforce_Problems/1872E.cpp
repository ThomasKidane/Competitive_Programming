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
    vector<int> a(n);
    vector<int> prefs(n+1);
    prefs[0]=0;
    forn(i,n){
        cin>>a[i];
        prefs[i+1]=prefs[i]^a[i];
    }

    string s;
    cin>>s;
    int zeros=0,ones=0;
    forn(i,n){
        if(s[i]=='0'){
            zeros^=a[i];
        } else {
            ones^=a[i];
        }
    }
    int q;
    cin>>q;
    // dbgv(q);
    forn(m,q){
        int v;
        cin>>v;
        if(v==1){
            int l,r;
            cin>>l>>r;
            zeros^=(prefs[r]^prefs[l-1]);
            ones^=(prefs[r]^prefs[l-1]);
        } else {
            int b;
            cin>>b;
            if(b){
                cout<<ones<<' ';
            } else {
                cout<<zeros<<' ';
            }
        }
    }
    cout<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
