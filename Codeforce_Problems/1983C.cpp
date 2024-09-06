#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

const int MAXN=2e5+20;
int pa[MAXN]={0};
int pb[MAXN]={0};
int pc[MAXN]={0};

signed main(){
    int t,n,d,a,b;cin>>t;
    while(t--){
        cin>>n;
        forn(i,n) {
            cin>>d;
            pa[i+1]=pa[i]+d;
        }
        forn(i,n) {
            cin>>d;
            pb[i+1]=pb[i]+d;
        }
        forn(i,n) {
            cin>>d;
            pc[i+1]=pc[i]+d;
        }
        a=1,b=1;
        bool done=false;
        /*dbga(pa,n+1);
        dbga(pb,n+1);
        dbga(pc,n+1);*/
        for(a;a<n-1;a++){
            if(done) break;
            for(b=a;b<n-1;b++){
                /*dbgv(a);
                dbgv(b);*/
                if(pa[a]>=ceil((double)pa[n]/3) && pb[b+1]-pb[a]>=ceil((double)pa[n]/3)&&pc[n]-pc[b+1]>=ceil((double)pa[n]/3)){
                    cout<<1<<" "<<a<<" "<<a+1<<" "<<b+1<<" "<<b+2<<" "<<n<<endl;
                    done=true;
                    break;
                } else if(pa[a]>=ceil((double)pa[n]/3) && pc[b+1]-pc[a]>=ceil((double)pa[n]/3)&&pb[n]-pb[b+1]>=ceil((double)pa[n]/3)){
                    cout<<1<<" "<<a<<" "<<b+2<<" "<<n<<" "<<a+1<<" "<<b+1<<endl;
                    done=true;
                    break;
                } else if(pb[a]>=ceil((double)pb[n]/3) && pa[b+1]-pa[a]>=ceil((double)pa[n]/3)&&pc[n]-pc[b+1]>=ceil((double)pa[n]/3)){
                    cout<<a+1<<" "<<b+1<<" "<<1<<" "<<a<<" "<<b+2<<" "<<n<<endl;
                    done=true;
                    break;
                } else if(pb[a]>=ceil((double)pb[n]/3) && pc[b+1]-pc[a]>=ceil((double)pa[n]/3)&&pa[n]-pa[b+1]>=ceil((double)pa[n]/3)){
                    cout<<b+2<<" "<<n<<" "<<1<<" "<<a<<" "<<a+1<<" "<<b+1<<endl;
                    done=true;
                    break;
                } else if(pc[a]>=ceil((double)pb[n]/3) && pb[b+1]-pb[a]>=ceil((double)pa[n]/3)&&pa[n]-pa[b+1]>=ceil((double)pa[n]/3)){
                    cout<<b+2<<" "<<n<<" "<<a+1<<" "<<b+1<<" "<<1<<" "<<a<<endl;
                    done=true;
                    break;
                } else if(pc[a]>=ceil((double)pb[n]/3) && pa[b+1]-pa[a]>=ceil((double)pa[n]/3)&&pb[n]-pb[b+1]>=ceil((double)pa[n]/3)){
                    cout<<a+1<<" "<<b+1<<" "<<b+2<<" "<<n<<" "<<1<<" "<<a<<endl;
                    done=true;
                    break;
                } else {continue;}
            }
        }
        if(done) continue;
        else cout<<-1<<'\n';
    }


}



