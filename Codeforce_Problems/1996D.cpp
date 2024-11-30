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
    int n,x;
    cin>>n>>x;
    ll count=0;
    // map<int,map<int,map<int,int>>> vals;
    for(int a=1;a<=x-2;a++){
        for(int b=1;b<=min(n/a,x-a);b++){
            // for(int c=1;c<=min(x-a-b,(n-a*b)/(a+b));c++){
                // if(vals[a][b][c]==0){
                    count+=max(0,min(x-a-b,(n-a*b)/(a+b)));
                //     vals[a][b][c]=1;
                // }  
            }
        }
    

    cout<<count<<endl;
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
