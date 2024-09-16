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

int longestC(vector<int> a,vector<int> b,vector<int> c,int al,int bl,int cl){
    if(al==0 || bl==0 || cl==0){
        return 0;
    }
    int res=0; 
    res=max((a[al-1]==b[bl-1] && b[bl-1]==c[cl-1])+longestC(a,b,c,al-1,bl-1,cl-1),max(longestC(a,b,c,al-1,bl,cl),max(longestC(a,b,c,al,bl-1,cl),longestC(a,b,c,al,bl,cl-1))));
    return res;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    forn(i,n)cin>>a[i];
    forn(i,n)cin>>b[i];
    forn(i,n)cin>>c[i];
    cout<<longestC(a,b,c,n,n,n)<<endl;

}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
