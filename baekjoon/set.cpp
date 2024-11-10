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
    int m;
    cin>>m;
    // map<int,int> dc;
    int a[21];
    forn(i,21){
        a[i]=0;
    }
    forn(i,m){
        string s;
        cin>>s;
        if(s=="add"){
            int d;
            cin>>d;
            a[d]=1;
        } else if(s=="remove"){
            int d;
            cin>>d;
            dc[d]=0;
        } else if(s=="check"){
            int d;
            cin>>d;
            cout<<dc[d]<<endl;
        } else if(s=="toggle"){
            int d;
            cin>>d;
            dc[d]=int(!dc[d]);
        } else if(s=="All"){
            // map<int,int> tb;
            dc.clear();
            forn(i,20){
                dc[i+1]=1;
            }
            // dc=tb;
        } else if(s=="empty"){
            // map<int,int> tb;
            dc.clear();
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
