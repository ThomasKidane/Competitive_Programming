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
    map<int,int> dc;
    int d;
    forn(j,10*n){
        forn(i,5){
            cin>>d;
            dc[d]++;
        }
    }
    int c=0;
    vector<int> out;
    for(auto it=dc.begin();it!=dc.end();it++){
        if(it->second>2*n)out.push_back((*it).first);
    }
    if(out.size()>0){
        sort(out.begin(),out.end());

        dbga(out,out.size());
    } else {
        cout<<-1<<endl;
    }
    
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
