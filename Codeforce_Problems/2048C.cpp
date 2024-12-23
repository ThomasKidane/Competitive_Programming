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


//s3 is the xored one
bool bigger(string s1,string &s2,string &s3){
    for(int i=0;i<s1.size();i++){
        if(s3[i]=='0'){
            if(s1[i]==s2[i]){
                continue;
            } else {
                if(s1[i]>s2[i]){
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            if(s1[i]<s2[i]){
                return true;
            } else {
                return false;
            }
        }
    }

    return false;
}

void solve(){
    string s;
    cin>>s;
    int f,fz=1;
    bool sett=false;
    f=1;
    for(int i=1;i<s.length();i++){
        if(s[i]=='0'){
            fz=s.size()-i;
            sett=true;    
            break;
        }
    }
    string starter=s.substr(0,fz);
    int l=1;
    string comp=s.substr(s.size()-fz,fz);
    for(int i=0;i<s.size()-fz;i++){
        if(bigger(s.substr(i,fz),starter,comp)){
            starter=s.substr(i,fz);
            l=i+1;
        }
    }
    if(!sett){
        cout<<1<<' '<<s.size()<<' '<<1<<' '<<1<<endl;
    } else {
        cout<<1<<' '<<s.size()<<' '<<l<<' '<<l+fz-1<<endl; 
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
