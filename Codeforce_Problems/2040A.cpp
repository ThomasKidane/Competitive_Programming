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
    forn(i,n){
        cin>>a[i];
    }
    if(n==1){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        return;
    }
    forn(i,n){
        bool any=true;
        for(int j=0;j<n;j++){
            
            if(i!=j){
                if(abs(a[i]-a[j])%k==0){
                    any=false;
                    break;
                }
            }
            
        }
        if(any){
                cout<<"YES"<<endl;
                cout<<i+1<<endl;
                return;
            }
    }
    cout<<"NO"<<endl;

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
