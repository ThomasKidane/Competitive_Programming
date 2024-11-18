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
    ll v;
    cin>>n>>m>>v;
    ll a[n];
    forn(i,n){
        cin>>a[i];
    }
    // Try to pack as much as possible
    ll S=0;
    deque<int> ind;
    vector<ll> pre(n+1);
    pre[0]=0;
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+a[i];
    }
    for(int i=0;i<n;i++){
        S+=a[i];
        // pre[i+1]=pre[i]+a[i];
        if(S>=v){
            // Breakoff
            ind.push_back(i);
            S=0;
            if(ind.size()>=m)break;
        }
    }
    // dbga(ind,ind.size());
    if(ind.size()<m){
        // cout<<"Here"<<endl;
        cout<<-1<<endl;
    } else {
        // To find the max value we can siphon
        // int r=n-1;//Right Endpoint
        // int l=ind[m-1];
        // dbgv(l);
        // dbga(ind,ind.size());
        // ind.pop_back();
        ll mx=pre[n]-pre[ind.back()+1];
        ind.pop_back();
        ind.push_front(-1);
        int rr=n-1;
        // dbgv(rr);
        // ind.push_front(0);
        
        // dbga(pre,pre.size());
        do {
            int l=ind.back();
            // dbgv(l);
            ind.pop_back();
            int b=rr;
            // dbgv(b);
            // l++;
            ll S=0;
            for(int r=rr;r>=l;r--){
                S+=a[r];
                // dbgv(r);
                // dbgv(S);
                if(S>=v){
                    // Breakoff
                    // ind.push_back(i);
                    rr=r-1;//inclusive rightend
                    // S=0;
                    break;
                }
            }
            // dbgv(S);
            // dbgv(v);
            // dbgv(rr);
            // dbgv(pre[l+1]);
            // dbgv(pre[rr+1]);
            // if(l==0){
            //     mx=max(mx,pre[rr+1]-pre[l]);    
            // } else {
                mx=max(mx,pre[rr+1]-pre[l+1]);
            // }
            mx=max(mx,pre[rr+1]-pre[l+1]);
            // dbgv(mx);
            // dbgv(ind.size());
            // mx=max(pre[v]-)
        } while(!ind.empty());

        // cout<<"Here"<<endl;
        cout<<mx<<endl;
            
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
