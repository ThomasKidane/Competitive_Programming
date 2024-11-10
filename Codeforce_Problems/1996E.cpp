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
    map<int,vector<int>> dic;
    int c=0;
    int n=s.size();
    dic[0].push_back(0);
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            c--;
        } else {
            c++;
        }
        dic[c].push_back(i);
    }
    ll S=0;
    for(auto it=dic.begin();it!=dic.end();it++){
        vector list=(*it).second;
        if(list.size()==1)continue;
        vector<ll> pref(list.size());
        pref[list.size()-1]=(n-list.back());
        dbgv(pref[list.size()-1]);
        for(int i=list.size()-2;i>=0;i--){
            pref[i]=(n-list[i])+pref[i+1];
        }
        for(int i=0;i<list.size()-1;i++){
            S+=(i+1)%((1000000007))*(pref[i+1])%((1000000007));
            S%=(1000000007);
        }
    }
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
