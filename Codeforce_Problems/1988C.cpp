#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a

string toBinary(int n)
{
    string r;
    while(n!=0ll) {r=(n%2==0ll ?"0":"1")+r; n/=2ll;}
    return r;
}

int toNum(string s){
    int cur=0ll;
    int c=0ll;
    for(int i=s.length()-1ll;i>=0ll;i--){
        if(s[i]=='1'){
            c+=(int)pow(2ll,cur);
        }
        cur++;
    }
    return c;
}

signed main(){
    int t,n1;cin>>t;
    while(t--){
        cin>>n1;
        //n1=t+1;
        int c=0ll,n=n1;
        while(n!=0ll){
          n = n&(n-1ll);
          c++;
        }
        if(c==1ll){
            cout<<1<<endl<<n1<<endl;
        } else{
            cout<<c+1ll<<endl;
            string toW=toBinary(n1);
            int Os=1;
            for(int i=1;i<=c;i++){
                Os=1;
                string res="";
                for(int j=0;j<toW.length();j++){
                    if(toW[j]=='1' && Os==i){
                        res+="0";
                    } else {
                        res+=toW[j];
                    }
                    if(toW[j]=='1')Os++;
                }
                //cout<<res<<endl;
                cout<<toNum(res)<<" ";
            }
            //cout<<toW<<" ";
            cout<<n1<<endl;
        }

    }

}

