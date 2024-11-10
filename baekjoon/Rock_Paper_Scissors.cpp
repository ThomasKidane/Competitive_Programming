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
    int x=0;
    int y=0;
    forn(i,n){
        char a,b;
        cin>>a>>b;
        if(a==b)continue;
        else{
            if(a=='R'){
                if(b=='P'){
                    y++;
                } else {
                    x++;
                }
            } else if(a=='P'){
                if(b=='R'){
                    x++;
                } else {
                    y++;
                }
            } else {
                if(b=='R'){
                    y++;
                } else {
                    x++;
                }
            }
        }
    }
    if(x==y){
        cout<<"TIE"<<endl;
    } else if(x>y){
        cout<<"Player 1"<<endl;
    } else {
        cout<<"Player 2"<<endl;
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
