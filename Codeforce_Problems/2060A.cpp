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
    int a1,a2,a4,a5;
    cin>>a1>>a2>>a4>>a5;
    int mm=0;
    int m=1;
    
    int a3=a5-a4;
    if(a3==a1+a2){
        m++;
    }
    if(a3+a2==a4){
        m++;
    }
    mm=max(m,mm);
    m=1;

    a3=a1+a2;
    if(a4==a3+a2){
        m++;
    }
    if(a3+a5==a5){
        m++;
    }
    mm=max(m,mm);
    m=1;
    a3=a4-a2;
    if(a5==a3+a4){
        m++;
    }
    if(a3==a2+a1){
        m++;
    }
    mm=max(m,mm);
    

    cout<<mm<<endl;
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
