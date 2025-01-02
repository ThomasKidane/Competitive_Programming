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

int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

void solve(){
    int n,d;
    cin>>n>>d;
    cout<<1<<' ';
    if(n>=3 || d%3==0){
        cout<<3<<' ';
    }
    if(d==5){
        cout<<5<<' ';
    }
    if(d==7 || n>=3){
        cout<<7<<' ';
    }

    if(n>=6 || (n>=3 && d%3==0) || d==9){
        cout<<9<<' ';
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
