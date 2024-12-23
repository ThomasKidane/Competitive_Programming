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
    string s;
    cin>>s;
//     if(s.size()%2==1){
//         cout<<"NO"<<endl;
//  } else {
    map<char,int> freq;
    int d=0;
    for(int i=0;i<s.size();i++){
        freq[s[i]]++;
        // if(freq[s[i]]==0){
        //     // d++;
        //     freq[s[i]]++;
        //     // dbgv(s[i]);
        // }        
    }
    map<char,int> already;
    for(int i=0;i<s.size();i++){
        // freq[s[i]]++;
        if(freq[s[i]]>1 && already[s[i]]==0){
            // if(freq[s[i]]%2==1){
            //    d+=((freq[s[i]]+1)/2); 
            // } else {
            //     d+=(freq[s[i]]/2);
            // }
            d++;
            
            already[s[i]]++;
            // freq[s[i]]++;
            // dbgv(s[i]);
        }        
    }
    // dbgv(d);
    // dbgv(d);
        if(d>1){
            cout<<"YES"<<endl;
            return;
        } else {
           cout<<"NO"<<endl; 
           return;
        }
//  }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
