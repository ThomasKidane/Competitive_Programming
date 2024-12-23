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
    int a[n];
    // forn(i,/n){
        // cin>>a[i];
    // }
    bool allz=true;
    forn(i,n){
        cin>>a[i];
        if(a[i]!=0){
            allz=false;
        }
    }
    if(allz){
        cout<<0<<endl;
    } else {
        int gaps=0;
        bool inone=a[0]==0;
        if(!inone){
            gaps++;
        }
        for(int i=1;i<n;i++){
            if(inone){
                if(a[i]!=0){
                    gaps++;
                    inone=false;
                }
            } else {
                if(a[i]==0){
                    inone=true;
                }
            }
        }
        if(gaps>1){
            cout<<2<<endl;
        } else {
            cout<<1<<endl;
        }
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
