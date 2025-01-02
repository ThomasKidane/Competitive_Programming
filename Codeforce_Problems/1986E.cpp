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
    int n,k;
    cin>>n>>k;
    map<ll,vector<ll>> vals;
    map<int,int> cnt;
    forn(i,n){
        int d;
        cin>>d;
        vals[d%k].push_back(d);
        cnt[d]++;
    }

    ll c=0;
    if(n%2==0){
        for(auto it=vals.begin();it!=vals.end();it++){
            if(it->ss.size()%2!=0){
                cout<<-1<<endl;
                return;
            }else  {
                sort(it->ss.begin(),it->ss.end());
                for(int i=0;i<it->ss.size();i+=2){
                    c+=(it->ss[i+1]-it->ss[i])/k;
                }
                cout<<c<<endl;
                return;
             } 
        }
    } else {
        bool twice=false;
        for(auto it=vals.begin();it!=vals.end();it++){
            if(it->ss.size()%2!=0){
                if(twice){
                    cout<<-1<<endl;
                return;
                } else {
                    sort(it->ss.begin(),it->ss.end());
                    vector<ll> cost1;
                    vector<ll> cost2;
                    ll S1=0;
                    ll S2=0;
                    // dbgv(it->ff);/
                    // dbgv(it->ss.size());
                    // dbga(it->ss,it->ss.size());
                    for(int i=0;i<it->ss.size()-1;i+=2){
                        // dbgv(it->ss[i+1]);
                        cost1.push_back((it->ss[i+1]-it->ss[i])/k);
                        S1+=cost1.back();
                    }
                    for(int i=1;i<it->ss.size();i+=2){
                        // dbgv(it->ss[i+1]);
                        cost2.push_back((it->ss[i+1]-it->ss[i])/k);
                        S2+=cost2.back();
                    }
                    ll M=1e9;
                    ll pref1[cost1.size()+1];
                    pref1[cost1.size()]=0;
                    ll pref2[cost2.size()+1];
                    pref2[0]=0;
                    for(int i=cost1.size()-1;i>=0;i--){
                        pref1[i]=cost1[i]+pref1[i+1];
                    }
                    for(int i=0;i<cost2.size();i++){
                        pref2[i+1]=cost2[i]+pref2[i];
                    }
                    for(int i=0;i<=cost1.size();i++){
                        M=min(pref1[i]+pref2[i],M);
                    }
                    // ll pref1[cost1.size()+1];
                    pref2[cost1.size()]=0;
                    // ll pref2[cost2.size()+1];
                    pref1[0]=0;
                    for(int i=cost1.size()-1;i>=0;i--){
                        pref2[i]=cost2[i]+pref2[i+1];
                    }
                    for(int i=0;i<cost2.size();i++){
                        pref1[i+1]=cost1[i]+pref1[i];
                    }
                    for(int i=0;i<=cost1.size();i++){
                        M=min(pref1[i]+pref2[i],M);
                    }
                    // dbga(cost1,cost1.size());
                    // dbga(cost2,cost2.size());
                    // dbga(pref1,cost1.size()+1);
                    // dbga(pref2,cost1.size()+1);

                    twice=true;
                    c+=M;
                    // dbgv(c);
                }
                
            }else  {
                
                sort(it->ss.begin(),it->ss.end());
                for(int i=0;i<it->ss.size();i+=2){
                    c+=(it->ss[i+1]-it->ss[i])/k;
                }
                // dbgv(c);
                
             } 
        }
    }

    cout<<c<<endl;
    
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
