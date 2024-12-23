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
    set<int> seen;
    int a[n];
    forn(i,n){
        cin>>a[i];
        seen.insert(a[i]);
    } 
    deque<int> notseen;

    for(int i=1;i<=n;i++){
        if(seen.find(i)==seen.end()){
            notseen.push_back(i);
        }
    }
    map<int,int> did;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(!did[a[i]]){
            res.push_back(a[i]);
            did[a[i]]=1;
        } else {
            res.push_back(notseen.front());
            notseen.pop_front();
            // did[a[i]]=1;
        }
    }
    dbga(res,n);
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
