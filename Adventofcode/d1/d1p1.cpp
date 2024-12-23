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
    vector<int> a,b;
    bool p=true;
    int d;
    while(cin>>d){
        if(p){
            a.push_back(d);

        }else{
            b.push_back(d);
        }
        p=!p;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int s=0;
    forn(i,a.size()){
        s+=abs(a[i]-b[i]);
    }
    cout<<s;
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
