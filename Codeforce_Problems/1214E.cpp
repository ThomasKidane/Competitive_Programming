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
    pair<int,int> a[n];
    forn(i,n){
        int d;  

        cin>>d;

        // cin>>a[i];
        a[i]=make_pair(d,2*(i+1));
    }
    vector<deque<int>> vals(2*n,deque<int>());
    sort(a,a+n);
    reverse(a,a+n);
    int skip[2*n];
    memset(skip,0,sizeof(skip));
    forn(i,n){
        vals[i].push_back(a[i].ss);

        vals[i+a[i].ff+1-vals[i].size()].push_back(a[i].ss-1);
    }
    int i=0;
    while(i<2*n-1 && !vals[i+1].empty()){
        forn(j,vals[i+1].size()){
            cout<<vals[i][0]<<' '<<vals[i+1][j]<<endl;
        }


        i++;
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
