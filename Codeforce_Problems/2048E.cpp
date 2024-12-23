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

bool check(int n,int m){
    int v=2*n*m;
    int cc=1;
    int c=0;
    for(int i=0;i<n;i++){
        c+=((2*n)-i+(m-i-1));
        // cc++;
    }
    // dbgv(c);

    // dbgv(v);
    return c>=v;
}

void solve(){
    int n,m;
    cin>>n>>m;
    if(!check(n,m)){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        vector<vector<pair<int,int>>> res(2*n);
        int l=0;
         for(int i=0;i<n;i++){
            for(int j=i;j<2*n;j++){
                if(res[j].size()<m){
                    res[j].push_back(make_pair(i+1,i+1));
                }
                if(res[j].size()==m && j>l)l=j;
            }
            // cout<<"Fr"<<endl;
            // for(int i=0;i<res[2].size();i++){
            //     cout<<res[2][i].ss<<' ';
            // }
            // cout<<endl;
            int s=i+2;
            int cc=i+1;
            for(int j=0;j<2*n && s<=m;j++){
                // s=min(s,m);
                if(res[j].size()<max(i+1,m)){
                    res[j].push_back(make_pair(s,i+1));
                    s++;
                }
                if(res[j].size()==m && j>l)l=j;
            }
            // cout<<"Fr"<<endl;
            // for(int i=0;i<res[2].size();i++){
            //     cout<<res[2][i].ss<<' ';
            // }
            // cout<<endl;
            // dbga(res[2],res[2].size());

         }//
        for(int i=0;i<2*n;i++){
            if(res[i].size()<m){
                res[i].push_back(make_pair(l+2,n));
                l++;
            }
        }
         for(int i=0;i<2*n;i++){
            sort(res[i].begin(),res[i].end());
            for(int j=0;j<res[i].size();j++){
                cout<<res[i][j].second<<' ';
            }
            cout<<endl;
         }
    }
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
