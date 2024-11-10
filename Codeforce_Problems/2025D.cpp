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
    int n,m;   
    cin>>n>>m;
    int dp[m+3];
    for(int i=0;i<=m;i++){
        // for(int j=0;j<=m;j++){
            dp[i]=-1;
        // }
    }
    dp[0]=0;
    int a[n];
    vector<map<int,int>> ops;
    bool ls=false;
    map<int,int> f;
    ops.push_back(f);
    forn(i,n){
        cin>>a[i];
        if(a[i]==0){
            if(ls){
                ops.back()[0]++;
            } else {
                map<int,int> dc;
                dc[0]++;
                ops.push_back(dc);
                ls=true;
            }
        } else {
            if(!ls){
                ops.back()[a[i]]++;
            } else {
                map<int,int> dc;
                dc[a[i]]++;
                ops.push_back(dc);
                ls=false;
            }
        }
    }
    // cout<<"Here"<<endl;
    // forn(i,ops.size()){

    // }
    // dbgv(ops.size());
    
    int t=1;
    forn(i,ops.size()){
        if(ops[i][0]>0){
            forn(j,ops[i][0]){
                // forn(k,m+1){
                    // if(dp[k]!=-1){
                        // dp[k]=max(dp[k],dp[k]);

                        dp[t+1]=max(dp[t+1],dp[t]);
                    // } else {
                    //     break;
                    // }
                    
                // }
                t++;

            }

            // t+=ops[i][0];
        } else {
            
            for(auto it=ops[i].begin();it!=ops[i].end();it++){
                // it becomes value and checks
                if(it->first<0){
                    for(int k=(-1)*it->first;k<=t;k++){
                        dp[k]+=it->second;
                    }
                } else {
                    for(int k=0;k<=t-it->first;k++){
                        dp[k]+=it->second;
                    }
                }
            }
        }
        
    }
    forn(i,m+1){
        // forn(j,m+1){
            cout<<dp[i]<<' ';
        // }
        // cout<<endl;
    }
    

    int M=0;
    forn(i,m+1){
        if(dp[i]>M)M=dp[i];
    }
    cout<<M<<endl;
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
