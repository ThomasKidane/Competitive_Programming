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
    forn(i,n){
        cin>>a[i];
    }
    vector<int> sz(n,n-1);
    // dbga(sz,n);
    forn(i,n){
        if(i==0){
            int l=0;
            for(int j=1;j<n;j++){
                if(a[j]>a[i])l++;
            }
            sz[i]=l;
            // dbgv(l);
        } else if(i==n-1){
            int l=0;
            for(int j=i+1;j<n;j++){
                if(a[j]>a[i])l++;
            }
            sz[i]=l+i;
        } else {
            int l=0;
            for(int j=i+1;j<n;j++){
                if(a[j]>a[i])l++;
            }
            sz[i]=l+i;
        }
    }

    int M=sz[0];
    forn(i,n){
        if(sz[i]<M)M=sz[i];
    }

    cout<<M<<endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
