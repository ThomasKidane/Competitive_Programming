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
    map<int,int> freqMap;
    int d;
    int m=0;
    forn(i,n){
        cin>>d;
        freqMap[d]+=1;
        if(m<d)m=d;
    }

    m+=2;
    int amount=freqMap[0];
    int res=0;
    int cur=0;
    // dbgv(amount);x`
    forn(i,m){
        if(amount==0)break;
        if(freqMap[cur]>0){
            
            if(freqMap[cur]<=amount){
                // dbgv(amount-freqMap[cur]);
                // dbgv(cur);
                // dbgv(res);
                res+=(cur)*(amount-freqMap[cur]);
                amount=freqMap[cur];
            }
            cur++;
        } else {
            // dbgv(res);
            // dbgv(cur);
            // dbgv(freqMap[cur]);
            res+=(cur)*(amount);
            break;
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
