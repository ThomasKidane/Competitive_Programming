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

const int MAXN=1e6+1000;
int precal[MAXN];

bool same(int n,int p){
    // dbgv((n%(int)(pow(10,p-2))));
    // dbgv((n%(int)(pow(10,p)))/((int)pow(10,max(0,p-1))));
    if((n%(int)(pow(10,p)))/((int)pow(10,max(0,p-1)))!=4){
        // cout<<"Here"<<endl;
        return false;
    } else {
        
        for(int i=p-1;i>=0;i--){
            if(n%(int)(pow(10,i))/((int)pow(10,max(0,i-1)))>=5){
                // cout<<"Here"<<endl;
                // dbgv(n);
                // dbgv(p);
                return true;
            } else if((n%(int)(pow(10,i)))/((int)pow(10,max(0,i-1)))<=3){
                return false;
            }
        }
        return false;
    }
}

int a(int n){
    int p=(int)ceil(log10(n));
    int s=0;
    int v=5;
    // dbgv(p);
    if(n<=10){
        return 0;
    }
    if((n%(int)(pow(10,p)))/((int)pow(10,max(0,p-1)))!=4){
        // cout<<"Here"<<endl;
        for(int i=0;i<((int)pow(10,p)/2<=n? p-1:p-2);i++){
            s+=v;
            v*=10;
            v+=5;
        }
    } else {
        for(int i=0;i<p-2;i++){
            s+=v;
            v*=10;
            v+=5;
        }
        // cout<<"Here"<<endl;
        // dbgv(v);
        s+=max(0,n-(int)pow(10,p)/2+v+1);
    }
    // cout<<s<<endl;
    // return (5/81)*(pow(10,(p)) - 9*p - 10);   
    return s;
}

void solve(){
    int n;
    cin>>n;
    // for(int i=0;i<20;i++){
    //     cout<<precal[i][1]<<' ';
    // }
    // cout<<endl;
    // for(int i=0;i<n+1;i++){
    //     cout<<precal[i][4]<<' ';
    // }
    // cout<<endl;
    // dbgv(same(4450,4));
    // dbgv(n);
    // dbgv((int)ceil(log10(n))+1);
    // dbgv(same(445,3));
    // dbgv(precal[5][1]);
    // dbgv(same(5,1));
    // cout<<a(n)<<endl;
    cout<<a(n)<<endl;
    // cout<<precal[n]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
    // for(int i=0;i<7;i++){
        precal[0]=0;
        precal[1]=0;
        precal[2]=0;
    // }
    // for(int i=2;i<MAXN;i++){
    //     // for(int j=0;j<7;j++){
    //         precal[i]=(same(i,(int)ceil(log10(i)))?1:0)+precal[i-1];
    //         if(precal[i]!=a(i)){
    //             cout<<"Dont match break"<<endl;
    //             dbgv(i);
    //             dbgv(a(i));
    //             break;
    //         }
    //     // }
    // }

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
