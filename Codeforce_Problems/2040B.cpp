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
    
    if(n==1){
        cout<<1<<endl;
        return;
    } else if(n==2){
        cout<<2<<endl;
        return;
    } else {
        int c=0;
        int m=2;
        c++;
        c++;
        // n-=4;
        int e=4;
        while(n>e){
            e=2*e+2;
            // dbgv(e);
            // c++;
            
            // if(n<=0){
            //     break;
            // }
            c++;
        }
        cout<<c<<endl;
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
