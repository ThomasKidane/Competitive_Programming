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

vector<pair<int,int>> printDivisors(int n)
{
    vector<pair<int,int>> res;
    // Note that this loop runs till square root
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal, print only one
            // if (n / i == i)
            res.push_back(make_pair(i,n/i));
            // res.push_back(make_pair(i,n/i));
                // {res.push_back(i);}
                // return res;}}
            // else {
            //     res.push_back(i);
            //     res.push_back(n/i);
            //     // return res;
            // }
        }
    }
    // sort(res.begin(),res.end());
    // reverse(res.begin(),res.end());
    return res;
}

void solve(vector<bool> &is_prime){
    int n;
    cin>>n;
    int c=0;
    vector<int> a(n);
    int lp;
    int mv=500000;
    forn(i,n){
        int d;
        cin>>d;
        if(is_prime[d]){c++;lp=d;}
        a[i]=d;
        mv=min(d,mv);
    }
    if(c>1){
        cout<<-1<<endl;
        // cout<<"Life"<<endl;
        // dbgv(c);
    } else if(c==1){
        if(lp>mv){
            cout<<-1<<endl;
        } else {
            if(n==1){
                cout<<a[0]<<endl;
                return ;
            }
            sort(a.begin(),a.end());
            bool can=true;
            for(int i=1;i<n;i++){
                bool did=false;
                vector<pair<int,int>> tb=printDivisors(a[i]);
                for(int j=0;j<tb.size();j++){
                    // dbgv(a[i]-min(tb[j].ff,tb[j].ss));
                    if(a[i]-min(tb[j].ff,tb[j].ss)>=2*lp || a[i]%lp==0){
                        did=true;
                        // cout<<"None";
                        break;
                    }
                }
                if(!did){
                    can=false;
                    break;
                }
                // if(4*printDivisors(a[i])[0]<lp+2 && a[i]<4*lp){
                //     can=false;
                //     // dbgv(a[i]);
                //     dbgv(3*printDivisors(a[i])[0]);
                //     // dbgv()
                // }
            }

            if(can){
                cout<<lp<<endl;
            } else {
                cout<<-1<<endl;
                // cout<<"Her"<<endl;
            }
        }
    } else {
        cout<<2<<endl;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int n=1000000;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    // map<int,map<int,int>>aval;// Atmost one thousand entries which in total contain a million entries
    // map<int,int> vals;
    // // map<int,int> checked;
    // for(int i=2;i<2000;i++){
        
    //     // checked.clear();
    //     if(is_prime[i]){
    //         vals.clear();
    //         for(int j=2*i;j<=4*i;j++){
    //             if(j%i==0){
    //                 vals[j]=1;
    //             }
    //             if(vals[j]==1){
    //                 vector toW=printDivisors(j);
    //                 dbga(toW,toW.size());
    //                 for(int k=0;k<toW.size();k++){
    //                     for(int v=j;v<=4*i;v+=toW[k]){
    //                         vals[v]=1;
    //                     }
    //                 }    
    //             }
                
    //         }
    //         aval[i]=vals;
    //     }
    // }


    int T = 1;
    cin >> T;
    while(T--){
        solve(is_prime);
    }
    return 0;
}
