#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n'

void solve(){
    string s;
    cin>>s;
    bool can=false;
    // cout<<"Her"<<endl;
    string toP;
    for(int i=0;i<s.size();i++){
        if(s.size()-i>=3){
            // string d=
            if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]){
                can=true;
                toP=s.substr(i,3);
                break;
            }
            // can|=threedifferent(s,i);
        }
        if(s.size()-i>=2){
            if(s[i]==s[i+1]) {can=true;toP=s.substr(i,2);break;}
        }
    }

    if(can){
        cout<<toP<<endl;
    } else {cout<<-1<<endl;}
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
