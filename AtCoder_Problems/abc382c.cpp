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
    int n,m;
    cin>>n>>m;
    int a[n];
    vector<pair<int,int>> actual;
    forn(i,n){
        cin>>a[i];
        if(actual.empty() || a[i]<actual.back().ss){
            actual.push_back(make_pair(i+1,a[i]));
        }
    }

    forn(i,m){
        int b;
        cin>>b;
        int j=actual.size()-1;
        for(int step=((actual.size()+1)/2);step>0;step/=2){
            // dbgv(j);
            if(j-step>=0){
                // dbgv(j);
                while(actual[j-step].ss<=b){
                    j-=step;
                    if(j-step<0){
                        break;
                    }
                }
            }
        }
        // dbgv(j);
        if(actual[j].ss<=b){
            cout<<actual[j].ff<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
