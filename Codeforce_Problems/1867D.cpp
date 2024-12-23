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
    int n,k;
    cin>>n>>k;
    int a[n];
    bool instabreak=false;
    
    forn(i,n){
        int b;
        cin>>b;
        b--;
        if(k==1){
            if(b!=i){
                instabreak=true;
            }
        }
        a[i]=b;        
    }
    if(instabreak){
        cout<<"NO"<<endl;
        return;
    }

    
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
