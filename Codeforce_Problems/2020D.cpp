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

ll N=200020;
ll C=11;
ll par[200060];
ll sz[200060];
ll dp[12][200030];
ll pref[12][200030];//[C][N]

int find_par(int i){
    if(par[i]==i)return i;
    else return find_par(par[i]);
}

void unite(int i,int j){
    // cout<<"fROM Unite"<<endl;
    // dbgv(i);
    // dbgv(j);
    // if(sz[find_par(i)]<sz[find_par(j)]){
    //     swap(i,j);
    // }
    // sz[find_par(i)]+=sz[find_par(j)];
    par[find_par(j)]=find_par(i);
    // dbgv(find_par(i));
}

void reset(int v){
    for(int i=0;i<=v+11;i++){
        for(int j=0;j<=C;j++){
                    dp[j][i]=0;
                    pref[j][i]=0;
    }
        par[i]=i;
        // sz[i]=1;
    }
}


void solve(){
    int n,m;
    cin>>n>>m;
    reset(n);
    forn(o,m){
        int a,d,k;
        cin>>a>>d>>k;
        // if(k==0)continue;
        dp[d][a]++;
        dp[d][a+k*d+d]--;
    }
    // for(int j=0;j<C;j++){
    //     for(int i=0;i<=n;i++){
        
    //                 cout<<dp[j][i]<<' ';
    //     }
    //     cout<<endl;
    // }
    
    
    
    for(int j=1;j<C;j++){
        for(int s=1;s<=j;s++){
            int curr=0;
            for(int i=s;i<=n;i+=j){
                // dbgv(i);
                // dbgv(j);
                
                if(i-j<0){
                    pref[j][i]=dp[j][i];
                    curr=dp[j][i];
                    
                } else {
                    // cout<<curr<<endl;
                    if(curr>0 && curr+dp[j][i]>0){
                        unite(i-j,i);
                    }
                    pref[j][i]=(dp[j][i]+pref[j][i-j]);
                    
                    
                    // dbgv(pref[])
                    curr=pref[j][i];
                    
                }
            }
        }
        // dbgv(j);
        
    }
    // cout<<endl;
    
    // for(int j=1;j<=C;j++){
    //     for(int s=1;s<=j;s++){
    //         bool New=true;
    //         for(int i=s;i<=n;i+=j){
    //             if(pref[j][i]>0 && New){
    //                 // cout<<"Happends nEW"<<endl;
    //                 // dbgv(i);
    //                 // dbgv(j);
    //                 // dbgv(pref[j][i])
    //                 New=false;

    //             } else if(pref[j][i]>0 && !New){
    //                 // cout<<"Happens"<<endl;
    //                 unite(i-j,i);
    //             } else {
    //                 New=true;
    //             }
    //         }
    //     }
        
    // }
    // cout<<"pref"<<endl;
    // for(int j=0;j<C;j++){
    //     for(int i=0;i<=n;i++){
        
    //                 cout<<pref[j][i]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<"par"<<endl;
    // dbga(par,n);
    int c=0;
    forn(i,n){
        if(par[i+1]==i+1){
            c++;
        }
    }
    cout<<c<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
