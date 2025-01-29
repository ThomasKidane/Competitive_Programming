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

int execute(int v[],int a,int b,int c,int d,int n){
    forn(i,n){
        if(v[i]>0){
            int val=min(v[i],min(c,b-d));
            d+=val;
            c-=val;
        } else {
            int val=min(-v[i],min(d,a-c));
            d-=val;
            c+=val;
        }
    }

    return c;
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int v[n];
    forn(i,n){
        cin>>v[i];
    }
    int res[a+1][b+1];
    memset(res,0,sizeof(res));
    // dbgv(execute(v,a,b,4,4,3));
    forn(i,a+b+1){
        // first to first
        int l=0;
        int r=0;
        if(1){
            int c=max(0,i-b);
            int d=i-c;
            // dbgv(c);
            // dbgv(d);
            
            res[c][d]=execute(v,a,b,c,d,n);
            // cout<<"here"<<endl;
            int j=0;
            for(int step=i/2;step;step/=2){
                if(j+step>d || j+step+c>a)continue;
                while(execute(v,a,b,c+j+step,d-j-step,n)==res[c][d]){
                    j+=step;
                    if(j+step>d || j+step+c>a){break;}
                }
            }
            forn(k,j){
                res[c+k+1][d-k-1]=res[c][d];
            }//includsive
            l=j;
        }
        if(1){
            int d=max(0,i-a);
            int c=i-d;
            
            res[c][d]=execute(v,a,b,c,d,n);
            int j=0;
            for(int step=i/2;step;step/=2){
                if(j+step>a || j+step+d>b)continue;
                while(execute(v,a,b,c-j-step,d+j+step,n)==res[c][d]){
                    j+=step;
                    if(j+step>a || j+step+d>b){break;}
                }
            }//inclusive
            forn(k,j){
                res[c-k-1][d+k+1]=res[c][d];
            }
            r=j;
        }
        int c1=max(0,i-b);
        int c2=i-max(0,i-a);
        int d=i-c1;
        // dbgv(l);
        // dbgv(r);
        for(int k=c1+l+1;k<c2-r;k++){
            // cout<<"Hera"<<endl;
            // dbgv(i);
            res[k][d-k+c1]=res[c1][d]+k-c1-l;
        }

    }

    forn(i,a+1){
        forn(j,b+1){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
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
