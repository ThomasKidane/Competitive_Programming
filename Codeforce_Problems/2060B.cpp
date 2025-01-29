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

bool comp(vector<int> v1,vector<int> v2){
    return v1.front()<v2.front();
}
void solve(){
    int n,m;
    cin>>n>>m;
    int va [n][m+1];
    forn(i,n){
        forn(j,m){
            int d;
            cin>>d;
            va[i][j]=d; 
        }
        va[i][m]=i+1;
    }
    for(int i=0;i<n;i++){
        sort(va[i],va[i]+m);
    }
    vector<vector<int>> vals(n,vector<int>());
    forn(i,n){
        forn(j,m+1){
            vals[i].push_back(va[i][j]);
        }
    }
    sort(vals.begin(),vals.end(),comp);
    int v=-1;
    bool can=true;
    // dbga(vals[0],m);
    // dbga(vals[1],m);
    
    forn(j,m){
        v=vals[0][j];
        // dbgv(v);
        for(int i=0;i<n;i++){
            if(vals[i][j]<v){
                // dbgv(vals[i][j]);
                // dbgv(v);
                can=false;
                break;
            }
            v=vals[i][j];
        }
        // cout<<"here"<<endl;
        // dbgv(can);
        if(!can){
            break;
        }
    }
    if(can){
        forn(i,n){
            cout<<vals[i].back()<<' ';
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
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
