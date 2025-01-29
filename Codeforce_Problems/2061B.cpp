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
    vector<ll> a;
    map<ll,int> vals;
    ll reps=0;
    bool done=false;
    forn(i,n){
        ll d;
        cin>>d;
        a.push_back(d);
        vals[a[i]]+=1;
        if(vals[a[i]]>=2){
            if(!done){
                reps=a[i];
                done=true;
            } else {
                if(a[i]>reps){
                    reps=a[i];
                }
            }
        }
    }
    // dbgv(done);
    if(done){
        sort(a.begin(),a.end());
        // auto last = std::unique(a.begin(), a.end());
        // a.erase(last, a.end());

        ll v1,v2;
        bool v1done=false;
        bool v2done=false;
        forn(i,a.size()){
            // dbgv(v1done);
            // dbgv(v2done);
            if(!v1done && ((a[i]==reps && vals[a[i]]>2) || (vals[a[i]]>0 && a[i]!=reps))) {
                if(v2done){
                    if(min(v1,v2)+2*reps>max(v1,v2)){
                    break;
                } else {
                    v1done=false;
                    v1=max(v1,v2);
                    v2=min(v1,v2);
                                //    dbgv(v2);/
                                //    cout<<"here"<<endl;
                }
                }
                v1done=true;
                v1=a[i];
                vals[a[i]]-=1;
                if(v2done){
                    if(min(v1,v2)+2*reps>max(v1,v2)){
                    break;
                } else {
                    // v1done=false;
                    v1=max(v1,v2);
                    v2=min(v1,v2);
                                //    dbgv(v2);/
                                //    cout<<"here"<<endl;
                }
                }
            }
            // dbgv(v1done);
            if(v1done && ((a[i]==reps && vals[a[i]]>2) || (vals[a[i]]>0) && a[i]!=reps)){
                if(v2done){
                    if(min(v1,v2)+2*reps>max(v1,v2)){
                    break;
                } else {
                    v1done=false;
                    v1=max(v1,v2);
                    v2=min(v1,v2);
                                //    dbgv(v2);/
                                //    cout<<"here"<<endl;
                }
                }
                 
                v2done=true;
                v2=a[i];
                vals[a[i]]-=1;
                if(min(v1,v2)+2*reps>max(v1,v2)){
                    break;
                } else {
                    v1done=false;
                    v1=min(v1,v2);
                    v2=max(v1,v2);
                                //    dbgv(v2);?
                                //    cout<<"here"<<endl;
 }
                
            } 
            // dbgv(i);
            
        }
        // dbgv(v1);
        // dbgv(v2);
        // dbgv(v1done);
        if(!v2done){
            cout<<-1<<endl;
        } else {
            if(min(v1,v2)+2*reps>max(v1,v2)){
                cout<<v1<<' '<<reps<<' '<<reps<<' '<<v2<<endl;
            } else {
                cout<<-1<<endl;
            }
        }
    } else {
        cout<<-1<<endl;
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
