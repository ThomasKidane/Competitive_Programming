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

ll res(ll a,ll b){
    if(abs(a-b)<=15){
        return 7ll;
    } else if(abs(a-b)<=23){
        return 6ll;
    } else if(abs(a-b)<=43){
        return 4ll;
    } else if(abs(a-b)<=102){
        return 2ll;
    } else {
        return 0ll;
    }
}

ll bScore(vector<ll>& a,vector<ll>& b,ll i,ll j,ll n,ll m,vector<vector<ll>>& Mem){
    // cout<<"Called"<<endl;
    if(Mem[i][j]!=-1){
        return Mem[i][j];
    }

    // Currently trying to match a[i] to b[j], Starts off as 0,0, and a is always smaller or equal in size, and n and m are sizes, so n<=m
    if(j==m-1){
        if(b[j]<=a[i]){
            Mem[i][j]=res(b[j],a[i]);
            return res(b[j],a[i]);
        } else if(i==n-1){
            Mem[i][j]=res(b[j],a[i]);
            return res(b[j],a[i]);
        } else {
            Mem[i][j]=max(res(a[i],b[j]),bScore(a,b,i+1,j,n,m,Mem));
            return Mem[i][j];
        }
    } else if(i==n-1){
        if(b[j]>=a[i]){
            Mem[i][j]=res(b[j],a[i]);
            return res(b[j],a[i]);
        }
        else if(j!=m-1){
            Mem[i][j]=max(res(a[i],b[j]),bScore(a,b,i,j+1,n,m,Mem));
            return Mem[i][j];
        } else if(j==m-1){
            return res(b[j],a[i]);
        }
        else {
            Mem[i][j]=res(b[j],a[j]);
            return Mem[i][j];
        }
    } else {
            
        Mem[i][j]=max(res(a[i],b[j])+bScore(a,b,i+1,j+1,n,m,Mem),max(bScore(a,b,i,j+1,n,m,Mem),bScore(a,b,i+1,j,n,m,Mem)));
        return Mem[i][j];        
    }
}

void solve(){
    // cout<<"Here"<<endl;
    vector<vector<ll>> mom(2020,vector<ll> (2020));
    forn(i,2010){
        forn(j,2010){
            mom[i][j]=-1ll;
        }
    }

    long long n,m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(m);
    forn(i,n){
        cin>>a[i];
    }
    forn(i,m){
        cin>>b[i];
    }
    // Makes a always smaller
    if(n>m){
        swap(a,b);
        swap(n,m);
    }
    // cout<<"Here"<<endl;
    cout<<bScore(a,b,0,0,n,m,mom)<<endl;
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
