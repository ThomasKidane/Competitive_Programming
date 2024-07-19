#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<endl;

int isprime(int N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}

signed main(){
    int t,n;cin>>t;
    while(t--){
        cin>>n;
        if(n==1){cout<<"FastestFinger"<<endl;}
        else if(n==2){cout<<"Ashishgup"<<endl;}
        else if(n%2==1){cout<<"Ashishgup"<<endl;}
        else{
                int d=n/2;
                int step=1;
                while(d!=1 && d%2==0 && n%d==0){
                    d=d/2;
                    step+=1;
                }

                if(d==1 || (isprime(d)&&step==1)){cout<<"FastestFinger"<<endl;}
                else{cout<<"Ashishgup"<<endl;}
        }
    }
}
