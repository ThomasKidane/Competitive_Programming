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
    int n,x,y;
    cin>>n>>x>>y;
    if(n%2==0){
        if((y-x)%2==1){
            for(int i=1;i<=n;i++){
                cout<<i%2<<' ';
            }
            // cout<<endl;
        } else {
            for(int i=1;i<=n;i++){
                if(i==x){
                    cout<<2<<' ';
                } else {
                    cout<<i%2<<' ';
                }
            }
        }
    } else {
        if(y==n){
            for(int i=0;i<n-1;i++){
                cout<<i%2<<' ';
            }
            cout<<2;
        } else {

            if((y-x)%2==1){
                // cout<<"here"<<endl;
                for(int i=0;i<n-1;i++){
                    cout<<i%2<<' ';
            }
            cout<<2;
            } else {
                if((x-1)%2==1){
                    if(y!=n-1){
                    for(int i=0;i<n-1;i++){
                        if(i!=y-1){
                            cout<<i%2<<' ';
                        } else {
                            cout<<2<<' ';
                        }
                        
                    }
                    cout<<2;
                } else {
                    for(int i=0;i<n;i++){
                        if(i!=x-1 && i!=n-1){
                            cout<<i%2<<' ';
                        } else {
                            cout<<2<<' ';
                        }
                        
                    }
                }
                } else {
                    for(int i=0;i<n;i++){
                        if(i<x){
                            cout<<i%2<<' ';
                        } else if(i==x) {
                            cout<<2<<' ';
                        } else {
                            cout<<(i+1)%2<<' ';
                        }
                    }
                }
            }
        }
    }
    cout<<endl;
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
