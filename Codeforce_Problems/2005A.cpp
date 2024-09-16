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
    vector<char> let ={'a', 'e', 'i', 'o', 'u'};
    string res;
    if(n<=5){
        for(int i=0;i<min(5,n);i++){
        res+=let[i];
    }
    } else {
        for(int i=0;i<n;i++){
        res+=let[i%5];
    }   
    sort(res.begin(),res.end());
    }
    
    
    cout <<res<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
