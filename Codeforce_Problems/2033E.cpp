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

int cycleL(int i,map<int,int> &dc,bool b[]){

    if(b[dc[i]]){
        return 0;
    } else {
        b[i]=true;
        return 1+cycleL(dc[i],dc,b);
    }
}   

void solve(){
    int n;
    cin>>n;
    // if a[i]=i+1; or a[a[i]-1]=i+1
    map<int,int> dc;
    forn(i,n){
        int d;
        cin>>d;
        dc[i+1]=d;
    }

    bool b[n+1];
    forn(i,n+1){
        b[i]=false;
    }
    int c=0;

    for(int i=1;i<=n;i++){
        if(dc[i]==i || dc[dc[i]]==i){
            continue;
        } else {
            if(b[i]){
                continue;
            } else {
                b[i]=true;
                c+=(cycleL(i,dc,b))/2;
            }
        }
    }

    cout<<c<<endl;
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
