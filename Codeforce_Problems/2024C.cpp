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

bool Comp(vector<int> v1,vector<int> v2){
    if(min(v1[0],v1[1])<min(v2[0],v2[1])){
        return true;
    } else if(min(v1[0],v1[1])>min(v2[0],v2[1])){
        return false;
    } else {
        return max(v1[0],v1[1])<max(v2[0],v2[1]);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> toB;
    forn(i,n){
        int a,b;
        cin>>a>>b;
        toB.push_back({a,b,i+1});
    }

    sort(toB.begin(),toB.end(),Comp);
    forn(i,n){
        cout<<toB[i][0]<<' '<<toB[i][1]<<' ';
    }
    cout<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
