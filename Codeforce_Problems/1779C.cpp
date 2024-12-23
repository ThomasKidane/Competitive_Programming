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
    int a[n];
    forn(i,n){
        cin>>a[i];   
    }
    priority_queue<int> pq;
    ll s=0;
    int c=0;
    for(int i=m-1;i>0;i--){
        s+=a[i];
        pq.push((a[i]<<1));
        if(s>0){
            s-=pq.top();
            c++;
            pq.pop();
        }
    }
    s=0;
    while(!pq.empty())pq.pop();
    // pq.clear();
    for(int i=m;i<n;i++){
        s+=a[i];
        pq.push(2*(-a[i]));
        if(s<0){
            s+=pq.top();
            pq.pop();
            c++;
        }
    }
    cout<<c<<endl;
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
