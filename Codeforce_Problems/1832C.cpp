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
    vector<int> vals;
    int p;
    forn(i,n){
        if(i==0){
            int d;
            cin>>d;
            p=d;
            vals.push_back(d);
        } else {
            int d;
            cin>>d;
            if(p==d){
                continue;
            } else {
                p=d;
                vals.push_back(d);
            }
        }
    }

    if(vals.size()==1){
        cout<<1<<endl;
    } else {
        bool sign=(vals[0]<vals[1]);
        // dbga(vals,vals.size());
        // dbgv(sign);
        int d=2;
        int p=vals[1];
        // dbgv(p);
        // dbga(vals,vals.size());
        for(int i=2;i<vals.size();i++){
            
            // dbgv(p);
            // dbgv(vals[i]);
            if(vals[i]>p && sign){
                // cout<<"Here"<<endl;
                p=vals[i];
            } else if(vals[i]>p && !sign){
                
                d++;
                sign=!sign;
                p=vals[i];
            } else if(vals[i]<p && sign){
                // cout<<"Here"<<endl;
                // dbgv(vals[i]);
                // dbgv(p);
                d++;
                sign=!sign;
                p=vals[i];
            } else {
                p=vals[i];
            }
            // dbgv(d);
        }

        cout<<d<<endl;
    }

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
