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
    int n;string s;
    map<char,int> dic;
    cin>>n>>s;
    forn(i,n){
        dic[s[i]]+=1;
    }
    deque<pair<int,char>> lfreq;
    for(auto it=dic.begin();it!=dic.end();it++){
        lfreq.push_back(make_pair(it->ss,it->ff));
    }
    sort(lfreq.begin(),lfreq.end());
    reverse(lfreq.begin(),lfreq.end());
    string res;
    
    for(int i=0;lfreq.size()>0;i++){
        res+=lfreq.front().ss;
        if(lfreq.front().ff==1)lfreq.pop_front();
        else {
            pair<int,char> to_be_put=lfreq.front();
            lfreq.pop_front();
            to_be_put.ff-=1;
            lfreq.push_back(to_be_put);
        }
    }
    
    cout<<res<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
