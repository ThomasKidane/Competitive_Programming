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

ll swapcost=1000000000000;
ll delcost=1000000000001;

void solve(){
    string s;
    cin>>s;
    deque<char> vals;
    forn(i,s.size()){
        vals.push_back(s[i]);
    }
    while(!vals.empty() && vals.front()=='0'){
        vals.pop_front();
    }
    while(!vals.empty() && vals.back()=='1'){
        vals.pop_back();
    }
    if(vals.empty()){
        cout<<0<<endl;
        return;
    }
    //1100
    deque<pair<char,int>> vl;
    // dbgv(vals.size());
    for(auto c:vals){
        if(vl.empty()){
            vl.push_back(make_pair(c,1));
        } else {
            if(c==vl.back().ff){
                vl.back().ss++;
            } else {
                vl.push_back(make_pair(c,1));
            }
        }
    }
    
    vector<pair<char,int>> trueval;
    ll S1=0;
    ll S0=0;
    for(auto pi:vl){
        trueval.push_back(pi);
        if(pi.ff=='0'){ 
            S0+=pi.ss;              
        }
    }
    ll S=S0*delcost;
    // dbgv(vl.size());
    forn(i,vl.size()){
        pair<char,int> pi=vl[i];
        if(pi.ff=='1'){
            S=min(S,S1*delcost+(pi.ss-1)*delcost+swapcost+(S0-1)*delcost);
            S1+=pi.ss;
        } else{
            // cout<<"here"<<endl;
            S0-=pi.ss;
            S=min(S,S1*delcost+S0*delcost);
        }
    }

    cout<<S<<endl;
    
    
    

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
