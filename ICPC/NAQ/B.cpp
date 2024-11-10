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
    bool notH=true;
    ld l;
    forn(i,n){
        ld x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        // cout<<y2-((y2-y1)/(x2-x1))*x2<<endl;
        if(x1==x2){
            continue;
        } else {
            if(notH && y2-((y2-y1)/(x2-x1))*x2>0 && abs(x1)/x1!=abs(x2)/x2){
                notH=false;
                l=y2-((y2-y1)/(x2-x1))*x2;
            } else if(y2-((y2-y1)/(x2-x1))*x2>0  && abs(x1)/x1!=abs(x2)/x2){
                l=min(l,y2-((y2-y1)/(x2-x1))*x2);
            }
            
        }
    }
    if(notH){
        cout<<-1<<endl;
    } else {
        cout<<l<<endl;
    }
    
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
