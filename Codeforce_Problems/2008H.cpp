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

bool lessSum(int m,int k,int n,int res[]){
    int cnt=0;
    for(int i=0;i*k<=n;i++){
        cnt+=(res[min(k*i+m,n)]-res[max(k*i-1,0)]);
        /*dbgv(res[min(k*i+m,n)]);
        dbgv(res[max(k*i-1,0)]);*/
    }
    /*dbgv(m);
    dbgv(k);
    dbgv(n);
    dbgv(cnt);*/
    if((n%2==0) ? cnt<(n+2)/2 : cnt<(n+1)/2) return true;
    else return false;
}

void solve(){
    int n,q;
    cin>>n>>q;
    int a[n];
    int c[n+1]={0};
    forn(i,n){
        cin>>a[i];
        c[a[i]]++;
    }
    forn(i,n){
        c[i+1]+=c[i];
    }
    int res[n+1];
    res[1]=0;
    //dbga(c,n+1);
    for(int i=2;i<=n;i++){
        int v=0;
        for(int s=(i+1)/2;s>=1;s/=2){
            //cout<<"New one"<<endl;
            while(lessSum(v+s,i,n,c))v+=s;
        }
        if(lessSum(v,i,n,c))v++;
        res[i]=v;
    }
    forn(i,q){
        int d;
        cin>>d;
        cout<<res[d]<<' ';
    }
    cout<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
