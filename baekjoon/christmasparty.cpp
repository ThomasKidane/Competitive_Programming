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
    int m;
    cin>>m;
    int a[m];
    forn(i,m){
        cin>>a[i];
    }
    int score[n]={0};
    forn(i,m){
        int wrong=0;
        forn(j,n){
            int d;
            cin>>d;
            if(d==a[i]){
                score[j]++;
            } else {
                wrong++;
            }
        }
        score[a[i]-1]+=wrong;
    }

    forn(i,n){
        cout<<score[i]<<endl;
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
