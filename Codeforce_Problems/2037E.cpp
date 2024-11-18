#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
// #define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

///idfhiheifekkl

void askhandle(int l,int r,string& s,int n,int q){
    cout<<"? "<<l<<" "<<r<<endl;
    int v;
    cin>>v;
    bool nddd;
    if(v<r-l){
        s+="0";
        nddd=true;
    } else {
        s+="1";
        nddd=false;
    }
    if(r==n || q+1==n){
        return;
    } else {
        if(!nddd){
            askhandle(l,r+1,s,n,q+1);
        } else {
            askhandle(r,r+1,s,n,q+1);
        }
    }
}

long long count01Subsequences(string& binary) {
    long long count = 0;
    long long zeros = 0;  // Keep track of number of zeros seen so far
    
    for(char c : binary) {
        if(c == '0') {
            zeros++;
        } else if(c == '1') {
            // For each '1', add the number of zeros seen before it
            count += zeros;
        }
    }
    return count;
}

void solve(){
    int n;
    cin>>n;
    cout<<"? "<<1<<" "<<n<<endl;
    int v;
    int o;
    cin>>v;
    o=v;
    string s;
    if(!v){
        cout<<"! IMPOSSIBLE"<<endl;
        return;
    } else {
        if(n==2){
            cout<<"! 01"<<endl;
            return;
        } else {
            if(n==3){
                cout<<"? "<<1<<" "<<2<<endl;
                cin>>v;
                if(v){
                    s="01";
                    askhandle(1,3,s,n,2);
                } else {
                    s="0";
                    askhandle(2,3,s,n,2);                
                }

                if(s.size()==n){
                    cout<<"! "<<s<<endl;
                    return;
                } else {
                    string t="0"+s;
                    if(o==count01Subsequences(t)){
                        s="0"+s;
                    } else {
                        s="1"+s;
                    }

                    cout<<"! "<<s<<endl;
                    return;
                }
            } else {
                int l=2;
                int c=o;
                while(c>0 && l<n){
                    cout<<"? "<<l<<" "<<n<<endl;
                    int p;
                    cin>>p;
                    if(p==0){
                        s+="01";
                        break;
                    }
                    if(p<c){
                        s+="0";
                    } else if(p==c){
                        s+="1";
                    }
                    c=p;
                    l++;
                }
                // dbgv(l);
                // dbgv(s);
                if(s.size()<n){
                    askhandle(l-1,l+1,s,n,0);
                }
                
                
                cout<<"! "<<s<<endl;
            }
            
            
            
        }
    }
    

    

    
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
