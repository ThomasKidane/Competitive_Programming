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
    vector<int> psum(86500);
    forn(j,n){
        int m;
        cin>>m;
        forn(j,m){
            int l,r;
            cin>>l>>r;
            psum[l]++;
            psum[r+1]--;
        }
    }
    int m=0;
    int s=0;
    forn(i,86500){
        s+=psum[i];
        if(s>m)m=s;
    }
    int c=0;
    s=0;
    forn(i,86500){
        s+=psum[i];
        if(s==m)c++;
    }

    cout<<m<<endl;
    cout<<c<<endl;
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
