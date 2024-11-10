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

ll dfs(int e,ll cur_value,map<int,int>& freq,vector<ll>& mem,vector<ll>& a,vector<int>& b){
    if(mem[e]!=-1){
        return mem[e];
    } else if(e<=0){
        return cur_value;
    }
    else {
        // cout<<"Again"<<endl;
        // dbgv(e);
        // dbgv(a[e-1]);
        // dbgv(cur_value);
        
        freq[e]+=1;
        // dbgv(freq[e]);
        // dbgv(mem[e-1-freq[e-1]]);
        // dbgv(b[e-1]);
        mem[e]=mem[e-1-freq[e-1]]!=-1 ? cur_value+a[e-1] : dfs(e-1-freq[e-1],a[e-1],freq,mem,a,b)+cur_value;
        mem[e]=max(mem[e],dfs(b[e-1]-freq[b[e-1]],cur_value,freq,mem,a,b));
        return mem[e];
    }
}

void solve(){
    int n;
    // cout<<"Life"<<endl;
    cin>>n;
    // cout<<n<<endl;
    vector<ll> a(n);
    vector<int> b(n);
    map<int,int> freq;
    vector<ll> mem(n+1);
    forn(i,n+1){
        mem[i]=-1;
    }
    forn(i,n){
        cin>>a[i];
    }
    forn(i,n){
        cin>>b[i];
    }
    // cout<<"Here"<<endl;
    dfs(1,0,freq,mem,a,b);
    ll M=0;
    forn(i,n+1){
        if(M<mem[i])M=mem[i];
    }
    cout<<M<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
