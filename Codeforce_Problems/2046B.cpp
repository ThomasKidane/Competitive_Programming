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
    string s;
    cin>>n;
    cin>>s;
    map<char,int> freq;
    int mx=-1;
    int mi=12;
    char mxc;
    char mic;
    int v=0;
    // vector<pair<>> vals;
    forn(i,n){
        freq[s[i]]++;
        // if(freq[s[i]]==1){v++;

        // }
        // if(freq[s[i]]>mx  || (mic==mxc && s[i]!=mic)){
        //     mx=freq[s[i]];
        //     mxc=s[i];
        // } 
        // if(freq[s[i]]<mi || (mic==mxc && s[i]!=mxc)){
        //     mi=freq[s[i]];
        //     mic=s[i];
        // }
    }
    
    for(auto it=freq.begin();it!=freq.end();it++){
        if(it->second>mx){
            mxc=it->first;
            mx=it->second;
        }
    }
    for(auto it=freq.begin();it!=freq.end();it++){
        if(it->second<mi && it->ff!=mxc){
            mic=it->first;
            mi=it->second;
        }
    }
    int c=0;
    // if(mic==m)
    // dbgv()
    // dbgv(mxc);
    // dbgv(mic);
    for(int i=0;i<n;i++){
        if(s[i]==mic){
            s[i]=mxc;
            break;
        }
    }

    cout<<s<<endl;
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
