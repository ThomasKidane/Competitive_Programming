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
// S=15, T=30

int dp(string& s,string& t, int i,int j,vector<vector<int>> &mem){
    if(i==-1){
        return (j+1)*30;
    } else if(j==-1){
        return (i+1)*15;
    }
    if(mem[i][j]!=-1){
        return mem[i][j];
    } else {
        mem[i][j]=min(dp(s,t,i-1,j,mem)+15,min(dp(s,t,i-1,j-1,mem)+(!(s[i]==t[j]))*45,dp(s,t,i,j-1,mem)+30));
    }
    return mem[i][j];
}

void solve(){
    while(true){
        string s,t;
        cin>>s;
        if(s[0]=='#') break;
        cin>>t;
        vector<vector<int>> mem(s.size()+1,vector<int> (t.size()+1,-1));
        cout<<dp(s,t,s.length()-1,t.size()-1,mem)<<endl;
    }
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
