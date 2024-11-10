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

ll twos[(ll)3e7+20];

void solve(){
    int n;
    cin>>n;
    vector<int> eveFact(n);
    vector<int> oddFact(n);
    vector<ll> oddFactS;
    vector<ll> eveFactS;
    oddFactS.push_back(0);
    eveFactS.push_back(0);
    map<int,ll> vals;
    forn(i,n){
        ll d;
        cin>>d;
        vals[i]=d;
        int c=0;
        while(d%2==0){
            d/=2;
            c++;
        }
        eveFact[i]=c;
        oddFact[i]=d;        
        // dbgv(oddFactS.back());
        oddFactS.push_back(oddFactS.back()+d);
        // dbga(oddFactS,oddFactS.size());
        eveFactS.push_back(eveFactS.back()+c);
        
    }

    // dbga(twos,3);
    // dbga(oddFact,n);
    // dbga(eveFact,n);

    vector<vector<ll>> maxes;// (Base b, 2 power n, Residue r, Current Sum S, I)
    for(int k=0;k<n;k++){
        if(maxes.empty()){
            vector<ll> temp;
            temp.push_back(oddFact[k]);
            temp.push_back(eveFact[k]);
            temp.push_back(0);
            temp.push_back(vals[k]);
            temp.push_back(0);
            maxes.push_back(temp);
            cout<<vals[k]<<' ';
        } else {
            // the value is smaller than the last
            ll R=0;
            ll N=0;
            ll V=vals[k];
            ll S=0;
            bool total=false;
            // cout<<"St"<<endl;
            // dbgv(V*(ll)pow(2,N));
            bool started=false;
            // dbgv(maxes.size());
            // dbgv(maxes.back()[0]);
            // dbgv(maxes.back()[1]);
            // dbgv(vals[maxes.back()[4]]);
            while(V*(ll)pow(2,N)>=maxes.back()[0] && !maxes.empty()){
                started=true;
                // dbgv(V*(ll)pow(2,N));
                R+=maxes.back()[2];
                R+=maxes.back()[0];
                R%=(1000000007);
                N+=maxes.back()[1];
                S=maxes.back()[3];
                maxes.pop_back();
                // dbgv(maxes.size());
                if(N>31 || maxes.empty()){
                    total=true;
                    break;
                }
            }
            // dbgv(total)
            // dbgv(maxes.size());
            if(total){
                N=eveFactS[k];
                // b=oddFact[k];
                R=oddFactS[k];     
                S=0;           
                
            }
            // cout<<endl;
            // cout<<"Before"<<endl;
            // dbgv(S)
            // dbgv(maxes.size());
            // dbgv(total);
            // dbgv(started);
            // dbgv(twos[N]);
            // dbgv(vals[k]*twos[N]);
            // dbgv(R);
            if(started){
                if(!maxes.empty()){
                    S=maxes.back()[3];
                }
                
                S=S+twos[N]*(vals[k])+R;
                S%=(1000000007);
                N+=eveFact[k];
            }
            
            
            // cout<<endl;
            
            
            if(!started){
                N=eveFact[k];
                S=maxes[maxes.size()-1][3];
                // cout<<"From Started"<<endl;
                // dbgv(S);
                R=0;
                S=S+vals[k]+R;
                S%=(1000000007);
                N=eveFact[k];

            }
            S%=(1000000007);
            vector<ll> temp;
            temp.push_back(oddFact[k]);
            temp.push_back(N);
            temp.push_back(R);
            // S=()
            temp.push_back(S);
            temp.push_back(k);
            maxes.push_back(temp);
            // dbgv(maxes.size());
            // dbgv(S);
            cout<<S<<' ';
        }
        
    }

    cout<<endl;

}

int main() {
    ll s=1;
    forn(i,(ll)3e7+20){
        twos[i]=s;
        s*=2;
        s%=(1000000007);
    }
    // dbga(twos,5);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
