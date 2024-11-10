#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
#include <iomanip>

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
void solve(){
    int n;
    cin>>n;
    ld v=0;
    map<int,vector<ld>> dc;
    forn(i,n){
        int s;
        ll c;
        cin>>s>>c;
        dc[s].push_back(c);
    }
    for(auto it=dc.begin();it!=dc.end();it++){
        if((*it).ss.size()==1){
            continue;
        } else {
            sort((*it).ss.begin(),(*it).ss.end());
            ld l=(*it).ss.front();
            // dbgv(l);
            for(int i=0;i<(*it).ss.size()/2;i++){
                // dbgv(i);
                // dbgv((*it).ss[i]);
                v+=log((*it).ss[(*it).ss.size()-1-i])-log((*it).ss[i]);
                // l=(*it).ss[i];
            }
        }
    }
    cout<< std::setprecision(17)<<v<<endl;
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
