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

void solve(int n,int a,int b,int c){
    if(n==1){
        cout<<a<<' '<<c<<endl;
    }
    else {
        solve(n-1,a,c,b);
        cout<<a<<' '<<c<<endl;
        solve(n-1,b,a,c);
    }
    
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        int n;
        cin>>n;
        cout<<pow(2,n)-1<<endl;
        solve(n,1,2,3);
    }
    return 0;
}
