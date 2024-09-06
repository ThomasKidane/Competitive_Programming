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

bool isPalindrome(string s){
    
    reverse(s.begin(),s.end());
    string t=s;
    reverse(s.begin(),s.end());
    if(s==t){return true;}
    else return false;
}

void solve(){
    string s;
    cin>>s;
    forn(i,s.length()+1){
        forn(j,26){
            string t;
            t=s.substr(0,i)+char(j+int('a'))+s.substr(i);
            if(isPalindrome(t)){
                cout<<t<<endl;
                return;
            }
        }
    }
    cout<<"NA"<<endl;
    return;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
