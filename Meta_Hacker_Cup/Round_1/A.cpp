#include<bits/stdc++.h>
#include <fstream>
#include <iostream>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
void solve(int v){
    int n;
    cin>>n;
    if(n==1){
        ld a,b;
        cin>>a>>b;
        
        cout<<"Case #"<<v<<": "<<1/b<<endl;
    } else {
        ld f,s;
        cin>>f>>s;
        if(f==0){
            f=10000001;
        }else {
            f=(1/f); // Upper bound of speed
        }
        
        s=(1/s); // Lower bound of Speed
        ld a,b;
        for(int i=2;i<=n;i++){
            cin>>a>>b;
            
            if(a==0){
                a=10000001;
            } else {
                a=i/a;//Upper bound of speed
            }
            
            b=(i/b); // Lower bound of speed
            f=min(f,a);
            s=max(s,b);
        }
        if(s>f){
            cout<<"Case #"<<v<<": "<<-1<<endl;
        } else {
            cout<<"Case #"<<v<<": "<<s<<endl;
        }
    }
}

int main() {
    ifstream fileIn("subsonic_subway_input.txt");
    cin.rdbuf(fileIn.rdbuf());
    ofstream fileOut("A.txt");
    cout.rdbuf(fileOut.rdbuf());

    int T = 1;
    cin >> T;
    int n=T;
    while(T--){
        solve(n-T);
    }
    return 0;
}
