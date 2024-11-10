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
    unsigned long long a[n];
    forn(i,n){
        cin>>a[i];        
    }
    if(n==1){
        cout<<1<<endl;
    }
    else if(n==2){
        cout<<(a[1]-a[0])<<endl;
    }
 else {
    if(n%2==0){
        vector<unsigned long long> b;
        // b.clear();
        forn(i,n){
            // if(u!=i){
            b.push_back(a[i]);
            // }
        }
        vector<unsigned ll> difA(1);
        // sort(b.begin(),b.end());
        difA[0]=b[1]-b[0];
        // dbgv(difA[0]);
        // dbga(b,b.size());
        for(int i=1;i<n-2;i+=2){
            // dbgv(i+2);
            difA.push_back(b[i+2]-b[i+1]);
        }
        sort(difA.begin(),difA.end());
        // difA.pop_back();
        // if(difA.back()<m)m=difA.back();
        // unsigned long long d= difA.back();
        // d++;
        // d/=2;
        // difA.pop_back();
        // difA.push_back(d);
        sort(difA.begin(),difA.end());
        // dbga(difA,2);
        cout<<difA.back()<<endl;
        
    } else {
        unsigned long long m=(unsigned long long)1e18+50ll;
        int beS=0;
        vector<unsigned long long> b;
        for(int u=0;u<n;u+=2){
            b.clear();
            forn(i,n){
                if(u!=i){
                    b.push_back(a[i]);
                }
            }
            vector<unsigned ll> difA(1);
            // sort(b.begin(),b.end());
            difA[0]=b[1]-b[0];
            for(int i=1;i<n-2;i+=2){
                difA.push_back(b[i+2]-b[i+1]);
            }
            sort(difA.begin(),difA.end());
            // difA.pop_back();
            if(difA.back()<m)m=difA.back();
            // cout<<difA.back()<<endl;
        }    
        cout<<m<<endl;   
    }
    


    
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
