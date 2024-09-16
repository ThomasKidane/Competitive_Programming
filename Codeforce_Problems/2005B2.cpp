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
    int n,m,q,d;
    cin>>n>>m>>q;
    vector<int> teachers;
    bool fake1=false;
    bool faken=false;
    forn(i,m){
        cin>>d;
        teachers.push_back(d);
        if(d==1)fake1=true;
        if(d==n)faken=true;
    }
    sort(teachers.begin(),teachers.end());
    forn(i,q){
        int p;
        cin>>p;
        int j=lower_bound(teachers.begin(),teachers.end(),p)-teachers.begin();
        if(j==0){
            cout<<teachers[j]-1<<endl;
        }
        else if(p==1){
            int k=upper_bound(teachers.begin(),teachers.end(),p)-teachers.begin();
            cout<<(teachers[0]-1)<<endl;
        }
        else if(p==n){
            cout<<(n-teachers[teachers.size()-1])<<endl;
        }
        else if(j==m){
            cout<<n-teachers[teachers.size()-1]<<endl
        }

        
        else if(teachers[j]>p && teachers[j-1]!=1){
            cout<<(teachers[j]-teachers[j-1])/2<<endl;
        } else if(teachers[j]>p && teachers[j-1]==1 && fake1==false){
            cout<<(teachers[j]-teachers[j-1])<<endl;
        } else if(teachers[j]>p && teachers[j-1]==1 && fake1==true){
            cout<<(teachers[j]-teachers[j-1])/2<<endl;
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
