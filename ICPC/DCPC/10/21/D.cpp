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
    int n,k;
    cin>>n>>k;
    vector<int> comms;
    string c;
    bool comm=false;
    int m=0;
    forn(i,k){
        if(comm){
            cin>>m;
            comm=false;
            // dbgv(comms.size());
            // dbgv(m);
            forn(j,m){
                comms.pop_back();
            }
        } else {
            cin>>c;
            if(c[0]=='u'){
                k++;
                comm=true;
                continue;
            } else {
                // cout<<"Here"<<endl;
                int v;
                // dbgv(c);
                sscanf(c.c_str(),"%d",&v);
                // dbgv(v);
                // cout<<v<<endl;
                comms.push_back(v);
            }

        }
        
        
    }
    // forn(i,comms.size()){
    //     cout<<i<<endl;
    // }
    int s=0;
    // dbgv()
    forn(i,comms.size()){
        s+=comms[i];
    }
    cout<<(s%n+n)%n;

}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
