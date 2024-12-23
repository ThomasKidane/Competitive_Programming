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
    map<int,vector<int>> edges;
    map<int,int> neighbors;
    int inner;
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        // edges.push_back((a,b));
        edges[a].push_back(b);
        edges[b].push_back(a);
        neighbors[a]++;
        neighbors[b]++;
        if(neighbors[a]>=2){
            inner=a;
        }
        if(neighbors[b]>=2){
            inner=b;
        }
    }
    if(n<=2){
        if(k>0){
            cout<<0<<endl;
            return;
        } else {
            cout<<n<<endl;
            return;
        }
    }
    // cout<<"Here"<<endl;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> res(n+1,0);
    map<int,bool>done;
    for(auto it=neighbors.begin();it!=neighbors.end();it++){
        if(it->ss==1){
            pq.push(make_pair(1,it->ff));
            res[it->ff]=1;
            done[it->ff]=true;
        }
    }
    
    while(!pq.empty()){
        int c=pq.top().ff;
        int i=pq.top().ss;
        pq.pop();
        // dbga(res,n+1);
        for(auto e:edges[i]){
            if(done[e])continue;
            neighbors[e]--;
            if(neighbors[e]<=1){
                res[e]=c+1;
                pq.push(make_pair(c+1,e));
                done[e]=true;
            }
        }
    }

    int c=0;
    for(int i=1;i<=n;i++){
        if(res[i]>k){
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
    // int tt=T;
    while(T--){
        solve();
    }
    return 0;
}
