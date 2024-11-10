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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    forn(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    ll difA[n-1];
    if(n==1){
        cout<<a[0]+k<<endl;
        return;
    }
    forn(i,n-1){
        difA[i]=a[i+1]-a[i];
    }
    dbga(difA,n-1);
    ll mul=1;
    ll M=a[0];
    ll i=0;
    while(k>=difA[i]*mul){
        if(i==n-2){
            M=a[i+1];
            k-=(difA[i]*mul);
            mul++;
            M+=(k/mul);
            k%=mul;break;
        }
        M=a[i+1];
        k-=(difA[i]*mul);
        mul++;
    }
    if(i<n-2){
        M+=k;
        k-=k;
        dbgv(M);
        cout<<1+M*(M-1)+(n-i-1)<<endl;
        return;
    }
    
    cout<<1+M*(M-1)+k<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
