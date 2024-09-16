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

int solve(int n){
    //int n;
    if(n==0)return 0;


    return n/5+solve(n/5);
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
