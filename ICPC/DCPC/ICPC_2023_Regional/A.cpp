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
    deque<string> strs;
    forn(i,n){
        string s;
        cin>>s;
        strs.push_back(s);
    }
    vector<string> tb;
    tb.push_back(strs.front());
    strs.pop_front();
    forn(i,n-1){
        if(strs[i]=="Present!"){
            tb.pop_back();
        } else {
            tb.push_back(strs[i]);
    }
    }

    if(tb.empty()){
        cout<<"No Absences";
    } else  {
        forn(i,tb.size()){
        cout<<tb[i]<<endl;
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
