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
    int n,s;
    cin>>n>>s;
    s--;
    int c=0;
    deque<int> vals;
    forn(i,n){
        int d;
        cin>>d;
        if(i==s){
            if(d!=0){
                c++;
            }   
            vals.push_back(0);
        } else {
            vals.push_back(d);
        }
    }
    sort(vals.begin(),vals.end());
    vals.pop_front();
    int cc=0;
    while(!vals.empty() && vals.front()==0){
        cc++;
        vals.pop_front();
    }
    c+=cc;
    // dbgv(cc);
    // dbgv(vals.size());
    int p=0;
    while(!vals.empty()){
        if(abs(vals.front()-p)>1){
            // cout<<"here"<<endl;
            
                if(cc>=abs(vals.front()-p)-1){
                    cc-=abs(vals.front()-p)-1;
                    p=vals.front();
                    vals.pop_front();
                } else {
                    c+=min((int)vals.size(),abs(vals.front()-p)-1-cc);
                    int vv=min((int)vals.size(),abs(vals.front()-p)-1-cc);
                    forn(i,vv){
                        vals.pop_back();
                    }
                    if(!vals.empty()){
                        p=vals.front();
                        vals.pop_front();
                    }  
                    cc-=cc;
                }
                
            
            
            
            
            
            
            
            
        } else {
            p=vals.front();
            vals.pop_front();

        }
    }

    cout<<c<<endl;
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
