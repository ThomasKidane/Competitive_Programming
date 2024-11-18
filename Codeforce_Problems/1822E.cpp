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
    if(n%2==1){
        cout<<-1<<endl;
    } else {
        int mx=0;
        int c=0;
        map<char,int> freq;
        map<char,int> matches;
        int mxc=0;
        forn(i,n){
            freq[s[i]]++;
            mx=max(mx,freq[s[i]]);
            if(s[i]==s[n-i-1] && i<n/2){
                c++;
                matches[s[i]]++;
                mxc=max(mxc,matches[s[i]]);
            }
        }

        if(mx>n/2){
            cout<<-1<<endl;
        } else {
            cout<<max((c+1)/2,mxc)<<endl;
        }
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
