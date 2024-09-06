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
    string s;
    cin>>s;
    vector<int> vals;
    reverse(s.begin(),s.end());
    int n=s.size();
    int j=0;
    ll S=0;
    forn(i,n){
        if(s[i]=='1'){
            S+=(i-j);
            vals.push_back((i-j));
            j++;
        }
    }
    if(!vals.empty())S+=vals.back();
    cout<<S<<endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
