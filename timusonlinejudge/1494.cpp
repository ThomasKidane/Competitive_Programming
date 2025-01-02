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
    vector<int> stack;
    int l=0;
    for(int i=n;i>=1;i--){
        int d;
        cin>>d;
        if(stack.empty()){
            for(int i=l+1;i<=d;i++){
                stack.push_back(i);
            }
            stack.pop_back();
            l=d;
        } else {
            if(d<stack.back()){
                cout<<"Cheater";
                return;
            } else {
                if(d==stack.back()){
                    stack.pop_back();
                } else {
                    for(int i=l+1;i<d;i++){
                        stack.push_back(i);
                    }
                    l=d;
                }
            }
        }

    }
    cout<<"Not a proof"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
