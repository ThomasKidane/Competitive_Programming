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

bool comp(double x,double y){
    int d1=x*100;
    int d2=y*100;
    return (d1%10)<(d2%10);
}

void solve(){
    int n;
    cin>>n;
    double res=0;
    // vector<double> rv;
    vector<double> end8;
    vector<double> end9;
    forn(i,n){
        ld x;
        cin>>x;
        int d=(100*(x+0.0001));
        // dbgv(x);
        // dbgv(d%5);
        if(d%5==0){
            res+=x;
        } else if(d%5<=2){
            res+=(double)(d-d%5)/100;
        } else {
            if(d%5==3)end8.push_back(x);
            else end9.push_back(x);
            // rv.push_back(x);
        }
    }
    // dbgv(end8.size());
    // cout<<res<<endl;

    // sort(rv.begin(),rv.end(),comp);
    while(end8.size()>=1 && end9.size()>=1){
            double x;
            double y;
            x=end8.back();
            end8.pop_back();
            y=end9.back();
            end9.pop_back();
            // dbgv(end9.size());
            double z=x+y;
            // if((int)((z+0.0001)*100)%5<=2){
                int d=(z+0.0001)*100;
                res+=(double)(d-d%5)/100;                
            // } else {
            //     rv.push_back(z);
            // }

        }
        // dbgv(end9.size());
        if(end9.size()>=2){
            while(end9.size()>=2){
                double x;
                double y;
                x=end9.back();
                end9.pop_back();
                y=end9.back();
                end9.pop_back();
                double z=x+y;
                // if((int)((z+0.0001)*100)%5<=2){
                    // int d=(z+0.0001)*100;
                    // res+=(double)(d-d%5)/100;                
                // } else {
                    end8.push_back(z);
                // }
                while(end8.size()>=1 && end9.size()>=1){
                    double x;
                    double y;
                    x=end8.back();
                    end8.pop_back();
                    y=end9.back();
                    end9.pop_back();
                    double z=x+y;
                    // if((int)((z+0.0001)*100)%5<=2){
                        int d=(z+0.0001)*100;
                        res+=(double)(d-d%5)/100;                
                    // } else {
                    //     rv.push_back(z);
                    // }

                }

            }
        }
        if(end8.size()>=2){
            while(end8.size()>=2){
                double x;
                double y;
                x=end8.back();
                end8.pop_back();
                if(end9.size()>0){
                    y=end9.back();
                    end9.pop_back();

                } else {
                    y=end8.back();
                    end8.pop_back();
                }
                
                double z=x+y;
                // if((int)((z+0.0001)*100)%5<=2){
                    int d=(z+0.0001)*100;
                    res+=(double)(d-d%5)/100;                
                // } else {
                    // end8.push_back(z);
                // }
                while(end8.size()>=1 && end9.size()>=1){
                    double x;
                    double y;
                    x=end8.back();
                    end8.pop_back();
                    y=end9.back();
                    end9.pop_back();
                    double z=x+y;
                    // if((int)((z+0.0001)*100)%5<=2){
                        int d=(z+0.0001)*100;
                        res+=(double)(d-d%5)/100;                
                    // } else {
                    //     rv.push_back(z);
                    // }

                }

            }
        }
        if(!end8.empty()){
            res+=end8[0];
        }
        if(!end9.empty()){
            res+=end9[0];
        }

        cout<<fixed<<setprecision(2)<<res;
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
