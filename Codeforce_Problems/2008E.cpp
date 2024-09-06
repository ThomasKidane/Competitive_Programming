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

ll getMin(vector<int> a1,vector<int> b1,vector<int> a2,vector<int> b2){
    
    forn(i,26){a1[i]+=b1[i];a2[i]+=b2[i];}
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    int o=0;
    forn(i,25){
        o+=a1[i]+a2[i];
    }
    return o;
}

vector<int> combineP(vector<int> a,vector<int> b){
    forn(i,26)a[i]-=b[i];
    return a;
}


void solve(){
    int n;
    string s;
    cin>>n>>s;
    if(n%2==0){
        ll a[26],b[26];
        forn(i,26) {a[i]=0;b[i]=0;}
        forn(i,n){
            if(i%2==0){
                a[ll(s[i])-ll('a')]+=1;
            } else {
                b[ll(s[i])-ll('a')]+=1;
            }
        }
        ll o=0;
        sort(a,a+26);
        sort(b,b+26);
        forn(i,25){
            o+=(a[i]+b[i]);
        }
        cout<<o<<endl;
    } else {
        
        vector<vector<int>> apre(n+2,vector<int> (26,0));
        vector<vector<int>> bpre(n+2,vector<int> (26,0));
        vector<int> nullV(26,0);
        
        for(int i=0;i<n;i++){
            
            if(i%2==0){                
                apre[i+1]=apre[i];
                
                apre[i+1][int(s[i])-int('a')]+=1;
            } else {
                apre[i+1]=apre[i];
            }
        }
        
        for(int i=0;i<n;i++){
            if(i%2==1){                
                bpre[i+1]=bpre[i];
                bpre[i+1][int(s[i])-int('a')]+=1;
            } else {
                bpre[i+1]=bpre[i];
            }
        }
        ll dp[n];
        ll steps=1000000000;
        forn(i,n+2){
            forn(j,26) {
                //cout<<apre[i][j]<<' ';
            } 
            //cout<<endl;
            
        }
        //cout<<endl;
        forn(i,n+2){
            forn(j,26) {
                //cout<<bpre[i][j]<<' ';
            } 
            //cout<<endl;
        }
        forn(i,n){
            dp[i]=getMin(apre[i],combineP(bpre[n],bpre[i+1]),bpre[i],combineP(apre[n],apre[i+1]));  
            steps=min(steps,dp[i]);
        }
        cout<<steps+1<<endl;
    }
}

signed main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
