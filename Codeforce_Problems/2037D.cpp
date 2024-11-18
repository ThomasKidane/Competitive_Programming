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
    int n,m,L;
    cin>>n>>m>>L;
    map<int,map<string,int>> pos;
    map<int,vector<int>> powerspoint;
    forn(i,n){
        int l,r;
        cin>>l>>r;
        
        pos[l]["block"]++;
        pos[l]["ending"]+=1;
        // pos[l]["ending"]-=2;
        pos[r+1]["block"]--;
        pos[r+1]["ending"]-=1;
    }
    forn(i,m){
        int x,v;
        cin>>x>>v;
        
        pos[x]["power"]+=v;
        powerspoint[x].push_back(v);
    }
    // dbgv()
    int j=1;
    bool can=true;
    int lastpos=1;
    priority_queue <int> powers;
    int jumppower=1;
    int taken=0;
    for(auto it=pos.begin();it!=pos.end();it++){
        //  if((it->second)["block"]!=0) {
            // dbgv((it->first));
            // Is blocked or ending of a block
            if((it->second)["block"]>0){
                //start of a block
                lastpos=(it->first)-1;
                
            } else if((it->second)["block"]<0){
                // dbgv((it->first));
                //ending of a block
                // dbgv(jumppower);
                while(jumppower<(it->first)-lastpos && !powers.empty()){
                    jumppower+=powers.top();
                    taken++;
                    // dbgv(powers.top)
                    // dbgv(jumppower);
                    powers.pop();
                }

                if(jumppower<(it->first)-lastpos){
                    // dbgv(jumppower);
                    cout<<-1<<endl;
                    return;
                }
                
            }
        // }
        // if ((it->second)["power"]>0){
            while(!powerspoint[it->first].empty()){
                // int v=powers.top();
                // powers.pop();
                powers.push(powerspoint[it->first].back());
                powerspoint[it->first].pop_back();
            }
        // }
    }

    cout<<taken<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
