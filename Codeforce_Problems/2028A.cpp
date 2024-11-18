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
    int n,a,b;
    cin>>n>>a>>b;
    int x=0;
    int y=0;
    string s;
    cin>>s;
    bool can=false;
    for(int v=0;v<1000;v++){
        if(x==a && y==b){can=true;break;}
        forn(i,n){  
            if(s[i]=='N'){
                y++;
            } else if(s[i]=='S'){
                y--;
            } else if(s[i]=='E'){
                x++;
            } else{
                x--;
            }
            if(x==a && y==b){can=true;break;}
        }
        if(can){break;}
    }

    if(can){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
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
