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

// int MAXN=1001;
char s[1001][1001];

bool comp(int i,int j){
    if(i<j && ::s[i][j]=='1'){
        return true;
    } else if(i<j && ::s[i][j]=='0'){
        return false;
    } else if(i>j && ::s[i][j]=='1'){
        return false;
    } else {
        return true;
    }
}


void solve(){
    int n;
    cin>>n;
    int a[n];
    forn(i,n){
        a[i]=i+1;
    }
    forn(i,n){
        string ss;
        cin>>ss;
        // s[i+1]=ss;
        forn(j,n){
            s[i+1][j+1]=ss[j];
        }
    }

    sort(a,a+n,comp);
    dbga(a,n);
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
