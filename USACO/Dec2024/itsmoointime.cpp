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

int mismatch(string &a,string b){
    int v=0;
    for(int i=0;i<min(b.size(),a.size());i++){
        if(a[i]!=b[i])v++;
    }
    return v;
}

bool valid(string t,string &s,int f){
    int n=s.size();
    int dp[2][n+1];
    forn(i,n+1){
        dp[0][i]=0;
        dp[1][i]=0;
    }
    char a=t[0];
    char b=t[2];
    for(int i=3;i<=n;i++){
        if(s[i-3]==a && s[i-2]==s[i-1] && s[i-1]==b){
            dp[0][i]=max(1+dp[0][max(0,i-3)],dp[0][i]);
            dp[1][i]=max(1+dp[1][max(0,i-3)],dp[1][i]);
        }
        dp[0][i]=max(max(dp[0][i-1],dp[0][i-2]),dp[0][i]);
        if(mismatch(t,s.substr(i-3,3))<=1){
            // dbgv(dp[0][max(0,i-3)]);
            // dbgv(i);
            // dbgv(s.substr(i-2,3));
            dp[1][i]=max(max(dp[1][i],1+dp[0][max(0,i-3)]),max(dp[1][i-1],dp[1][i-2]));
        }
        // dbgv(dp[1][i]);
        dp[1][i]=max(dp[1][i],max(dp[1][i-1],dp[1][i-2]));
    }
    // for(int j=0;j<2;j++){
    //     for(int i=0;i<=n;i++){
    //         cout<<dp[j][i]<<' ';
    //     }
    //     cout<<endl;
    // }
    // dbgv(max(dp[1][n],dp[0][n]));
    // dbgv((max(dp[1][n],dp[0][n])>=f ? "yes":"NO"));
    return max(dp[1][n],dp[0][n])>=f;
}

void solve(){
    int n,f;
    cin>>n>>f;
    string s;
    cin>>s;
    vector<string> vals;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(i!=j){
                string t;
                t+=char((int)('a')+i);
                t+=char((int)('a')+j);
                t+=char((int)('a')+j);
                // dbgv(t);
                if(valid(t,s,f)){
                    vals.push_back(t);
                }
            }
        }
    }

    cout<<vals.size()<<endl;
    for(int i=0;i<vals.size();i++){
        cout<<vals[i]<<endl;
    }
    // dbgv(valid("cqq",s,f));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
