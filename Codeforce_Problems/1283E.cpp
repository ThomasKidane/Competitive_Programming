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
    map<int,int> c;
    forn(i,n){
        int d;
        cin>>d;
        c[d]++;
    }

    set<int> mis;
    set<int> mxs;
    for(auto it=c.begin();it!=c.end();it++){
        for(int i=0;i<min(it->ss,3);i++){
            if(mxs.find(it->ff-1)!=mxs.end()){
                if(mxs.find(it->ff)!=mxs.end()){

                    if(mxs.find(it->ff+1)!=mxs.end()){
                        
                        continue;
                    } else{
                               mxs.insert(it->ff+1);

                    }
                } else {
                                    mxs.insert(it->ff);

                }
            } else {
            mxs.insert(it->ff-1);

            }
        }
    }
    for(auto it=c.begin();it!=c.end();it++){
        // for(int i=0;i<min(it->ss,3);i++){
            if(mis.find(it->ff-1)==mis.end()){
                if(mis.find(it->ff)==mis.end()){

                    if(mis.find(it->ff+1)==mis.end()){
                            mis.insert(it->ff+1);
                        // continue;
                    } else{
                        continue; 

                    }
                } else {
                                    // mxs.insert(it->ff);
                                    continue;

                }
            } else {
            // mxs.insert(it->ff-1);
            continue;

            }
        // }
    }

    cout<<mis.size()<<' '<<mxs.size()<<endl;
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
