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
    ll a[n];
    forn(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    vector<int> c1;
    // vector<int> c2;
    forn(i,n-2){
        
        int j=lower_bound(a,a+n,a[i]+a[i+1])-a;
        // dbgv(j);
        // dbgv(i);
        if(j>=n){
            if(a[i]+a[i+1]<=a[j-1])j--;
        } else {
            // if(a[i]+a[i+1]<=a[j])j--;
        }
        
        c1.push_back(max(n-j+i,0));
    }
    // reverse(a,a+n);
    // int c2=0;
    // for(int i=n-1;i>=2;i--){
    //     if(a[0]+a[1]<=a[i])c2++;
    // }
    int m=c1[0];
    forn(i,n-2){
        if(m>c1[i])m=c1[i];
    }
    cout<<m<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
