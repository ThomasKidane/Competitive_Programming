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
bool inside(vector<int> found,int v){
    forn(i,found.size()){
        if(found[i]==v){
            return true;
        }
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    vector<int> mis;
    vector<int> found;
    int start=1;
    forn(i,n){
        int d;
        cin>>d;
        found.push_back(d);
    }
    if(found.size()==found.back()){
        cout<<"good job";
    } else {
        for(int i=1;i<=found.back();i++){
            if(!inside(found,i)){
                cout<<i<<endl;
            }
        }
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
