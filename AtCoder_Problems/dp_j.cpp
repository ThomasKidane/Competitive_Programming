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
    int n;
    cin>>n;
    int c1=0;
    int c2=0;
    int c3=0;
    forn(i,n){
        int d;
        cin>>d;
        if(d==1)c1++;
        else if(d==2)c2++;
        else c3++;
    }
    vector<vector<vector<ld>>> dp(301,vector<vector<ld>>(301,vector<ld>(301,0)));
    // memset(dp,0,sizeof(dp));
    // forn(i,301){
    //     forn(j,301){
    //         forn(k,301){
    //             dp[i][j][k]=0;
    //         }
    //     }
    // }
    dp[c1][c2][c3]=1;
    ld res=0;
    for(int c=c3;c>=0;c--){
        for(int b=c2+c3;b>=0;b--){
            for(int a=c1+c2+c3;a>=0;a--){
                if(a+b+c>n)continue;
                // dbgv(a);
                // dbgv(b);
                // dbgv(c);
                ld pwaste=(ld)(a+b+c)/n;
                ld wasted_steps;
                // dbgv(pwaste);
                if(pwaste<1e-6){
                    wasted_steps=0;
                } else {
                    wasted_steps=(1/(pwaste));
                }
                res+=dp[a][b][c]*wasted_steps;

                // dbgv(wasted_steps);
                if(c>0) {dp[a][b+1][c-1]+=((ld)c/(a+b+c))*(dp[a][b][c]);}
                if(b>0) {dp[a+1][b-1][c]+=((ld)b/(a+b+c))*(dp[a][b][c]);}
                if(a>0) {dp[a-1][b][c]+=((ld)a/(a+b+c))*(+dp[a][b][c]);}
            }
        }
    }

    cout<<setprecision(15)<<res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;/
    while(T--){
        solve();
    }
    return 0;
}
