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
    int a[n];
    forn(i,n){
        cin>>a[i];
    }
    vector<int> mi;
    vector<int> mx;
    int s=a[0];
    // mi.push/_back(s);
    // mx.push_back(s);
    for(int i=1;i<n;i++){
        // cout<<"Her"<<endl;
        // if(mi.size()){dbga(mi,mi.size());}/
        // if(mx.size()){dbga(mx,mx.size());}
        if(a[i]==s)continue;
        if(s<a[i]){
            
            if(mx.size()>0){
                if(a[i]>mx.back()){
                    cout<<"NO"<<endl;
                    return;
                } else {
                    if(a[i]==mx.back()){
                        mi.push_back(s);
                        s=a[i];
                        mx.pop_back();
                    } else {
                        mi.push_back(s);
                        s=a[i];
                        // mx.pop_back();
                    }
                }
            } else {
                mi.push_back(s);
                s=a[i];
            }
        } else {
            if(mi.size()>0){
                if(a[i]<mi.back()){
                    cout<<"NO"<<endl;
                    return;
                } else {
                    if(a[i]==mi.back()){
                        mx.push_back(s);
                        s=a[i];
                        mi.pop_back();
                    } else {
                        mx.push_back(s);
                        s=a[i];
                        // mx.pop_back();
                    }
                }
            } else {
                mx.push_back(s);
                s=a[i];
            }
        }
    }  

    cout<<"YES"<<endl;
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
