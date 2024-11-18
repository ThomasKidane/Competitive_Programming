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
    if(n<=4){
        cout<<-1<<endl;
    } else {
        // All evens except 4;
        for(int i=2;i<=n;i+=2){
            if(i!=4){
                cout<<i<<' ';
            }
        }
        cout<<4<<' '<<5<<' ';
        // All odds except 5;
        for(int i=1;i<=n;i+=2){
            if(i!=5){
                cout<<i<<' ';
            }
        }
        cout<<endl;
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
