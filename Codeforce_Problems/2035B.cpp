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
    if(n==3 || n==1){
        cout<<-1<<endl;
    } else {
        if(n%2==0){
            forn(i,n-2){
                cout<<3;
            }

            cout<<66<<endl;
        } else {
            forn(i,n-5){
                cout<<3;
            }
            cout<<"36366";
            
            cout<<endl;
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
