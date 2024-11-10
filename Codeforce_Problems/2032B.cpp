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
    if(n==1){
        cout<<n<<endl;
        cout<<n<<endl;
    } else {
        if(k==n || k==1){
            cout<<-1<<endl;
        } else {
            if(k%2==0){
                cout<<3<<endl;
                cout<<1<<' '<<k<<' '<<k+1<<endl;    
            } else {
                cout<<3<<endl;
                cout<<1<<' '<<k-1<<' '<<k+2<<endl;    
            }
            
        }
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
