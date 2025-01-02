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
    vector<vector<int>> noneone;
    map<int,vector<int>>taken;

    deque<vector<int>> real;
    forn(i,n){
        int l,r;
        cin>>l>>r;
        real.push_back({l,r});
        if(r-l==0){
            taken[r].push_back(i);
        } else {
            noneone.push_back({l,r,i});
        }
}

    vector<bool> vals(2*n+1,false);
    set<int> fucked;
    for(auto it=taken.begin();it!=taken.end();it++){
        if(it->ss.size()>1){
            fucked.insert(it->ff);
        }

        vals[it->ff]=true;
    }
    vector<int> pref(2*n+2,0);
    for(int i=0;i<2*n+1;i++){
        pref[i+1]=pref[i]+(vals[i+1]?1:0);
}
    // dbga(pref,8);
    forn(i,n){
        int l=real.front()[0];
        int r=real.front()[1];
        real.pop_front();
        if(r-l==0){
            if(fucked.find(r)!=fucked.end()){
                cout<<0;

            } else {
                cout<<1;
            }
            continue;
        }
        // dbgv(r);
        // dbgv(l);
        // dbgv(pref[r]);
        // dbgv(pref[l-1]);
        if(pref[r]-pref[l-1]!=(r-l+1)){
            cout<<1;
        } else{
            cout<<0;
        }

    }
    cout<<endl;
    
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
