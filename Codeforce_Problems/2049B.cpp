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
    string s;
    cin>>s;
    map<int,vector<pair<int,int>>> vals;
    for(int i=0;i<n;i++){
        // dbgv(i);
        if(s[i]=='p'){
            // cout<<"dksjfks"<<endl;
            // dbgv(i+1);
            if(vals[i+1].empty()){
                vals[i+1].push_back(make_pair(1,i+1));
            } else {
                // cout<<"DD"<<endl;
                // dbgv(vals[i+1].back().ss);
                for(int j=0;j<vals[i+1].size();j++){
                    if(vals[i+1][j].ff!=1 || vals[i+1][j].ss!=i+1){
                        cout<<"NO"<<endl;
                        // cout<<"Fuck"<<endl;

                        return;
                    }
                }
                // vals[i+1].push_back(make_pair(1,i+1));
            }
        } else if(s[i]=='s'){

            if(vals[n-i].empty()){
                vals[n-i].push_back(make_pair(i+1,n));
            } else {
                // cout<<"Hereddd"<<endl;
                for(int j=0;j<vals[n-i].size();j++){
                    // dbgv(n-i);

                    if(vals[n-i][j].ff!=i+1 || vals[n-i][j].ss!=n){
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                // vals[i+1].push_back(make_pair(1,i+1));
            }
        }
    }
    // cout<<"Here"<<endl;
    int l,r;
    bool all=false;
    for(auto it=vals.begin();it!=vals.end();it++){
        // dbgv(it->ff);
        if(!all){
            l=it->ss.back().ff;
            r=it->ss.back().ss;
            all=true;
        } else {
            if(l<it->ss.back().ff){
                cout<<"NO"<<endl;
                return;
            }
            if(r>it->ss.back().ss){
                cout<<"NO"<<endl;
                return;
            }
            l=min(it->ss.back().ff,l);
            r=max(it->ss.back().ss,r);
        }
    }

    cout<<"YES"<<endl;
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
