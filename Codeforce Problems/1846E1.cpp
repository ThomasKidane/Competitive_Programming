#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int n){
    int s=2ll;
    int x=max(3ll,(int)(log10(n*(s-1)+1)/log10(s)));
    while(((int)pow(s,3ll)-1ll)/(s-1ll)<=n){
            x=max(3ll,(int)(log10(n*(s-1)+1)/log10(s)));
            if(((int)pow(s,x)-1)/(s-1)==n || ((int)pow(s,x+1ll)-1)/(s-1)==n) {cout<<"YES"<<endl;return;}
            else{
                s++;
            }
        }
        cout<<"NO"<<endl;
}

signed main(){
    int t=0,n;cin>>t;
    while(t--){
        cin>>n;
        solve(n);

    }

}

