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
    forn(i,n){
        cin>>a[i];
    }
    int b[3];
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    map<int,map<int,map<int,int>>> dc;
    dc[-1][b[1]][b[2]]+=1;
    dc[b[0]][-1][b[2]]+=1;
    dc[b[0]][b[1]][-1]+=1;
    dc[b[0]][b[1]][b[2]]+=1;
    forn(i,n-3){
        b[0]=b[1];
        b[1]=b[2];
        b[2]=a[i+3];
        dc[-1][b[1]][b[2]]+=1;
        dc[b[0]][-1][b[2]]+=1;
        dc[b[0]][b[1]][-1]+=1;
        dc[b[0]][b[1]][b[2]]+=1;
    }
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    ll res=0;
    res+=(dc[-1][b[1]][b[2]]-dc[b[0]][b[1]][b[2]]);
    res+=(dc[b[0]][-1][b[2]]-dc[b[0]][b[1]][b[2]]);
    res+=(dc[b[0]][b[1]][-1]-dc[b[0]][b[1]][b[2]]);
    forn(i,n-3){
        b[0]=b[1];
        b[1]=b[2];
        b[2]=a[i+3];
        res+=(dc[-1][b[1]][b[2]]-dc[b[0]][b[1]][b[2]]);
        res+=(dc[b[0]][-1][b[2]]-dc[b[0]][b[1]][b[2]]);
        res+=(dc[b[0]][b[1]][-1]-dc[b[0]][b[1]][b[2]]);
    }
    cout<<res/2<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
