#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

bool comp(tuple<int,int,char> p1,tuple<int,int,char> p2){
    if(get<0>(p1)!=get<0>(p2))return get<0>(p1)<get<0>(p2);
    else {
        return get<1>(p1)>get<1>(p2);
    }
}

void solve(){
    string s;
    cin>>s;
    int c=0;
    vector<tuple<int,int,char>> parens;
    forn(i,s.size()){
        parens.push_back(make_tuple(c,i,s[i]));
        if(s[i]=='(')c++;
        else c--;
    }
    sort(parens.begin(),parens.end(),comp);
    /*forn(i,parens.size()){
        cout<<parens[i].ff<<" "<<parens[i].ss<<endl;
    }*/
    string res;
    forn(i,s.size()){
        res+=get<2>(parens[i]);
    }
    cout<<res<<endl
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
