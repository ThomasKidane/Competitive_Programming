#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
//#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
void solve(){
    unsigned int n;
    cin>>n;
    bool right=true;
    string s="";
    int c=0;
    while(c<2*n){
        if(right){
            int v;
            cout<<"? "<<s+"0"<<endl;
            cin>>v;
            if(v){
                s+='0';
                c++;
                if(s.size()==n){
                    break;
                } else {
                    continue;
                }
            } else {
                cout<<"? "<<s+"1"<<endl;
                cin>>v;
                c++;
                if(!v){
                    right=false;
                } else {
                    s=s+"1";
                    if(s.size()==n){
                    break;
                    } else {
                        continue;
                    }
                }
            }
        } else {
            int v;
            cout<<"? "<<"0"+s<<endl;
            cin>>v;
            if(v){
                s="0"+s;
                c++;
                if(s.size()==n){
                    break;
                } else {
                    continue;
                }
            } else {
                // cout<<s<<endl;
                // cin>>"1";
                s="1"+s;
                if(s.size()==n){
                    break;
                } else {
                    continue;
                }
            }
        }
    }
    cout<<"! "<<s<<endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
