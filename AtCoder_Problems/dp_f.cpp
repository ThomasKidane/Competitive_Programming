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

const int MAXN=3001;
vector<vector<int>> dp(MAXN,vector<int>(MAXN,0));
vector<vector<bool>>done(MAXN,vector<bool>(MAXN,false));


int maxlcs(string&s,string&t,int l,int m,vector<vector<int>>&dp){
    if(done[l][m]){
        return dp[l][m];
    }
    if(l<0 || m<0){
        return 0;
    }
    if(l==0 && m==0){
        // return ;
        dp[l][m]=(int)(s[l]==t[m]);
        done[l][m]=true;
        return dp[l][m];

    } else {
        if(l==0){
            done[l][m]=true;
            dp[l][m]=max(maxlcs(s,t,l,m-1,dp),(int)(s[l]==t[m]));
            return dp[l][m];
        }
        if(m==0){
            done[l][m]=true;
            dp[l][m]=max(maxlcs(s,t,l-1,m,dp),(int)(s[l]==t[m]));
            return dp[l][m];
        }
        done[l][m]=true;
        dp[l][m]=max(maxlcs(s,t,l-1,m,dp),max(maxlcs(s,t,l-1,m-1,dp)+(int)(s[l]==t[m]),maxlcs(s,t,l,m-1,dp)));
        return dp[l][m];
    }
}

void maxlcsstring(string&s,string&t,int l,int m,vector<vector<int>>&dp,deque<char>&res){
    if(l<0 || m<0)return;
    if(l==0 && m==0){
        if(dp[l][m]==1){
            if(l==0){
                // res=(s[l]+res);
                res.push_front(s[l]);
                // return;
                // return s.substr(l,1);
            } else {
                // res=(t[m]+res);
                res.push_front(t[m]);
                return;
                // return t.substr(m,1);
            }
        }
        // if(s[l]==t[m]){
            
        //     return s.substr(l,1);
        // } else {
        //     return "";
        // }

    } else {
        if(l==0){
            // done[l][m]=true;
            if(dp[l][m]==1){
                res.push_front(s[l]);
            }
            return;
            // dp[l][m]=max(maxlcs(s,t,l,m-1,dp),(int)(s[l]==t[m]));
            // return dp[l][m];
        }
        if(m==0){
            if(dp[l][m]==1){
                res.push_front(t[m]);
            }
            return;
        }
        if(dp[l][m]==dp[l-1][m-1]+1){
            // res=(s[l]+res);
            res.push_front(s[l]);
            maxlcsstring(s,t,l-1,m-1,dp,res);
            return;
            // return +s.substr(l,1);
        }
        if(dp[l][m]==dp[l-1][m-1]){
            // res=(+res);
            maxlcsstring(s,t,l-1,m-1,dp,res);
            return;
        } else {
            if(dp[l][m]==dp[l-1][m]){
                // res=();
                maxlcsstring(s,t,l-1,m,dp,res);
                return;
            } else {
                // res=();
                maxlcsstring(s,t,l,m-1,dp,res);
                return;
            }
        }
        // return max(maxlcs(s,t,l-1,m),max(maxlcs(s,t,l-1,m-1)+(s[l]==t[m]),maxlcs(s,t,l,m-1)));
    }
}

void solve(){
    string s,t;
    cin>>s>>t;
    // memset(dp,0,sizeof(dp));

    // cout<<maxlcs(s,t,s.size()-1,t.size()-1);
    // string res="";
    deque<char>res;
    maxlcs(s,t,s.size()-1,t.size()-1,dp);
    maxlcsstring(s,t,s.size()-1,t.size()-1,dp,res);
    // cout<<res<<endl;
    int n=res.size();
    forn(i,n){
        cout<<res.front();
        res.pop_front();
    }
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
